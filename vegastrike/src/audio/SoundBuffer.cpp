//
// C++ Implementation: Audio::SoundBuffer
//

#include "SoundBuffer.h"
#include "config.h"

#include <stdlib.h>
#include <memory.h>
#include <utility>

namespace Audio {

    SoundBuffer::SoundBuffer() 
        noexcept
        : buffer(0),
          byteCapacity(0),
          bytesUsed(0)
    {
    }
    
    SoundBuffer::SoundBuffer(unsigned int capacity, const Format &format) 
        noexcept(false) //throw(OutOfMemoryException)
        : buffer(0),
          byteCapacity(0),
          bytesUsed(0)
    {
        reserve(capacity, format);
    }
    
    SoundBuffer::SoundBuffer(const SoundBuffer &other)
        noexcept(false) //throw(OutOfMemoryException)
    {
        bytesUsed = byteCapacity = other.bytesUsed;
        buffer = malloc(byteCapacity);
        if (buffer == 0)
            throw OutOfMemoryException();
        memcpy(buffer, other.buffer, bytesUsed);
        format = other.format;
    }
    
    SoundBuffer& SoundBuffer::operator=(const SoundBuffer &other) 
        noexcept(false) //throw(OutOfMemoryException)
    {
        bytesUsed = byteCapacity = other.bytesUsed;
        buffer = realloc(buffer, byteCapacity);
        if (buffer == 0)
            throw OutOfMemoryException();
        memcpy(buffer, other.buffer, bytesUsed);
        format = other.format;
        
        return *this;
    }
    
    void SoundBuffer::reserve(unsigned int capacity)
        noexcept(false) //throw(OutOfMemoryException)
    {
        byteCapacity = capacity;
        bytesUsed = 0;
        
        buffer = realloc(buffer, byteCapacity);
        if (buffer == 0)
            throw OutOfMemoryException();
    }
    
    void SoundBuffer::reserve(unsigned int capacity, const Format &_format)
        noexcept(false) //throw(OutOfMemoryException)
    {
        format = _format;
        reserve(capacity * _format.frameSize());
    }
    
    void SoundBuffer::reformat(const Format &newFormat) 
        noexcept(false)
    {
        if (newFormat != format)
            throw(NotImplementedException("Format conversion"));
    }
    
    void SoundBuffer::swap(SoundBuffer &other) 
        noexcept
    {
        std::swap(buffer, other.buffer);
        std::swap(byteCapacity, other.byteCapacity);
        std::swap(bytesUsed, other.bytesUsed);
        std::swap(format, other.format);
    }

    void SoundBuffer::optimize() 
        noexcept
    {
        if (bytesUsed == 0) {
            if (buffer) {
                free(buffer);
                buffer = 0;
            }
            bytesUsed = byteCapacity = 0;
        } else {
            if (bytesUsed != byteCapacity)
                buffer = realloc(buffer, byteCapacity = bytesUsed);
        }
    }

};
