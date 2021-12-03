

#include "Vector.h"
#include "Sphere.h"
#include "Plane.h"
#include "Camera.h"

#ifndef SCENE_H
#define SCENE_H


class Scene
{

    public:

        Scene(Sphere s, Plane p, Camera c);
        ~Scene();

        Sphere get_sphere() const;

        Plane get_plane() const;

        Camera get_camera() const;


    private:

        Sphere sphere;

        Plane plane; 

        Camera camera;
        
};

#endif


