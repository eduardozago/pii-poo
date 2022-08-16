// Eduardo Zago - 16203169

#include <vector>
#include "point.hpp"
#include "node.hpp"
#include "circle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "sphere.hpp"
#include "cube.hpp"
#include "tetrahedron.hpp"

using namespace shapes;

int main()
{   
    vector<Node> listofshapes;

    Node n1;
    Node n2(Circle(4.5, Point2d(0,0)));
    Node n3(Square(4, Point2d(-10,-10)));
    Node n4(Triangle(Point2d(0,0), Point2d(10,0), Point2d(10,10)));
    Node n5(Sphere(3, Point3d(0,0,0)));
    Node n6(Cube(7.5, Point3d(-10,-10,-10)));
    Node n7(Tetrahedron(Point3d(10,0,0), Point3d(0,0,0), Point3d(0,10,0),Point3d(0,0,10)));

    listofshapes.push_back(n1);
    listofshapes.push_back(n2);
    listofshapes.push_back(n3);
    listofshapes.push_back(n4);
    listofshapes.push_back(n5);
    listofshapes.push_back(n6);
    listofshapes.push_back(n7);
 
    for(size_t i=0; i<listofshapes.size(); i++)
    {
        datatypes type;
        void* rawdata = listofshapes.at(i).getRawData(type);

        if(type == tcircle)
        {
            cout << endl << "CIRCLE" << endl
                << "Area: " << ((Circle*)rawdata)->GetArea() 
                << " ratio: " << ((Circle*)rawdata)->GetRatio() 
            << endl << endl;
            continue;
        } 

        if(type == tsquare)
        {
            cout << "SQUARE" << endl
                << "Area: " << ((Square*)rawdata)->GetArea() 
                << " edge: " << ((Square*)rawdata)->GetEdge() 
            << endl << endl;
            continue;
        } 

        if(type == ttriangle)
        {
            cout << "TRIANGLE" << endl    
                << "Area: " << ((Triangle*)rawdata)->GetArea()
                << " p1: (" << ((Triangle*)rawdata)->GetP1().GetX() << "," << ((Triangle*)rawdata)->GetP1().GetY() << ")"
                << " p2: (" << ((Triangle*)rawdata)->GetP2().GetX() << "," << ((Triangle*)rawdata)->GetP2().GetY() << ")"
                << " p3: (" << ((Triangle*)rawdata)->GetP3().GetX() << "," << ((Triangle*)rawdata)->GetP3().GetY() << ")" << endl
                << "angle1: " << ((Triangle*)rawdata)->GetAngle1() 
                << " angle2: " << ((Triangle*)rawdata)->GetAngle2() 
                << " angle3: " << ((Triangle*)rawdata)->GetAngle3() << endl
                << "edge1: " << ((Triangle*)rawdata)->GetEdge1()
                << " edge2: " << ((Triangle*)rawdata)->GetEdge2()
                << " edge3: " << ((Triangle*)rawdata)->GetEdge3() 
            << endl << endl;
            continue;
        }

        if(type == tsphere)
        {
            cout << "SPHERE" << endl
                << "Area: " << ((Sphere*)rawdata)->GetArea() 
                << " ratio: " << ((Sphere*)rawdata)->GetRatio() 
            << endl << endl;
            continue;
        }

        if(type == tcube)
        {
            cout << "CUBE" << endl
                << "Area: " << ((Cube*)rawdata)->GetArea() 
                << " edge: " << ((Cube*)rawdata)->GetEdge() 
            << endl << endl;
            continue;
        }

        if(type == ttetrahedron)
        {
            cout << "TETRAHEDRON" << endl    
                << "Area: " << ((Tetrahedron*)rawdata)->GetArea()
                << " p1: (" << ((Tetrahedron*)rawdata)->GetP1().GetX() << "," 
                << ((Tetrahedron*)rawdata)->GetP1().GetY() << ","
                << ((Tetrahedron*)rawdata)->GetP1().GetZ() << ")"
                << " p2: (" << ((Tetrahedron*)rawdata)->GetP2().GetX() << "," 
                << ((Tetrahedron*)rawdata)->GetP2().GetY() << ","
                << ((Tetrahedron*)rawdata)->GetP2().GetZ() << ")"
                << " p3: (" << ((Tetrahedron*)rawdata)->GetP3().GetX() << "," 
                << ((Tetrahedron*)rawdata)->GetP3().GetY() << ","
                << ((Tetrahedron*)rawdata)->GetP3().GetZ() << ")"
                << " p4: (" << ((Tetrahedron*)rawdata)->GetP4().GetX() << "," 
                << ((Tetrahedron*)rawdata)->GetP4().GetY() << ","
                << ((Tetrahedron*)rawdata)->GetP4().GetZ() << ")" << endl
                << "edge1: " << ((Tetrahedron*)rawdata)->GetEdge1()
                << " edge2: " << ((Tetrahedron*)rawdata)->GetEdge2()
                << " edge3: " << ((Tetrahedron*)rawdata)->GetEdge3()
                << " edge4: " << ((Tetrahedron*)rawdata)->GetEdge4() 
                << " edge5: " << ((Tetrahedron*)rawdata)->GetEdge5() 
                << " edge6: " << ((Tetrahedron*)rawdata)->GetEdge6()  
            << endl << endl;
            continue;ine
        }
    }

    return 0;
}
