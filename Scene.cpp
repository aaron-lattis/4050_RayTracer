

#include "Scene.h"

Scene::Scene(Sphere s, Plane p, Camera c)
{
    sphere = s;
    plane = p;
    camera = c;
}

Scene::~Scene()
{

}

Sphere Scene::get_sphere() const
{
    return sphere;
}

Plane Scene::get_plane() const
{
    return plane;
}

Camera Scene::get_camera() const
{
    return camera;
}
