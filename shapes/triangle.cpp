#include "triangle.hpp"

namespace shapes {

Triangle::Triangle()
{
    m_edge1=m_edge2=m_edge3=m_angle1=m_angle2=m_angle3=0;
    m_p1=m_p2=m_p3=m_pos=Point2d(0,0);
    
    m_Area=0;
}


Triangle::Triangle(Point2d p1, Point2d p2, Point2d p3)
{
    Triangle();
    
    m_p1=p1;
    m_p2=p2;
    m_p3=p3;
   
    m_edge1 = sqrt((p2.GetX()-p3.GetX())*(p2.GetX()-p3.GetX()) + (p2.GetY()-p3.GetY())*(p2.GetY()-p3.GetY()));
    m_edge2 = sqrt((p1.GetX()-p3.GetX())*(p1.GetX()-p3.GetX()) + (p1.GetY()-p3.GetY())*(p1.GetY()-p3.GetY()));
    m_edge3 = sqrt((p1.GetX()-p2.GetX())*(p1.GetX()-p2.GetX()) + (p1.GetY()-p2.GetY())*(p1.GetY()-p2.GetY()));
   
    m_s = (m_edge1 + m_edge2 + m_edge3) / 2;

    m_angle1 = acos((pow(m_edge1,2) - pow(m_edge2,2) - pow(m_edge3,2)) / (-2 * m_edge2 * m_edge3));
    m_angle1 = (m_angle1 * 360) / (2 * 3.14159265359 );
    m_angle2 = acos((pow(m_edge2,2) - pow(m_edge1,2) - pow(m_edge3,2)) / (-2 * m_edge1 * m_edge3));
    m_angle2 = (m_angle2 * 360) / (2 * 3.14159265359 );
    m_angle3 = acos((pow(m_edge3,2) - pow(m_edge1,2) - pow(m_edge2,2)) / (-2 * m_edge1 * m_edge2));
    m_angle3 = (m_angle3 * 360) / (2 * 3.14159265359 );

    CalcArea();
}

}
