
#include <iostream>
#include <fstream>

#include "Vector.h"
#include "Sphere.h"
#include "Plane.h"
#include "ImagePlane.h"
#include "Camera.h"
#include "Ray.h"
#include "Scene.h"
#include "Trace.h"

int main()
{

    ImagePlane imagePlane = ImagePlane(1024, 768);

    chromeball::Vector spherePosition = chromeball::Vector(1, 2, 15);

    Sphere sphere = Sphere(spherePosition, 3, 0.5, 1.0, 0.0);

    chromeball::Vector planePoint = chromeball::Vector(0, 2, 0);
    chromeball::Vector planeVector = chromeball::Vector(0, 1, 0);

    Plane plane = Plane(planePoint, planeVector, 0, 0.5, 1.0);

    chromeball::Vector CameraPosition = chromeball::Vector(0, 0, 0);
    chromeball::Vector CameraViewDirection = chromeball::Vector(0, 0, 1);
    chromeball::Vector CameraUpDirection = chromeball::Vector(0, 1, 0);
    float nX = 1024.0;
    float nY = 768.0;
    float aspectRatio = 1.3333;

    Camera camera = Camera(CameraPosition, CameraViewDirection, CameraUpDirection, 90, aspectRatio, nX, nY);

    Scene scene = Scene(sphere, plane, camera);


    chromeball::Vector rayDirection;
    chromeball::Vector rayPosition;

    Ray ray = Ray();

    chromeball::Color pixelColor;

    
    for (int i = 0; i < nX; i ++)
    {
        for (int j = 0; j < nY; j ++)
        {
            rayDirection = camera.view(i, j);
            rayPosition = camera.get_position();

            ray.set_direction(rayDirection);
            ray.set_position(rayPosition);

            pixelColor = Trace(ray, scene);

            imagePlane.set(i, j, pixelColor);
        }
    }

    int r;
    int g;
    int b;

    chromeball::Color printColor;

    std::ofstream myfile;
    myfile.open ("output.ppm");
    myfile << "P3\n";
    myfile << "1024 768\n";
    myfile << "255\n";

    for (int j = 0; j < nY; j ++)
    {
        for (int i = 0; i < nX; i ++)
        {
            printColor = imagePlane.get(i, j);

            r = int (printColor.r * 255); 
            g = int (printColor.g * 255);
            b = int (printColor.b * 255);

            myfile << r << " "; 
            myfile << g << " ";
            myfile << b << "\n";
        }
    }

    myfile.close();

    return 0;
}
