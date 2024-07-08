#include <iostream>
#include <vector>

class Vector2
{
    private :
        float x;
        float y;

    public : 
        Vector2(float x,float y); 
        void set_x(float x);
        void set_y(float y);
        float get_y();
        float get_x();
};