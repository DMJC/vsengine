//
// C++ Interface: Audio::Scene
//
#ifndef __AUDIO_LISTENER_H__INCLUDED__
#define __AUDIO_LISTENER_H__INCLUDED__

#include "Exceptions.h"
#include "Types.h"
#include "RenderableListener.h"

namespace Audio {

    /**
     * Listener class
     *
     * @remarks This class represents a scene listener. Its interface is quite simple.
     *      It's possible that scene managers (scenes) will provide their own implementation.
     *      @par This class is not abstract, its interface is simple enough so that Listener
     *      acts both as interface and basic implementation.
     */
    class Listener
    {
        LVector3 position;
        Vector3 atDirection;
        Vector3 upDirection;
        Vector3 velocity;
        
        Scalar radius;
        
        Scalar gain;
        
        Range<Scalar> cosAngleRange;
        
        SharedPtr<UserData> userDataPtr;
        SharedPtr<RenderableListener> rendererDataPtr;
        
        Matrix3 worldToLocal;
        
    protected:
        /** Notify implementations after position and/or attributes changes
         * @remarks Implementations use the "dirty" member struct to precisely know and 
         *      track what changed and what didn't. Call reset() when synchronized.
         */
        struct Dirty
        {
            Dirty()
                : location(0),
                  attributes(0),
                  gain(0)
            {}
                  
            /** position, velocity & direction */
            int location : 1;
            
            /** min/max angle, radius, pf radius ratios, reference freqs */
            int attributes : 1;
            
            /** min/max angle, radius, pf radius ratios, reference freqs */
            int gain : 1;
            
            void reset()
            {
                location = 0;
                attributes = 0;
                gain = 0;
            }
            
            void setAll()
            {
                location = 1;
                attributes = 1;
                gain = 1;
            }
        } dirty;
        
    public:
        /** Construct a default listener with default parameters */
        Listener() noexcept;
        
        virtual ~Listener();
        
        /** Return the listener's central position in 3D space */
        LVector3 getPosition() const noexcept { return position; }
        
        /** Set the listener's central position in 3D space */
        void setPosition(LVector3 x) noexcept { position = x; dirty.location = 1; }
        
        /** Return the listener's front direction */
        Vector3 getAtDirection() const noexcept { return atDirection; }
        
        /** Return the listener's up direction */
        Vector3 getUpDirection() const noexcept { return upDirection; }
        
        /** Set the listener's orientation */
        void setOrientation(Vector3 at, Vector3 up) noexcept { atDirection = at; upDirection = up; dirty.location = 1; }
        
        /** Return the listener's velocity */
        Vector3 getVelocity() const noexcept { return velocity; }
        
        /** Set the listener's velocity */
        void setVelocity(Vector3 x) noexcept { velocity = x; dirty.location = 1; }
        
        
        /** Return the listener's minimum/maximum perception angle
         * @remarks A listener's sound perception may be directional or omnidirectional. 
         *      Perception will be full within minimum directional drift. Further drift 
         *      will attenuate the sound until it reaches maximum attenuation by the maximum 
         *      perception angle. Notice that maximum attenuation may not be full silence.
         */
        Range<Scalar> getAngleRange() const noexcept;
        
        /** @see getAngleRange */
        void setAngleRange(Range<Scalar> r) noexcept;
        
        /** @see getAngleRange @remarks This version returns cosine-angles rather than radians, much quicker */
        Range<Scalar> getCosAngleRange() const noexcept { return cosAngleRange; }
        
        /** @see getAngleRange @remarks This version takes cosine-angles rather than radians, much quicker */
        void setCosAngleRange(Range<Scalar> r) noexcept { cosAngleRange = r; dirty.attributes = 1; }
        
        /** Get the listener's radius */
        Scalar getRadius() const noexcept { return radius; }
        
        /** Set the listener's radius */
        void setRadius(Scalar r) noexcept { radius = r; dirty.attributes = 1; }
        
        
        /** Get the listener's gain */
        Scalar getGain() const noexcept { return gain; }
        
        /** Set the listener's gain */
        void setGain(Scalar g) noexcept { gain = g; dirty.gain = 1; }
        
        
        /** Get renderer-specific data associated (and destroyed) with this sound source */
        SharedPtr<RenderableListener> getRenderable() const noexcept { return rendererDataPtr; }
        
        /** Set renderer-specific data to be associated (and destroyed) with this sound source */
        void setRenderable(SharedPtr<RenderableListener> ptr) noexcept { rendererDataPtr = ptr; dirty.setAll(); }
        
        /** Get user-specific data associated (and destroyed) with this listener */
        SharedPtr<UserData> getUserData() const noexcept { return userDataPtr; }
        
        /** Set user-specific data to be associated (and destroyed) with this listener */
        void setUserData(SharedPtr<UserData> ptr) noexcept { userDataPtr = ptr; }
        
        
        /** @see RenderableListener::update
         * @param flags see RenderableListener::UpdateFlags
         * @note It's not just a convenience, the abstract listener has to update
         *      its internal dirty flags and other things as well.
         */
        void update(int flags) noexcept;

        
        /**
         * Return the direction 'dir' in a local coordinate system centered at
         * the listener's position, with the -Z axis pointing forward,
         * +X pointing rightward and +Y pointing upwards (the OpenGL way).
         * @note The attributes used are those set during the last update()
         * @note The behavior is unspecified if there was no previous call to update().
         */
        Vector3 toLocalDirection(Vector3 dir) const noexcept;
        
        
    };

};

#endif//__AUDIO_LISTENER_H__INCLUDED__
