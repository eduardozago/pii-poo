#ifndef POINT_H
#define POINT_H

namespace shapes
{

class Point2d
{
private:
    float m_x, m_y;
    
public:
    Point2d() : m_x(0), m_y(0) {};
    Point2d(float x, float y=0) : m_x(x), m_y(y) {};
    
    float GetX() const { return m_x;};
    float GetY() const { return m_y;};
};

class Point3d
{
private:
    float m_x, m_y, m_z;
    
public:
    Point3d() : m_x(0), m_y(0), m_z(0) {};
    Point3d(float x, float y=0, float z=0) : m_x(x), m_y(y), m_z(z) {};

    float GetX() const { return m_x;};
    float GetY() const { return m_y;};
    float GetZ() const { return m_z;};
};

};

#endif
