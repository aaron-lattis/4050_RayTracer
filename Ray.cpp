
#include "Ray.h"

Ray::Ray()
{

}
Ray::~Ray()
{

}

Ray::Ray(chromeball::Vector p, chromeball::Vector d)
{
    position = p;
    direction = d;
}

const chromeball::Vector& Ray::get_position() const
{
    return position;
}

const chromeball::Vector Ray::get_direction() const
{
    return direction;
}

void Ray::set_position(chromeball::Vector p)
{
    position = p;
}

void Ray::set_direction(chromeball::Vector d)
{
    direction = d;
}