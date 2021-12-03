
#include "Ray.h"
#include "Plane.h"
#include <cmath>
#include <iostream>



Plane::Plane(chromeball::Vector p, chromeball::Vector d, double red, double green, double blue)
{
    position = p;

    normalDirection = d;

    color.r = red;
    color.g = green;
    color.b = blue;
}

Plane::Plane()
{

}

Plane::~Plane()
{

}

float Plane::intersection(const Ray& r) const
{
    float t; 

    float denominator;

    chromeball::Vector temp = (r.get_position() - position) * -1; 

    t = temp * normalDirection;

    denominator = r.get_direction() * normalDirection;

    if (denominator == 0) { return -1.0; }
    else { return t / denominator; }   
}

const chromeball::Color Plane::get_color() const
{
    return color;
}

