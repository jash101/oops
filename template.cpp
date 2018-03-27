//Template Functions
/*
Date: March 27, 2018
Author: Jash Mota
*/
#include <iostream>

using namespace std;

template <class J>//template keyword
J test(J a)//function definition
{
    return a;
}

int main()
{
    int a = 5;
    float b = 2.3;

    cout<<test<int>(a);//func call for int dtype
    cout<<endl;
    cout<<test<float>(b);//func call for float dtype
}
