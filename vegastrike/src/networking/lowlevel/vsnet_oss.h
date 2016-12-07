/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/** OSS means Operating System Shield. It is meant to hide stupid little
 *  incompatibilities that make the code ugly.
 *  When debugging is over, we should inline a lot here.
 */

#ifndef VSNET_OSS_H
#define VSNET_OSS_H

#undef INLINE_VSNET_OSS

#ifdef INLINE_VSNET_OSS
#define INLINE inline
#else
#define INLINE
#endif

struct in_addr;

namespace VsnetOSS
{
/** uses closesocket for WIN32, otherwise close
 */
INLINE int close_socket( int fd );

bool set_blocking( int fd, bool isBlock );

/** uses inet_aton if exists, otherwise inet_addr
 */
INLINE int inet_aton( const char *cp, struct in_addr *inp );

/** ensures that the error return value is -1 and nothing else
 */
INLINE int socket( int domain, int type, int protocol );

/** make recv calls easier to debug if strangeness is in calling
 *  class, otherwise no known portability issues.
 */
INLINE int recv( int fd, void *buf, unsigned int len, int flags );

INLINE void memcpy( void *dest, const void *src, int bytesize );
};

#ifdef INLINE_VSNET_OSS
#include "vsnet_oss.cpp"
#endif

#endif /* VSNET_OSS_H */

