#include <config.h>
#include <sstream>

#include "vsnet_headers.h"
#include "vsnet_socket.h"
#include "vsnet_socketbase.h"
#include "vsnet_socketset.h"
#include "vsnet_pipe.h"
#include "vsnet_dloadmgr.h"


SocketSet::SocketSet( bool blockmainthread ) :
    VSThread( false )
    , _blockmain( blockmainthread )
    , _blockmain_pending( 0 )
{
#ifndef USE_NO_THREAD
    _thread_end = false;
#endif
    FD_ZERO( &_blockmain_set );
}

SocketSet::~SocketSet()
{
#ifndef USE_NO_THREAD
    _thread_mx.lock();
    _thread_end = true;
    _blockmain  = false;     //signalling would be dangerous
    _thread_wakeup.closewrite();
    _thread_cond.wait( _thread_mx );
    _thread_wakeup.closeread();
    _thread_mx.unlock();
#endif
}
void SocketSet::predestroy()
{
    _autoset.clear();
}
bool SocketSet::addDownloadManager( boost::shared_ptr< VsnetDownload::Client::Manager >mgr )
{
    if ( !_client_mgr.expired() ) return false;
    _client_mgr = mgr;
    return true;
}

bool SocketSet::addDownloadManager( boost::shared_ptr< VsnetDownload::Server::Manager >mgr )
{
    if ( !_server_mgr.expired() ) return false;
    _server_mgr = mgr;
    return true;
}

void SocketSet::set( VsnetSocketBase *s )
{
    _autoset.insert( s );
    private_wakeup();
}

void SocketSet::unset( VsnetSocketBase *s )
{
    if ( _autoset.size() )
        _autoset.erase( s );
    private_wakeup();
}

#ifdef USE_NO_THREAD
int SocketSet::wait( timeval *tv )
{
    //assert( _blockmain ); // can't call wait if we haven't ordered the feature (?)
    if (_blockmain_pending == 0) {
        int ret;
        do {
            if (tv == NULL) {
                ret = private_select( NULL );
            } else {
                timeval tvCopy( *tv );                 //select resets timeval.
                ret = private_select( &tvCopy );
            }
        } while (ret == 1);
        return ret;
    } else {
#ifdef VSNET_DEBUG
        std::ostringstream ostr;
        for (int i = 0; i < _blockmain_pending; i++)
            if ( FD_ISSET( i, &_blockmain_set ) ) ostr<<" "<<i;
        COUT<<"something pending for sockets:"
            <<ostr.str()
            <<" ("<<_blockmain_pending<<")"<<endl;
#endif
        struct timeval zerotv;
        zerotv.tv_sec  = 0;
        zerotv.tv_usec = 0;
        return private_select( &zerotv );
    }
}
#else
#error You are using threaded network mode - do you really want this?
void SocketSet::wait( timeval *tv )
{
    assert( tv == NULL );     //No timeval.
    assert( _blockmain );     //can't call wait if we haven't ordered the feature
    _blockmain_mx.lock();
    if (_blockmain_pending == 0) {
        _blockmain_cond.wait( _blockmain_mx );
    }
#ifdef VSNET_DEBUG
    else {
        std::ostringstream ostr;
        for (int i = 0; i < _blockmain_pending; i++)
            if ( FD_ISSET( i, &_blockmain_set ) ) ostr<<" "<<i;
        COUT<<"something pending for sockets:"
            <<ostr.str()
            <<" ("<<_blockmain_pending<<")"<<endl;
    }
#endif
    _blockmain_mx.unlock();
}
#endif

void SocketSet::add_pending( int fd )
{
    if (_blockmain) {
        _blockmain_mx.lock();
        FD_SET( fd, &_blockmain_set );
        if (fd >= _blockmain_pending) _blockmain_pending = fd+1;
        _blockmain_mx.unlock();
    }
}

void SocketSet::rem_pending( int fd )
{
    if (_blockmain) {
        _blockmain_mx.lock();
        FD_CLR( fd, &_blockmain_set );
        if (fd == _blockmain_pending-1) {
            while (_blockmain_pending > 0) {
                if ( FD_ISSET( _blockmain_pending-1, &_blockmain_set ) )
                    break;
                _blockmain_pending -= 1;
            }
        }
        _blockmain_mx.unlock();
    }
}

void SocketSet::private_addset( int fd, fd_set &fds, int &maxfd )
{
    FD_SET( fd, &fds );
    if (fd >= maxfd) maxfd = fd+1;
}

int SocketSet::private_select( timeval *timeout )
{
#ifdef VSNET_DEBUG
    fd_set   debug_copy_of_read_set_select;
    fd_set   debug_copy_of_write_set_select;
    FD_ZERO( &debug_copy_of_read_set_select );
    FD_ZERO( &debug_copy_of_write_set_select );
#endif

    fd_set read_set_select;
    fd_set write_set_select;
    int    max_sock_select = 0;

    FD_ZERO( &read_set_select );
    FD_ZERO( &write_set_select );
    if ( !_client_mgr.expired() ) {
        boost::shared_ptr< VsnetDownload::Client::Manager >mgr( _client_mgr.lock() );
        if ( (bool) mgr )
            mgr->lower_check_queues();
    }
    if ( !_server_mgr.expired() ) {
        boost::shared_ptr< VsnetDownload::Server::Manager >mgr( _server_mgr.lock() );
        if ( (bool) mgr )
            mgr->lower_check_queues();
    }
    //private_test_dump_request_sets( timeout );
    for (Set::iterator it = _autoset.begin(); it != _autoset.end(); it++) {
        VsnetSocketBase *b     = (*it);
        int  fd = b->get_fd();
        bool wrote_on_negative = false;
        if ( fd < 0 && b->write_on_negative() ) {
            b->lower_clean_sendbuf();
            wrote_on_negative = true;
            fd = b->get_fd();
        }
        if (fd >= 0) {
            private_addset( fd, read_set_select, max_sock_select );
            if (b->need_test_writable() && !wrote_on_negative) {
                private_addset( b->get_write_fd(),
                                write_set_select,
                                max_sock_select );
            }
            //printf("Checking for read/writability...");
            else {
//printf("Checking for readability...");
            }
        }
    }
#ifndef USE_NO_THREAD
    private_addset( _thread_wakeup.getread(),
                    read_set_select,
                    max_sock_select );
#endif

#ifdef VSNET_DEBUG
    for (int i = 0; i < max_sock_select; i++) {
        if ( FD_ISSET( i, &read_set_select ) )
            FD_SET( i, &debug_copy_of_read_set_select );
        if ( FD_ISSET( i, &write_set_select ) )
            FD_SET( i, &debug_copy_of_write_set_select );
    }
#endif

    int ret = ::select( max_sock_select,
                        &read_set_select,
                        &write_set_select,
                        0, timeout );
    if (ret == -1) {
#if defined (_WIN32) && !defined (__CYGWIN__)
        if (WSAGetLastError() != WSAEINVAL)
            COUT<<"WIN32 error : "<<WSAGetLastError()<<endl;
#else
        perror( "Select failed : " );
#endif
    } else if (ret == 0) {
//printf("Nothing to do.\n");
    } else {
        ret++;
#if defined (VSNET_DEBUG)
        private_test_dump_active_sets( max_sock_select,
                                       debug_copy_of_read_set_select,
                                       read_set_select,
                                       debug_copy_of_write_set_select,
                                       write_set_select );
#endif
        for (Set::iterator it = _autoset.begin(); it != _autoset.end(); it++) {
            VsnetSocketBase *b = (*it);
            int fd = b->get_fd();
            if (fd >= 0) {
                if ( FD_ISSET( fd, &read_set_select ) ) {
//printf("Reading.\n");
                    if ( !b->lower_selected() )
                        ret--;                          //No complete packet received yet.
                }
                if ( b->isReadyToSend( &write_set_select ) ) {
//printf("Writing.\n");
                    ret--;
                    b->lower_sendbuf();
                }
            } else {
                if ( b->isReadyToSend( &write_set_select ) ) {
//printf("reconnecting?\n");
#ifdef VSNET_DEBUG
                    COUT<<"saw activity on "<<b->get_write_fd()
                        <<" but main file descriptor is "<<b->get_fd()<<endl;
#endif
                    b->lower_clean_sendbuf();
                }
            }
        }
#ifndef USE_NO_THREAD
        if ( FD_ISSET( _thread_wakeup.getread(), &read_set_select ) ) {
            char c;
            _thread_wakeup.read( &c, 1 );
        }
#endif
    }
    if (_blockmain) {
        //whatever the reason for leaving select, if we have been asked
        //to signal the main thread on wakeup, we do it
        _blockmain_mx.lock();
        _blockmain_cond.signal();
        _blockmain_mx.unlock();
    }
    return ret;
}

void SocketSet::wakeup()
{
    private_wakeup();
}

#ifdef USE_NO_THREAD
/// unthreaded case
void SocketSet::private_wakeup()
{}

/// unthreaded case
void SocketSet::waste_time( long sec, long usec )
{
    struct timeval tv;
    tv.tv_sec  = sec;
    tv.tv_usec = usec;
    private_select( &tv );
}
#else
/// threaded case
void SocketSet::private_wakeup()
{
    char c = 'w';
    _thread_wakeup.write( &c, 1 );
}

/// threaded case
void SocketSet::waste_time( long sec, long usec )
{
    struct timeval tv;
    tv.tv_sec  = sec;
    tv.tv_usec = usec;
    select( 0, NULL, NULL, NULL, &tv );
}
#endif

void SocketSet::run()
{
#ifndef USE_NO_THREAD
    while (!_thread_end)
        private_select( NULL );
    _thread_mx.lock();
    _thread_cond.signal();
    _thread_mx.unlock();
#endif
}

#if defined (VSNET_DEBUG) || defined (__APPLE__)
void SocketSet::private_test_dump_active_sets( int maxfd,
                                               fd_set &read_before,
                                               fd_set &read_after,
                                               fd_set &write_before,
                                               fd_set &write_after )
{
#if 0
    //Causes compile errors and I'm too lazy to figure it out at the moment.
    std::ostringstream str_r;
    std::ostringstream str_w;
    str_r<<"   *** read set: ";
    str_w<<"   *** write set: ";
    for (int i = 0; i < maxfd; i++) {
        if ( FD_ISSET( i, &read_before ) ) {
            if ( FD_ISSET( i, &read_after ) )
                str_r<<i<<"(!) ";
            else
                str_r<<i<<" ";
        } else if ( FD_ISSET( i, &read_after ) ) {
            str_r<<"(?>>"<<i<<"<<?)";
        }
        if ( FD_ISSET( i, &write_before ) ) {
            if ( FD_ISSET( i, &write_after ) )
                str_w<<i<<"(!) ";
            else
                str_w<<i<<" ";
        } else if ( FD_ISSET( i, &write_after ) ) {
            str_w<<"(?>>"<<i<<"<<?)";
        }
    }
    str_r<<ends;
    str_w<<ends;

    std::ostringstream ostr_r;
    std::ostringstream ostr_w;
    ostr_r<<"   *** read fds tested: ";
    ostr_w<<"   *** write fds tested: ";
    for (Set::iterator it = _autoset.begin(); it != _autoset.end(); it++) {
        VsnetSocketBase *b = (*it);
        int fd = b->get_fd();
        if (fd >= 0)
            if ( FD_ISSET( fd, &read_after ) )
                ostr_r<<b->get_socktype()<<" ";
        fd = b->get_write_fd();
        if (fd >= 0)
            if ( FD_ISSET( fd, &write_after ) )
                ostr_w<<"+"<<b->get_socktype()<<" ";
    }
#ifndef USE_NO_THREAD
    if ( FD_ISSET( _thread_wakeup.getread(), &read_after ) )
        ostr_r<<_thread_wakeup.getread()<<"(pipe)";
#endif

    ostr_r<<ends;
    ostr_w<<ends;
    COUT<<"select saw activity:"<<endl
        <<str_r.str()<<endl
        <<str_w.str()<<endl
        <<ostr_r.str()<<endl
        <<ostr_w.str()<<endl;
#endif
}
#endif /* VSNET_DEBUG */

#if defined (VSNET_DEBUG)
void SocketSet::private_test_dump_request_sets( timeval *timeout )
{
    std::ostringstream ostr;
    ostr<<"calling select with fds=";
    for (Set::iterator it = _autoset.begin(); it != _autoset.end(); it++) {
        VsnetSocketBase *b = (*it);
        int fd = b->get_fd();
        if (fd >= 0) {
            ostr<<fd<<" ";
            if ( b->need_test_writable() )
                ostr<<"+"<<b->get_write_fd()<<" ";
        }
    }
#ifndef USE_NO_THREAD
    ostr<<_thread_wakeup.getread()<<"(w)";
#endif
    if (timeout)
        ostr<<" t="<<timeout->tv_sec<<":"<<timeout->tv_usec;
    else
        ostr<<" t=NULL (blocking)";
    ostr<<ends;
    if (!timeout || timeout->tv_sec >= 1) {
        COUT<<ostr.str()<<endl;
    } else {
        static long waitabit = 0;
        waitabit += 1;
        if (waitabit > 100) {
            COUT<<ostr.str()<<endl;
            waitabit = 0;
        }
    }
}
#endif /* VSNET_DEBUG */

std::ostream&operator<<( std::ostream &ostr, const timeval &tv )
{
    ostr<<tv.tv_sec<<":"<<tv.tv_usec;
    return ostr;
}

