#ifndef LIGHT_H
#define LIGHT_H

#include "object.h"
enum light_type{ SPOTLIGHT, LOCAL, INFINITE, PROJECTOR, SKYLIGHT, IMAGE, GONIOMETRIC, AREA };

class light : public object
{
    public:
        light();
        virtual ~light();
    protected:
    private:
};

#endif // LIGHT_H
