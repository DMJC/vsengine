#ifndef _SOUNDCONTAINER_H_
#define _SOUNDCONTAINER_H_

#include <string>

#include "soundcontainer_generic.h"

/**
 * A reference to a soundfile that can be lazily loaded.
 * 
 * This abstract base class specifies the common interface 
 * for all implementations of sound containers, see
 * concrete implementations for more details.
 */
class GameSoundContainer : public SoundContainer
{
    bool triggered;
    bool loaded;
    
public:
    /**
     * Create a refernece to an optionally-looping sound file.
     */
    GameSoundContainer( const SoundContainer &other );
    
    virtual ~GameSoundContainer();
    
    /**
     * Forced loading of the resource. It's not necessary to call it,
     * but useful if you know you'll need it later and want to avoid
     * the latency of loading it on-demand.
     */
    void load();
    
    /**
     * Forced unloading of the resource. It's not necessary to call it,
     * but useful if you know you won't be needing the resource for a while.
     */
    void unload();
    
    /**
     * Start playing. For a looping source, it starts the loop if not already
     * playing. For a non-looping source, it will start playing from time 0
     * even if it's already playing.
     */
    void play();
    
    /**
     * Stop playing.
     */
    void stop();
    
    /**
     * Return whether or not the sound is really playing now.
     */
    bool isPlaying() const;
    
    /**
     * Return whether or not the sound was triggered with play().
     * Will return true after play(), false after stop() and right
     * after creation.
     */
    bool isTriggered() const 
    { 
        return triggered;
    }
    
    // Concrete classes implement the following:
protected:
    virtual void loadImpl() = 0;
    virtual void unloadImpl() = 0;
    
    /**
     * Start playing. Needs not account for loopgin vs non-looping,
     * just start playing the sound.
     */
    virtual void playImpl() = 0;
    
    virtual void stopImpl() = 0;
    
    /**
     * Return whether or not the sound is really playing now.
     */
    virtual bool isPlayingImpl() const = 0;
    
};

#endif

