//
// C++ Interface: Audio::Codec
//
#ifndef __AUDIO_STREAM_H__INCLUDED__
#define __AUDIO_STREAM_H__INCLUDED__

#include <string>
#include "Exceptions.h"
#include "Format.h"

namespace Audio {

    /**
     * Stream abstract class
     *
     * @remarks This is the interface to all kinds of streams.
     *      @par This abstract class has but a few 
     * @see Codec to create Stream instances.
     *
     */
    class Stream
    {
    private:
        std::string filePath;
        Format streamFormat;
        
        void* curBufferPos;
    
    protected:
        /**
         * No Buffer exception
         * @remarks thrown when a call to getBufferImpl() is made without a preceding call
         *       to nextBufferImpl(). Notice that this is commonplace at times, since calling
         *       nextBufferImpl() would advance the stream, and sometimes one must read the
         *       current buffer without advancing the stream, but whether or not a call was
         *       made to nextBufferImpl() may be hard to know.
         */
        class NoBufferException : public Exception {
        public:
            NoBufferException() {}
            NoBufferException(const NoBufferException &other) : Exception(other) {}
            explicit NoBufferException(const std::string &message) : Exception(message) {}
        };
        
    protected:
        /** Internal constructor used by derived classes */
        Stream(const std::string& path) throw(Exception);
        
        /** Internal write access to stream format, for derived classes */
        Format& getFormatInternal() throw() { return streamFormat; }
    
    public:
        virtual ~Stream();
        
        /** Return the path of the associated file. */
        const std::string& getPath() const throw() { return filePath; };
        
        /** Return the format of the stream. */
        const Format& getFormat() const throw() { return streamFormat; }
        
        /** 
         * Return the length of the stream.
         * @remarks This may not be an inocuous function. Some codecs can't return the length of
         *      a file without parsing it entirely, and as such it cannot be const. 
         *      So use sparingly.
         */
        double getLength() throw(Exception);
        
        /**
         * Fill the specified buffer with data from the stream, and advance.
         * @remarks If not enough data is available, but some is, instead of throwing an EndOfStream
         *      exception the function will return the amount of data actually fetched, in bytes.
         *      If no bytes at all are available, though, and EndOfStream exception will be raised.
         * @param buffer a pointer to a memory buffer where to extract data.
         * @param bufferSize the size of the memory area pointed to by buffer, and the maximum amount
         *      of data to be extracted from the stream, if available.
         */
        unsigned int read(void *buffer, unsigned int bufferSize) throw(Exception);
        
        /** Get the stream's current position, in seconds */
        double getPosition() const throw();
        
        /** 
         * Set the stream's position, in seconds
         * @remarks The final position in the stream after this operation is not guaranteed
         *      to be as requested, but an approximation given codec limitations. The only exception
         *      being seek(0), which is guaranteed to seek to the beginning of the stream.
         */
        void seek(double position) throw(Exception);
        
        // The following section contains all the virtual functions that need be implemented
        // by a concrete Stream class. All are protected, so the stream interface is independent
        // of implementations.
    protected:
        
        /** @see getLength */
        virtual double getLengthImpl() const throw(Exception) = 0;
        
        /** @see getPosition */
        virtual double getPositionImpl() const throw() = 0;
        
        /** @see seek */
        virtual void seekImpl(double position) throw(Exception) = 0;
        
        /**
         * Get the stream's current reading buffer.
         * @remarks This buffer is to remain valid until any stream advancement is made
         *      through seekImpl or nextBufferImpl, or the object gets destroyed. Repeated
         *      getBufferImpl calls will not modify the stream, though internal state may
         *      be modified in transparent ways (allowing for lazy decoding). In short,
         *      getBufferImpl is an idempotent member function.
         *      @par Asking the buffer where nextBufferImpl() has never been called would raise
         *      a NoBuffer exception.
         */
        virtual void getBufferImpl(void *&buffer, unsigned int &bufferSize) throw(Exception) = 0;
        
        /**
         * Advance the stream by reading a new buffer.
         * @remarks The data read by this member is accessible through getBufferImpl().
         *      @par After a successful call to this member, getBufferImpl will never raise
         *      a NoBuffer exception.
         * @see getBufferImpl
         */
        virtual void nextBufferImpl() throw(Exception) = 0;
    };

};

#endif//__AUDIO_STREAM_H__INCLUDED__
