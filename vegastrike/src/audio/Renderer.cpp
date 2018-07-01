//
// C++ Implementation: Audio::Renderer
//

#include "Renderer.h"
#include "config.h"

namespace Audio {

    Renderer::Renderer() noexcept(false)
    {
    }
    
    Renderer::~Renderer()
    {
    }
    
    void Renderer::setMeterDistance(Scalar distance) 
        noexcept
    {
        meterDistance = distance;
    }
    
    Scalar Renderer::getMeterDistance() const 
        noexcept
    {
        return meterDistance;
    }
    
    void Renderer::setDopplerFactor(Scalar factor) 
        noexcept
    {
        dopplerFactor = factor;
    }
    
    Scalar Renderer::getDopplerFactor() const 
        noexcept
    {
        return dopplerFactor;
    }
    
    void Renderer::setOutputFormat(const Format &format) 
        noexcept(false)
    {
        outputFormat = format;
    }
    
    const Format& Renderer::getOutputFormat() const 
        noexcept
    {
        return outputFormat;
    }
    
    void Renderer::beginTransaction() 
        noexcept(false)
    {
        // intentionally blank
    }
    
    void Renderer::commitTransaction() 
        noexcept(false)
    {
        // intentionally blank
    }
};
