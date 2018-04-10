/*
Written by: Yash Shetye
Problem Statement: Create a base class shape. Use this class to store two double type values that could be
used to compute area of figures. Derive two specific classes called triangle and
rectangle from the base shape. Add to the base a member function getdata() to initialize
base class data member and another member function display_area() to compute and
display the area of figures. Make display_area() as a virtual function and redefine it in the
derived class to suit their requirements.
*/
#include<iostream>
using namespace std;
class Shape
{
public:
    double b,h;
    void getdata();
    virtual void display_area() {}
};
void Shape::getdata()
{
    b=9.4;
    h=5.7;
}
class Triangle: public Shape
{
public:
    void display_area();
};
void Triangle::display_area()
{
    double area=0.5*b*h;
    cout<<"\nArea of triangle is : "<<area;
}
class Rectangle: public Shape
{
public:
    void display_area();
};
void Rectangle::display_area()
{
    double area=b*h;
    cout<<"\nArea of rectangle is :"<<area;
}
int main()
{
    Triangle obj1;
    Rectangle obj2;
    obj1.getdata();
    obj1.display_area();
    obj2.getdata();
    obj2.display_area();
    return 0;
}
