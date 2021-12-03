
#include <iostream>
#include "Trace.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"

chromeball::Color Trace(const Ray& r, const Scene& s)
{
    float distanceToSphere = -2;
    float distanceToPlane = -2;

    distanceToSphere = s.get_sphere().intersection(r);
    distanceToPlane = s.get_plane().intersection(r);

    if(distanceToSphere < 0 && distanceToPlane < 0)
    {
        chromeball::Color black = chromeball::Color();
        
        black.r = 0.0;
        black.g = 0.0;
        black.b = 0.0;

        return black;
    }
    if (distanceToSphere > 0 && distanceToPlane < 0)
    {
        return s.get_sphere().get_color();
    }
    else if (distanceToSphere < 0 && distanceToPlane > 0)
    {
        return s.get_plane().get_color();
    } 
    else if(distanceToSphere > 0 && distanceToPlane > 0)
    {
        if(distanceToSphere < distanceToPlane) { return s.get_sphere().get_color(); }
        else { return s.get_plane().get_color(); }
    }

    chromeball::Color black = chromeball::Color();
        
        black.r = 0.0;
        black.g = 0.0;
        black.b = 0.0;

        return black;
}
