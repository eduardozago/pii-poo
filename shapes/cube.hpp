#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include "point.hpp"

namespace shapes
{

class Cube 
{
private:
    float m_edge;
    Point3d m_pos;
    float m_Area;
    
    void CalcArea() { m_Area = 6 * m_edge * m_edge; };
    
public:
    Cube() : m_edge(0), m_pos(Point3d(0,0,0)) {};
    
    Cube(float edge, Point3d pos) : m_edge(edge), m_pos(pos) {
        CalcArea();
    };
    
    //getters
    float GetArea() const { return m_Area;} ;   
    float GetEdge() const { return m_edge;} ;   
};

};


#endif
