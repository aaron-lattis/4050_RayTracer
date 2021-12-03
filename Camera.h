
#include "Vector.h"

#ifndef CAMERA_H
#define CAMERA_H


class Camera
{

    public:

        Camera(chromeball::Vector p, chromeball::Vector v, chromeball::Vector u, float f, float a, int X, int Y);
        ~Camera();

        Camera();

        chromeball::Vector view(float x, float y) const;

        chromeball::Vector get_position();

    
    private:

        chromeball::Vector position;

        chromeball::Vector viewDirection;

        chromeball::Vector upDirection;

        float horizontalFieldOfView;

        float aspectRatio;

        int nX;

        int nY;

};

#endif
