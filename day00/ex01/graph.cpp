#include<vector>
#include<iostream>
#include "vector2.hpp"
#include <sstream>

typedef std::vector<char> char_vec;
class Graph
{
    private :

        std::vector<Vector2> points;
        std::vector<char_vec> grid;
        int max;
    public : 
        Graph(int maxValue): points(0, Vector2(0,0)), grid(maxValue + 1, char_vec(maxValue + 1, '.')), max(maxValue)
        {
        }
    void addPoint(float y, float x)
    {
        points.push_back(Vector2(y,x));
    }

    void fillGridWithPoints()
    {
        for (std::vector<Vector2>::iterator it = points.begin(); it != points.end(); it++)
            grid[(*it).get_y()][(*it).get_x()] = 'X';
    }

    void printGraph()
    {
        fillGridWithPoints();
        std::stringstream out;
        out << "   ";
        for (int y = max;  y >= 0; y--)
        {
            std::cout << " "  << y << " ";
            for (int x = 0; x <= max; x++)
            {
                std::cout << " " << grid[y][x] << " ";
            }
            out << " " << max - y << " ";
            std::cout << std::endl;
        }
        std::cout << out.str() << std::endl;
    }
};