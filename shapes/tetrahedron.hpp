#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include <iostream>
#include <cmath>
#include "point.hpp"

namespace shapes
{
    
class Tetrahedron 
{
private:
    float m_edge1, m_edge2, m_edge3, m_edge4, m_edge5, m_edge6;
    float m_t1, m_t2, m_t3, m_t4;
    float m_s1, m_s2, m_s3, m_s4;
    float m_Area;
    Point3d m_p1, m_p2, m_p3, m_p4, m_pos;
    
    void CalcArea();
    
public:
    Tetrahedron();
    Tetrahedron(Point3d p1, Point3d p2, Point3d p3, Point3d p4);
    
    //getters
    float GetArea() const { return m_Area; };
    Point3d GetP1() const { return m_p1; };
    Point3d GetP2() const { return m_p2; };
    Point3d GetP3() const { return m_p3; };
    Point3d GetP4() const { return m_p4; };
    float GetEdge1() const { return m_edge1; };
    float GetEdge2() const { return m_edge2; };
    float GetEdge3() const { return m_edge3; };
    float GetEdge4() const { return m_edge4; };
    float GetEdge5() const { return m_edge5; };
    float GetEdge6() const { return m_edge6; };
    
};

};


#endif
