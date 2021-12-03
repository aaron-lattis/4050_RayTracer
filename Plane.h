

#include "Vector.h"

#ifndef PLANE_H
#define PLANE_H


class Plane
{

    public:

        Plane(chromeball::Vector p, chromeball::Vector d, double red, double green, double blue);
        ~Plane();

        Plane();

        float intersection(const Ray& r) const;

        const chromeball::Color get_color() const;


    private:

        chromeball::Vector position;

        chromeball::Vector normalDirection; 

        chromeball::Color color;
        
};

#endif

