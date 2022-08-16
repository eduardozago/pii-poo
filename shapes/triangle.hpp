#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include "point.hpp"

namespace shapes
{
    
class Triangle 
{
private:
    float m_edge1, m_edge2, m_edge3;
    float m_angle1, m_angle2, m_angle3;
    float m_Area;
    float m_s;
    Point2d m_p1, m_p2, m_p3, m_pos;
    
    void CalcArea() { m_Area = sqrt(m_s * (m_s - m_edge1) * (m_s - m_edge2) * (m_s - m_edge3)); };
    
public:
    Triangle();
    Triangle(Point2d p1, Point2d p2, Point2d p3);
    
    //getters
    float GetArea() const { return m_Area;} ;
    Point2d GetP1() const { return m_p1;} ;
    Point2d GetP2() const { return m_p2;} ;
    Point2d GetP3() const { return m_p3;} ;
    float GetEdge1() const { return m_edge1;} ;
    float GetEdge2() const { return m_edge2;} ;
    float GetEdge3() const { return m_edge3;} ;
    float GetAngle1() const { return m_angle1;} ;
    float GetAngle2() const { return m_angle2;} ;
    float GetAngle3() const { return m_angle3;} ;
    
};

};


#endif
