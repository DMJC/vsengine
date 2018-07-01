//
//C++ Interface: vid_file
//
#ifndef __VID_FILE_H__INCLUDED__
#define __VID_FILE_H__INCLUDED__

#include <string>
#include <vsfilesystem.h>
#include <exception>

class VidFileImpl;

class VidFile
{
public:
    class Exception : public std::exception
    {
private:
        std::string _message;

public: Exception() {}
        Exception( const Exception &other ) : _message( other._message ) {}
        explicit Exception( const std::string &message ) : _message( message ) {}
        virtual ~Exception() noexcept {}
        virtual const char * what() const noexcept
        {
            return _message.c_str();
        }
    };

    class UnsupportedCodecException : public Exception
    {
public: UnsupportedCodecException() {}
        UnsupportedCodecException( const UnsupportedCodecException &other ) : Exception( other ) {}
        explicit UnsupportedCodecException( const std::string &message ) : Exception( message ) {}
    };

    class FileOpenException : public Exception
    {
public: FileOpenException() {}
        FileOpenException( const FileOpenException &other ) : Exception( other ) {}
        explicit FileOpenException( const std::string &message ) : Exception( message ) {}
    };

    class FrameDecodeException : public Exception
    {
public: FrameDecodeException() {}
        FrameDecodeException( const FrameDecodeException &other ) : Exception( other ) {}
        explicit FrameDecodeException( const std::string &message ) : Exception( message ) {}
    };

    class EndOfStreamException : public Exception
    {
public: EndOfStreamException() {}
        EndOfStreamException( const EndOfStreamException &other ) : Exception( other ) {}
        explicit EndOfStreamException( const std::string &message ) : Exception( message ) {}
    };

public: 
    VidFile() noexcept;
    ~VidFile();

    bool isOpen() const noexcept;

    void open( const std::string &path, size_t maxDimension = 65535, bool forcePOT = false ) noexcept(false);//throw (Exception);
    void close() noexcept;

/** Seeks to the specified time
 * @Returns true if frame changed, false otherwise.
 * @Throws EndOfStreamException when time lays past the end.
 * @Throws FrameDecodeException when an error occurs during frame decode.
 */
    bool seek( float time ) noexcept(false);//throw (Exception);

    float getFrameRate() const noexcept;
    float getDuration() const noexcept;
    int getWidth() const noexcept;
    int getHeight() const noexcept;
    void * getFrameBuffer() const noexcept;
    int getFrameBufferStride() const noexcept;

private:
    VidFileImpl *impl;
};

#endif //__VID_FILE_H__INCLUDED__

