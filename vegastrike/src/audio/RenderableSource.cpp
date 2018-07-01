//
// C++ Implementation: Audio::RenderableSource
//

#include "RenderableSource.h"
#include "config.h"
#include <stdio.h>

namespace Audio {

    RenderableSource::RenderableSource(Source *_source) noexcept : 
        source(_source)
    {
    }
    
    RenderableSource::~RenderableSource()
    {
        // Just in case.
        source = 0;
    }
    
    void RenderableSource::startPlaying(Timestamp start) 
        noexcept(false)
    {
        try {
            startPlayingImpl(start);
        } catch(EndOfStreamException) {
            // Silently discard EOS, results in the more transparent
            // behavior of simply notifying listeners of source
            // termination ASAP, which is also accurate.
        };
    }
    
    void RenderableSource::stopPlaying() 
        noexcept
    {
        // Cannot be playing if an exception rises, 
        // as that implies a problem with the underlying API
        try {
            if (isPlaying())
                stopPlayingImpl();
        } catch(Exception e) {}
    }
    
    bool RenderableSource::isPlaying() const 
        noexcept
    {
        try {
            return isPlayingImpl();
        } catch(Exception e) {
            // Cannot be playing if an exception rises, 
            // as that implies a problem with the underlying API
            return false;
        }
    }
    
    Timestamp RenderableSource::getPlayingTime() const 
        noexcept(false)
    {
        return getPlayingTimeImpl();
    }
    
    void RenderableSource::update(int flags, const Listener& sceneListener) 
        noexcept
    {
        try {
            updateImpl(flags, sceneListener);
        } catch(Exception e) {
            fprintf(stderr, "Ignoring exception in renderable update: %s", e.what());
        }
    }
    
    void RenderableSource::seek(Timestamp time) 
        noexcept(false)
    {
        seekImpl(time);
    }

};
