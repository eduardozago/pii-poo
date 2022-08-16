#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "point.hpp"

namespace shapes
{

class Square 
{
private:
    float m_edge;
    Point2d m_pos;
    float m_Area;
    
    void CalcArea() { m_Area = m_edge * m_edge; };
    
public:
    Square() : m_edge(0), m_pos(Point2d(0,0)) {};
    
    Square(float edge, Point2d pos) : m_edge(edge), m_pos(pos) {
        CalcArea();
    };
    
    //getters
    float GetArea() const { return m_Area;} ;   
    float GetEdge() const { return m_edge;} ;   
};

};


#endif
