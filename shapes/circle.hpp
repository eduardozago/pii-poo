#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "point.hpp"

namespace shapes
{

class Circle 
{
private:
    float m_ratio;
    shapes::Point2d m_pos;
    float m_Area;
    
    void CalcArea() { m_Area = 3.14159 * m_ratio * m_ratio; };
    
public:
    Circle() : m_ratio(0), m_pos(shapes::Point2d(0,0)) {};
    
    Circle(float ratio, Point2d pos) : m_ratio(ratio), m_pos(pos) 
    { 
        CalcArea(); 
    };
    
    //getters
    float GetArea() const { return m_Area;} ;
    float GetRatio() const { return m_ratio;} ;
};

};

#endif
