/*
Written by: Yash Shetye
Problem Statement: Program to add, subtract, multiply and divide two numbers using class template
*/
#include<iostream>
using namespace std;
template<class T>class Sample
{
    T a;
    T b;
public:
    Sample(T n1,T n2)
    {
        a=n1;
        b=n2;
    }
    void display()
    {
        cout<<"\nAddition : "<<add();
        cout<<"\nSubtraction : "<<sub();
        cout<<"\nMultiplication : "<<mul();
        cout<<"\nDivision : "<<div();
    }
    T add()
    {
        return a+b;
    }
    T sub()
    {
        return a-b;
    }
    T mul()
    {
        return a*b;
    }
    T div()
    {
        return a/b;
    }
};
int main()
{
    Sample<int>s1(4,2);
    s1.display();
    return 0;
}
