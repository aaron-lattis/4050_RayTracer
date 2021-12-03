
#include "Camera.h"
#include <math.h>
#include <iostream>




    Camera::Camera(chromeball::Vector p, chromeball::Vector v, chromeball::Vector u, float f, float a, int X, int Y)
    {
        position = p;

        viewDirection = v;

        upDirection = u;

        horizontalFieldOfView = f;

        aspectRatio = a;

        nX = X;

        nY = Y;

    }

    Camera::~Camera()
    {

    }

    Camera::Camera()
    {
        
    }

    chromeball::Vector Camera::get_position()
    {
        return position;
    }

    chromeball::Vector Camera::view(float x, float y) const
    {

        float hfov_radians = horizontalFieldOfView * (M_PI/180);
        
        float u = ((2.0 * x) / nX ) - 1.0;
        
        u = u * tan(hfov_radians/2);

        float v = ((2.0 * y) / nY ) - 1.0;

        v = v * (tan(hfov_radians/2) / aspectRatio);

        chromeball::Vector rightDirection = upDirection ^ viewDirection;

        chromeball::Vector X = u * rightDirection + v * upDirection; 

        chromeball::Vector temp = (X + viewDirection);

        chromeball::Vector n = temp / temp.magnitude();

        return n;


    }

    
   

  

