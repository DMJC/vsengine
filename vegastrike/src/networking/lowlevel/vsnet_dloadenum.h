#ifndef VSNET_DLOADENUM_H
#define VSNET_DLOADENUM_H

#include <config.h>

#include <iostream>
#include "vsfilesystem.h"
// using namespace VSFileSystem; DONT DO THIS IN HEADERS

namespace VsnetDownload
{
/*------------------------------------------------------------*
* declaration VsnetDownload::Subcommand
*------------------------------------------------------------*/

enum Subcommand
{
    ResolveRequest,
    ResolveResponse,
    DownloadRequest,
    DownloadError,
    Download,
    DownloadFirstFragment,
    DownloadFragment,
    DownloadLastFragment,
    UnexpectedSubcommand
};

std::ostream&operator<<( std::ostream &ostr, Subcommand e );

namespace Client
{
class Manager;

/*------------------------------------------------------------*
* declaration VsnetDownload::Client::State
*------------------------------------------------------------*/

enum State
{
    Idle,
    Queued,
    Resolving,
    Resolved,
    Requested,
    FragmentReceived,
    Completed
};

std::ostream&operator<<( std::ostream &ostr, State s );

std::ostream&operator<<( std::ostream &ostr, VSFileSystem::VSError e );
}; //namespace Client
}; //namespace VsnetDownload

#endif /* VSNET_DLOADENUM_H */

