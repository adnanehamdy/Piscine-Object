#include "vector2.hpp"


Vector2::Vector2(float x, float y) : x(x), y(y)
{}

float Vector2::get_x()
{
    return this->x;
}

float Vector2::get_y()
{
    return this->y;
}

void Vector2::set_x(float x)
{
    this->x = x;
}

void Vector2::set_y(float y)
{
    this->y = y;
}