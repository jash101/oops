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
