

#include "Vector.h"

#ifndef IMAGE_PLANE_H
#define IMAGE_PLANE_H


class ImagePlane
{

    public:

        ImagePlane(int x, int y);
        ~ImagePlane();

        chromeball::Color get(int i, int j) const;

        void set(int i, int j, const chromeball::Color& C);


    private:

        int nX;

        int nY; 

        chromeball::Color* data;      
};

#endif


