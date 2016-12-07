#include <stdio.h>
#define JPEG_SUPPORT
#ifdef JPEG_SUPPORT   /* Always true? */
#ifndef __JPEG_MEMORY_H
#define __JPEG_MEMORY_H
#include <string.h>
/* BAD BAD!!
 * #if defined( _WIN32) && !defined( __CYGWIN__)
 * #ifndef HAVE_BOOLEAN
 * #define HAVE_BOOLEAN
 * #define FALSE 0
 * #define TRUE 1
 *  typedef unsigned char boolean;
 * #endif
 * #ifndef XMD_H
 * #define XMD_H
 *  typedef int INT32;
 * #endif
 * #endif
 */
#if defined (_WIN32) && !defined (__CYGWIN__)
#ifndef NOMINMAX
#define NOMINMAX
#endif //tells VCC not to generate min/max macros
#include <windows.h>
#endif
#include "vsfilesystem.h"
#ifdef _WIN32
#define XMD_H
#undef HAVE_BOOLEAN
#define boolean boolean1
#endif
extern "C" {
//#define XMD_H
#include <jconfig.h>
#include <jmorecfg.h>
#include <jpeglib.h>
}
/*--------------
 *  A hack to hijack JPEG's innards to write into a memory buffer
 *  ----------------
 *  /  this defines a new destination manager to store images in memory
 *  /  derived by jdatadst.c */
typedef struct
{
    struct jpeg_destination_mgr pub;     /* public fields */
    JOCTET *buffer;                                     /* start of buffer */
    int     bufsize;                                    /* buffer size */
    int     datacount;                                  /* finale data size */
} memory_destination_mgr;

typedef memory_destination_mgr*mem_dest_ptr;

/*----------------------------------------------------------------------------
 *  /  Initialize destination --- called by jpeg_start_compress before any data is actually written. */

METHODDEF( void )
init_destination( j_compress_ptr cinfo )
{
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
    dest->pub.next_output_byte = dest->buffer;
    dest->pub.free_in_buffer   = dest->bufsize;
    dest->datacount = 0;
}

/*----------------------------------------------------------------------------
 *  /  Empty the output buffer --- called whenever buffer fills up. */
METHODDEF( boolean )
empty_output_buffer( j_compress_ptr cinfo )
{
    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
    dest->pub.next_output_byte = dest->buffer;
    dest->pub.free_in_buffer   = dest->bufsize;

    return TRUE;
}

/*----------------------------------------------------------------------------
 *  /  Terminate destination --- called by jpeg_finish_compress
 *  /  after all data has been written.  Usually needs to flush buffer. */
METHODDEF( void )
term_destination( j_compress_ptr cinfo )
{
    /* expose the finale compressed image size */

    mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
    dest->datacount = dest->bufsize-dest->pub.free_in_buffer;
}

GLOBAL( void ) jpeg_memory_dest( j_compress_ptr cinfo, JOCTET*buffer, int bufsize );
int jpeg_compress( char *dst, char *src, int width, int height, int dstsize, int quality );
int jpeg_compress_to_file( char *src, char *file, int width, int height, int quality );
extern void jpeg_memory_src( j_decompress_ptr cinfo, unsigned char *ptr, size_t size );
void jpeg_decompress( unsigned char *dst, unsigned char *src, int size, int *w, int *h );
void jpeg_decompress_from_file( unsigned char *dst, char *file, int size, int *w, int *h );

#endif
#endif

