#include<map>
#include "graph.cpp"

int main()
{
    Graph cartesianSystem(5);
    cartesianSystem.addPoint(1.0,2.5);
    cartesianSystem.addPoint(3,3);
    cartesianSystem.printGraph();
}