#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "point.hpp"

namespace shapes
{

class Sphere 
{
private:
    float m_ratio;
    shapes::Point3d m_pos;
    float m_Area;
    
    void CalcArea() { m_Area = 4 * 3.14159 * m_ratio * m_ratio; };
    
public:
    Sphere() : m_ratio(0), m_pos(shapes::Point3d(0,0,0)) {};
    
    Sphere(float ratio, Point3d pos) : m_ratio(ratio), m_pos(pos) 
    { 
        CalcArea(); 
    };
    
    //getters
    float GetArea() const { return m_Area;} ;
    float GetRatio() const { return m_ratio;} ;
};

};

#endif
