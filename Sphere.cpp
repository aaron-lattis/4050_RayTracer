
#include "Ray.h"
#include "Sphere.h"
#include <cmath>



Sphere::Sphere(chromeball::Vector p, int r, double red, double green, double blue)
{
    position = p;

    radius = r;

    color.r = red;
    color.g = green;
    color.b = blue;
}

Sphere::Sphere()
{

}

Sphere::~Sphere()
{

}

float Sphere::intersection(const Ray& r) const
{
    float determinant;

    chromeball::Vector rayMinusPoint = r.get_position() - position; //This is R0 - Pc

    determinant = pow((r.get_direction() * rayMinusPoint), 2) + pow(radius, 2) - pow(rayMinusPoint.magnitude(), 2); 

    if (determinant < 0) 
    { 
        return -1.0; 
    }
    else if (determinant == 0)
    {
        return (r.get_direction() * rayMinusPoint) * -1;
    }
    else 
    {
        float withoutDeterminant = (r.get_direction() * rayMinusPoint) * -1;

        float tPlus = withoutDeterminant + sqrt(determinant);
        float tMinus = withoutDeterminant - sqrt(determinant);

        if (tMinus < 0 && tPlus < 0) { return -1.0; }
        else if (tMinus > 0 && tPlus < 0) { return tMinus; }
        else if (tMinus < 0 && tPlus > 0) { return tPlus; }  
        else 
        {
            if (tMinus < tPlus) { return tMinus; }
            else { return tPlus; }
        } 
    }
}

const chromeball::Color Sphere::get_color() const
{
    return color;
}
