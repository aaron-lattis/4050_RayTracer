

#include "ImagePlane.h"



    ImagePlane::ImagePlane(int x, int y)
    {
        nX = x;
        nY = y;

        int size = x * y; 

        data = new chromeball::Color [size];
    }

    ImagePlane::~ImagePlane()
    {
        delete[] data;
    }

    chromeball::Color ImagePlane::get(int i, int j) const
    {
        return data[i + (nX * j)];
    }

    void ImagePlane::set(int i, int j, const chromeball::Color& C)
    {
        data[i + (nX * j)] = C;
    }




