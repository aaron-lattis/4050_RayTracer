
#include "Ray.h"
#include "Vector.h"

#ifndef SPHERE_H
#define SPHERE_H


class Sphere
{

    public:

        Sphere(chromeball::Vector p, int r, double red, double green, double blue);
        ~Sphere();

        Sphere();

        float intersection(const Ray& r) const;

        const chromeball::Color get_color() const;


    private:

        chromeball::Vector position;

        int radius; 

        chromeball::Color color;
};

#endif