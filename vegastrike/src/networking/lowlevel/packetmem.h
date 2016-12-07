#ifndef PACKETMEM_H
#define PACKETMEM_H

#include <sys/types.h>
#include <iostream>

#include "vsnet_debug.h"
#include "networking/const.h"

#include "boost/shared_array.hpp"

/***********************************************************************
 * PacketMem - declaration
 ***********************************************************************/

class PacketMem
{
    DECLARE_VALID

public:
    LOCALCONST_DECL(bool,TakeOwnership,1)
    LOCALCONST_DECL(bool,LeaveOwnership,0)

private:
    typedef boost::shared_array<char> ptr;

    ptr     _buffer;
    size_t  _len;

public:
    PacketMem( );
    PacketMem( const PacketMem& );
    PacketMem( size_t bytesize );

    /// this constructor allows only copy-in of the buffer
    PacketMem( const void* buffer, size_t size );

    /** this constructor makes it possible to copy-in the buffer, but also to
     *  acquire only a temporary reference
     */
    PacketMem( void* buffer, size_t size, bool own );

    ~PacketMem( );

    void set( void* buffer, size_t size, bool own );

    size_t      len() const;
    char*       getVarBuf( );
    const char* getConstBuf( ) const;

    /** Dump the content of this buffer onto the given ostream, identing
     *  every line by indent_depth spaces.
     */
    void dump( std::ostream& ostr, size_t indent_depth ) const;

    PacketMem& operator=( const PacketMem& );

    bool operator==( const PacketMem& orig ) const;

private:
    void release( );
    void inner_set( void* buffer, size_t size, bool own );
};

#endif

