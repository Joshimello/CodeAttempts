#include <iostream>
#include <string>
#include <cmath>

#ifndef SHAPE_H
#define SHAPE_H

namespace oj
{
    class Shape 
    {   
    public:
        double getArea();
        double getPerimeter();
    
    protected:
        void setArea(double a);
        void setPerimeter(double p);
            
    private:
        double area;
        double perimeter;
    };

    class Triangle : public Shape
    {
    public:
        Triangle(double edge1, double edge2, double edge3);
        
    private:
        double edge1;
        double edge2;
        double edge3;
    };

    class Rectangle : public Shape
    {
    public:
        Rectangle(double width, double height);
        
    private:
        double width;
        double height;
    };

    class Circle : public Shape
    {
    public:
        Circle(double radius, double pi);
        
    private:
        double radius;
        double pi;
    };

    Triangle::Triangle(double edge1, double edge2, double edge3){
        if(edge1 < 0 || edge2 < 0 || edge3 < 0){
            setArea(0);
            setPerimeter(0);
            return;
        }

        if(edge1 + edge2 < edge3 || edge2 + edge3 < edge1 || edge3 + edge1 < edge2){
            setArea(0);
            setPerimeter(0);
            return;
        }

        double s = (edge1 + edge2 + edge3) / 2;
        setArea(sqrt(s * (s - edge1) * (s - edge2) * (s - edge3)));
        setPerimeter(edge1 + edge2 + edge3);
    }

    Rectangle::Rectangle(double width, double height){
        if(width < 0 || height < 0){
            setArea(0);
            setPerimeter(0);
            return;
        }

        setArea(width * height);
        setPerimeter(width * 2 + height * 2);
    }

    Circle::Circle(double radius, double pi){
        if(radius < 0 || pi < 0){
            setArea(0);
            setPerimeter(0);
            return;
        }

        setArea(radius * radius * pi);
        setPerimeter(radius * 2 * pi);
    }
}
#endif


using namespace std;

namespace oj
{   
    void Shape::setArea(double a)
    {
        area = a;
    }

    void Shape::setPerimeter(double p)
    {
        perimeter = p;
    }

    double Shape::getArea()
    {
        return area;
    }

    double Shape::getPerimeter()
    {
        return perimeter;
    }
}


int main(void)
{   
    using namespace oj;

    string s;
    double a, b, c;
    double totalArea = 0.0, totalPerimeter = 0.0;

    while(cin >> s) {
        if(s == "Triangle") {
            cin >> a >> b >> c;
            Triangle T(a, b, c);
            totalArea += T.getArea();
            totalPerimeter += T.getPerimeter();
        }
        if(s == "Rectangle") {
            cin >> a >> b;
            Rectangle R(a, b);
            totalArea += R.getArea();
            totalPerimeter += R.getPerimeter();
        }
        if(s == "Circle") {
            cin >> a >> b;
            Circle C(a, b);
            totalArea += C.getArea();
            totalPerimeter += C.getPerimeter();
        }
    }

    cout << totalArea << endl;
    cout << totalPerimeter << endl;


    return 0;
}