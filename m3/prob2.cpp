/*
Written by: Yash Shetye
Problem Statement: Program to swap data using function templates without using third variable
*/
#include<iostream>
using namespace std;
template<class T>
void swapp(T& a, T& b)//name changed to swapp coz swap is a keyword in the library
{
    a=a+b;
    b=a-b;
    a=a-b;
}
int main()
{
    int x1=8;
    int x2=4;
    cout<<"\Before swapping \nx1= "<<x1<<"\nx2= "<<x2;
    swapp(x1,x2);
    cout<<"\nAfter swapping \nx1= "<<x1<<"\nx2= "<<x2;
    return 0;
}
