#include "tetrahedron.hpp"

namespace shapes {

Tetrahedron::Tetrahedron()
{
    m_edge1=m_edge2=m_edge3=m_edge4=m_edge5=m_edge6=0;
    m_p1=m_p2=m_p3=m_p4=m_pos=Point3d(0,0,0);
    
    m_Area=0;
}


Tetrahedron::Tetrahedron(Point3d p1, Point3d p2, Point3d p3, Point3d p4)
{
    Tetrahedron();
    
    m_p1=p1;
    m_p2=p2;
    m_p3=p3;
    m_p4=p4;
   
    m_edge1 = sqrt((p2.GetX()-p3.GetX())*(p2.GetX()-p3.GetX()) + (p2.GetY()-p3.GetY())*(p2.GetY()-p3.GetY()) + (p2.GetZ()-p3.GetZ())*(p2.GetZ()-p3.GetZ()));
    m_edge2 = sqrt((p1.GetX()-p3.GetX())*(p1.GetX()-p3.GetX()) + (p1.GetY()-p3.GetY())*(p1.GetY()-p3.GetY()) + (p1.GetZ()-p3.GetZ())*(p1.GetZ()-p3.GetZ()));
    m_edge3 = sqrt((p1.GetX()-p2.GetX())*(p1.GetX()-p2.GetX()) + (p1.GetY()-p2.GetY())*(p1.GetY()-p2.GetY()) + (p1.GetZ()-p2.GetZ())*(p1.GetZ()-p2.GetZ()));
    m_edge4 = sqrt((p4.GetX()-p1.GetX())*(p4.GetX()-p1.GetX()) + (p4.GetY()-p1.GetY())*(p4.GetY()-p1.GetY()) + (p4.GetZ()-p1.GetZ())*(p4.GetZ()-p1.GetZ()));
    m_edge5 = sqrt((p4.GetX()-p2.GetX())*(p4.GetX()-p2.GetX()) + (p4.GetY()-p2.GetY())*(p4.GetY()-p2.GetY()) + (p4.GetZ()-p2.GetZ())*(p4.GetZ()-p2.GetZ()));
    m_edge6 = sqrt((p4.GetX()-p3.GetX())*(p4.GetX()-p3.GetX()) + (p4.GetY()-p3.GetY())*(p4.GetY()-p3.GetY()) + (p4.GetZ()-p3.GetZ())*(p4.GetZ()-p3.GetZ()));
   
    m_s1 = (m_edge1 + m_edge2 + m_edge3) / 2;
    m_s2 = (m_edge3 + m_edge4 + m_edge5) / 2;
    m_s3 = (m_edge1 + m_edge5 + m_edge6) / 2;
    m_s4 = (m_edge2 + m_edge4 + m_edge6) / 2;

    CalcArea();
}

void Tetrahedron::CalcArea(){
    m_t1 = sqrt(m_s1 * (m_s1 - m_edge1) * (m_s1 - m_edge2) * (m_s1 - m_edge3));
    m_t2 = sqrt(m_s2 * (m_s2 - m_edge3) * (m_s2 - m_edge4) * (m_s2 - m_edge5));
    m_t3 = sqrt(m_s3 * (m_s3 - m_edge1) * (m_s3 - m_edge5) * (m_s3 - m_edge6));
    m_t4 = sqrt(m_s4 * (m_s4 - m_edge2) * (m_s4 - m_edge4) * (m_s4 - m_edge6));

    m_Area = m_t1 + m_t2 + m_t3 + m_t4;
}

}
