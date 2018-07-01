//
// C++ Interface: Audio::Source
//
#ifndef __AUDIO_SOURCE_H__INCLUDED__
#define __AUDIO_SOURCE_H__INCLUDED__

#include "Exceptions.h"
#include "Types.h"
#include "Format.h"
#include "RenderableSource.h"

namespace Audio {

    // Forward declarations
    
    class Sound;
    class Listener;
    class SourceListener;
    

    /**
     * Source abstract class
     *
     * @remarks This is the interface to all kinds of audio sources.
     *      This base class implements the majority of the functions required
     *      for sources, specific implementations need only provide a handful
     *      of functions (impl functions) that keep their associated scene managers
     *      up to speed.
     *      @par Renderer-specific implementation goes through RenderableSource s
     *      attached to the abstract Source. Renderers are responsible for attaching
     *      RenderableSource s to abstract Sources as necessary. Many implementation
     *      functions (as play/stop/getPlayingTime) go through those renderer-specific 
     *      interfaces.
     *
     */
    class Source
    {
    private:
        SharedPtr<Sound> soundPtr;
        SharedPtr<RenderableSource> rendererDataPtr;
        SharedPtr<UserData> userDataPtr;
        long userDataLong;
        SharedPtr<SourceListener> sourceListenerPtr;
        
    protected:
        LVector3 position;
        Vector3 direction;
        Vector3 velocity;
        
        Range<Scalar> cosAngleRange;
        
        Scalar radius;
        PerFrequency<Scalar> pfRadiusRatios;
        PerFrequency<Scalar> referenceFreqs;
        
        Scalar gain;
        
        struct {
            int looping : 1;
            int attenuated : 1;
            int relative : 1;
        } flags;
        
        Timestamp lastKnownPlayingTime;
        Timestamp lastKnownPlayingTimeTime;
        
        /** Notify implementations after position and/or attributes changes
         * @remarks Implementations use the "dirty" member struct to precisely know and 
         *      track what changed and what didn't. Call reset() when synchronized.
         */
        struct {
            /** position, velocity & direction */
            int location : 1;
            
            /** min/max angle, radius, pf radius ratios, reference freqs, attenuation */
            int attributes : 1;
            
            /** gain */
            int gain : 1;
            
            /** soundPtr */
            int soundPtr : 1;
            
            /** looping */
            int soundAttributes : 1;
            
            void reset()
            {
                location = 0;
                attributes = 0;
                gain = 0;
                soundPtr = 0;
                soundAttributes = 0;
            }
            
            void setAll()
            {
                location = 1;
                attributes = 1;
                gain = 1;
                soundAttributes = 1;
            }
        } dirty;
        
    protected:
        /** Internal constructor used by derived classes */
        Source(SharedPtr<Sound> sound, bool looping = false) noexcept;
        
    public:
        virtual ~Source();
        
        /** Return the source's central position in 3D space */
        LVector3 getPosition() const noexcept { return position; }
        
        /** Set the source's central position in 3D space */
        void setPosition(LVector3 x) noexcept { position = x; dirty.location = 1; }
        
        /** Return the source's main propagation direction */
        Vector3 getDirection() const noexcept { return direction; }
        
        /** Set the source's main propagation direction */
        void setDirection(Vector3 x) noexcept { direction = x; dirty.location = 1; }
        
        /** Return the source's velocity */
        Vector3 getVelocity() const noexcept { return velocity; }
        
        /** Set the source's velocity */
        void setVelocity(Vector3 x) noexcept { velocity = x; dirty.location = 1; }
        
        /** Return the source's minimum/maximum propagation angle
         * @remarks Sound will fully propagate in directions within minimum
         *      directional drift. Further drift will attenuate the sound
         *      until it (practically) disappears by the maximum propagation angle.
         */
        Range<Scalar> getAngleRange() const noexcept;
        
        /** @see getAngleRange */
        void setAngleRange(Range<Scalar> r) noexcept;
        
        /** @see getAngleRange @remarks This version returns cosine-angles rather than radians, much quicker */
        Range<Scalar> getCosAngleRange() const noexcept { return cosAngleRange; }
        
        /** @see getAngleRange @remarks This version takes cosine-angles rather than radians, much quicker */
        void setCosAngleRange(Range<Scalar> r) noexcept { cosAngleRange = r; dirty.attributes = 1; }
        
        /** Get the source's radius */
        Scalar getRadius() const noexcept { return radius; }
        
        /** Set the source's radius */
        void setRadius(Scalar r) noexcept { radius = r; dirty.attributes = 1; }
        
        /** Get the source's frequency-dependant radius ratios 
         * @remarks Sound propagation goes different for low and high frequencies than
         *      for others. Sound creation does too - this specifies the ratio of a source's
         *      volume that is generating high/low frequency vibrations. This will affect
         *      propagation of those frequencies over distance.
         */
        PerFrequency<Scalar> getPerFrequencyRadiusRatios() const noexcept { return pfRadiusRatios; }
        
        /** Set the source's frequency-dependant radius ratios
         * @see getRadiusRatios 
         */
        void setPerFrequencyRadiusRatios(PerFrequency<Scalar> val) noexcept { pfRadiusRatios = val; dirty.attributes = 1; }
        
        /** Get the source's refernece frequencies */
        PerFrequency<Scalar> getReferenceFreqs() const noexcept { return referenceFreqs; }
        
        /** Set the source's reference frequencies */
        void setReferenceFreqs(PerFrequency<Scalar> val) noexcept { referenceFreqs = val; dirty.attributes = 1; }
        
        /** Get the source's main gain */
        Scalar getGain() const noexcept { return gain; }
        
        /** Set the source's main gain */
        void setGain(Scalar g) noexcept { gain = g; dirty.gain = 1; }
        
        /** Is the source in looping mode? */
        bool isLooping() const noexcept { return flags.looping != 0; }
        
        /** Set the source's looping mode */
        void setLooping(bool loop) noexcept { flags.looping = loop ? 1 : 0; dirty.soundAttributes = 1; }
        
        /** Is the source using distance attenuation? */
        bool isAttenuated() const noexcept { return flags.attenuated != 0; }
        
        /** Set whether the source uses distance attenuation */
        void setAttenuated(bool attenuated) noexcept { flags.attenuated = attenuated ? 1 : 0; dirty.attributes = 1; }
        
        /** Is the source's position always relative to the root listener?
         * @remarks Relative sources are useful for interphase sounds, music,
         *      comm streams, and all those sources which are not anchored
         *      to a real 3D object, but rather to the listener itself.
         */
        bool isRelative() const noexcept { return flags.relative != 0; }
        
        /** Set whether the source's position is always relative to the root listener. */
        void setRelative(bool relative) noexcept { flags.relative = relative ? 1 : 0; dirty.attributes = 1; }
        
        /** Play the source
         * @param start an optional timestamp to start playing from.
         * @remarks Rewind and play from the beginning. If the source is playing, it is reset.
         *      May not take effect immediately.
         */
        void startPlaying(Timestamp start = 0) noexcept(false);
        
        /** Stop a playing source
         * @remarks If the source is playing, stop it. Otherwise, do nothing.
         *      @par Remembers the playing time so that a call to getWouldbePlayingTime can
         *      return the correct time.
         */
        void stopPlaying() noexcept;
        
        /** Pause a playing source
         * @remarks If the source is active, make it inactive. Otherwise, do nothing.
         *      Playing state is not changed, but the attached renderable is stopped. This is useful
         *      to free up resources. A later call to continuePlaying() undoes this, and playing resumes
         *      as if the source hadn't been stopped (at getWouldBePlayingTime).
         * @see getWouldBePlayingTime
         */
        void pausePlaying() noexcept;
        
        /** Continue playing a source
         * @remarks If the source is playing but inactive, continue playing. Otherwise, do nothing.
         * @see pausePlaying
         */
        void continuePlaying() noexcept(false);
        
        /** Is the source still playing? */
        bool isPlaying() const noexcept;
        
        /** Is the attached renderable playing this source? */
        bool isActive() const noexcept;
        
        /** Get the playing position of a playing or paused source */
        Timestamp getPlayingTime() const noexcept;
        
        /** Get the playing position of a playing or paused source. For a paused source, extrapolate
         * from the last known playing time and elapsed time since the measurement was done.
         */
        Timestamp getWouldbePlayingTime() const noexcept;
        
        /** Get renderer-specific data associated (and destroyed) with this sound source */
        SharedPtr<RenderableSource> getRenderable() const noexcept { return rendererDataPtr; }
        
        /** Set renderer-specific data to be associated (and destroyed) with this sound source */
        void setRenderable(SharedPtr<RenderableSource> ptr) noexcept;
        
        /** Get user-specific data associated (and destroyed) with this sound source */
        SharedPtr<UserData> getUserDataPtr() const noexcept { return userDataPtr; }
        
        /** Set user-specific data to be associated (and destroyed) with this sound source */
        void setUserDataLong(SharedPtr<UserData> ptr) noexcept { userDataPtr = ptr; }
        
        /** Get user-specific data associated with this sound source */
        long getUserDataLong() const noexcept { return userDataLong; }
        
        /** Get user-specific data associated with this sound source */
        void setUserDataLong(long data) noexcept { userDataLong = data; }
        
        /** Get an event listener associated with this sound source */
        SharedPtr<SourceListener> getSourceListener() const noexcept { return sourceListenerPtr; }
        
        /** Set an event listener to be associated with this sound source */
        void setSourceListener(SharedPtr<SourceListener> ptr) noexcept { sourceListenerPtr = ptr; }
        
        /** Get the associated sound stream */
        SharedPtr<Sound> getSound() const noexcept { return soundPtr; }
        
        /** Set the associated sound stream - Only for SceneManagers to call */
        void setSound(SharedPtr<Sound> ptr) noexcept { soundPtr = ptr; dirty.soundPtr = 1; }
        
        /** Convenience function to update the attached renderable, if present, and active. 
         * @param flags see RenderableSource::UpdateFlags
         * @param sceneListener the listener to which this source is associated
         */
        void updateRenderable(int flags, const Listener& sceneListener) noexcept;
        
        /** Seek to the specified position
         * @note It may not be supported by the renderer on all sources.
         *      Streaming sources are guaranteed to perform a rough seek on a best effort
         *      basis, meaning the effective time after the seek may be off a bit, and
         *      the process may be costly.
         *       Seeking in non-streaming sources may not be supported at all.
         * @throws EndOfStreamException if you try to seek past the end
         */
        void seek(Timestamp time) noexcept(false);
        
    protected:
        /** Set the last known playing time, update the measurement timestamp as well.
         * @return the parameter, for chaining.
         */
        Timestamp setLastKnownPlayingTime(Timestamp timestamp) noexcept;
        
        // The following section contains all the virtual functions that need be implemented
        // by a concrete Sound class. All are protected, so the stream interface is independent
        // of implementations.
    protected:
        
        /** @see startPlaying 
         * @param start The starting position.
         */
        virtual void startPlayingImpl(Timestamp start) noexcept(false) = 0;
        
        /** @see stopPlaying.*/
        virtual void stopPlayingImpl() noexcept(false) = 0;
        
        /** @see isPlaying.*/
        virtual bool isPlayingImpl() const noexcept(false) = 0;
    
        // The following section contains package-private stuff
        // They're intended for plugin developers, and not end users
    public:
        
        /**
         * Notifies source listeners (if any) that the source
         * has begun actually playing.
         *
         * @remarks Usually, listener notifications are automatic. In the
         *      case of rendering start (actual playing), it's not as
         *      easy, since the renderer and scene manager have ultimate
         *      control over it. It's the renderer's responsability, thus,
         *      to fire this notification event when it's begun rendering.
         *          All other events take place immediately, so they're
         *      automatically handled by Source's implementation.
         */
        void _notifyPlaying() noexcept;
    };

};

#endif//__AUDIO_SOURCE_H__INCLUDED__
