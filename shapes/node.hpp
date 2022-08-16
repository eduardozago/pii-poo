#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "point.hpp"
#include "circle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "sphere.hpp"
#include "cube.hpp"
#include "tetrahedron.hpp"

using namespace std;

enum datatypes { tnone, tcircle, tsquare, ttriangle, tsphere, tcube, ttetrahedron, tpoint2d, tpoint3d };

class Node
{
private:
    void* m_data;
    datatypes m_type;
    
public:
    //constructors
    Node()          : m_data(NULL), m_type(tnone) {};
    Node(shapes::Circle i) : m_data(new shapes::Circle(i)), m_type(tcircle) {};
    Node(shapes::Square i) : m_data(new shapes::Square(i)), m_type(tsquare) {};
    Node(shapes::Triangle i) : m_data(new shapes::Triangle(i)), m_type(ttriangle) {};
    Node(shapes::Sphere i) : m_data(new shapes::Sphere(i)), m_type(tsphere) {};
    Node(shapes::Cube i) : m_data(new shapes::Cube(i)), m_type(tcube) {};
    Node(shapes::Tetrahedron i) : m_data(new shapes::Tetrahedron(i)), m_type(ttetrahedron) {};
    Node(shapes::Point2d i) : m_data(new shapes::Point2d(i)),m_type(tpoint2d) {};
    Node(shapes::Point3d i) : m_data(new shapes::Point3d(i)),m_type(tpoint3d) {};
    
    //destructor
    ~Node();    
    
    //setters
    //update()
    
    //getters
    void* getRawData(datatypes& type) const { 
        type=m_type; 
        return m_data;         
    };
    
};
#endif
