

#include "Vector.h"

#ifndef RAY_H
#define RAY_H


class Ray
{

    public:

        Ray();
        ~Ray();

        Ray(chromeball::Vector p, chromeball::Vector d);

        const chromeball::Vector& get_position() const;

        const chromeball::Vector get_direction() const;

        void set_position(chromeball::Vector p);

        void set_direction(chromeball::Vector d);

        


    private:

        chromeball::Vector position;

        chromeball::Vector direction; 
};

#endif
