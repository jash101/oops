#include<iostream>
using namespace std;
class SHAPE
{
public:
    virtual void area()=0;
};
class Rectangle:public SHAPE
{
public:
    float l,b;
    void input();
    void area();
};
void Rectangle::input()
{
    cout<<"Enter length of rectangle : ";
    cin>>l;
    cout<<"Enter breadth of rectangle : ";
    cin>>b;
}
void Rectangle::area()
{
    float area=l*b;
    cout<<"\nArea of rectangle is : "<<area;
}
class Circle:public SHAPE
{
public:
    float r;
    void input();
    void area();
};
void Circle::input()
{
    cout<<"\nEnter radius of circle : ";
    cin>>r;
}
void Circle::area()
{
    float area=3.14*r*r;
    cout<<"\nArea of circle is : "<<area;
}
int main()
{
    Rectangle obj1;
    Circle obj2;
    obj1.input();
    obj1.area();
    obj2.input();
    obj2.area();
    return 0;
}
