/*
Program to set complex numbers, add, subtract, multiply and divide them, find magnitude, phase and convert from polar to rectangular form
Author: Jash Mota (jash101)
Purpose: Complex number operations

The following code helps understand:
>>declare and define functions
>>define a class
>>declare class objects
>>using library functions
>>accessing private class entities using public functions
>>declarating functions with user defined returntype
>>Good programming style and standard for C++, C and Objective C
*/
//pre processor directives
#include <iostream>
#include <cmath>
#define PI 3.14159265//Simply means, "Hey Computer! Replace PI with 3.141... everywhere, because I'm too lazy to type it everytime"

using namespace std;

class Complex
{
    //Declaring the instance variables
    //value will be passed dynamically through the setX(double) funtions
  private:
    double real;
    double imag;

    /*
    declaration of functions used to manipulate the variables
    variables being private entities, can only be manipulated out of the class scope using the public functions of this class
    function names pretty much define the operation they'll do over real and imag
    ------------------------------------------------------------------------------------------------------------------------------------
    Function Declaration Syntax: returntype functionname (input1, input2,...inputn);
    ____________________________________________________________________________________________________________________________________
    */
  public:
    void setReal(double);
    void setImag(double);
    double getReal();
    double getImag();
    double magnitude();
    double phase();
    void display();
    //The following functions have a user-defined returntype, that is, they return a value of the type Complex
    //These functions interpret the inputs as complex entities and spit out the same
    Complex add(Complex, Complex);
    Complex sub(Complex, Complex);
    Complex multiply(Complex, Complex);
    Complex divide(Complex, Complex);
    Complex conjugate();
    Complex p2r(double, double);
};

//Function Definitions
/*
____________________________________________________________________________________________________________________________________
Function Definition Syntax: returntype classname::functionname (input1, input2,...., inputn)
{
    //operation commands
}
____________________________________________________________________________________________________________________________________
NOTICE: NO SEMICOLONS IN THE DEFINITION SYNTAX
==================================================================================================================
RULE OF THUMB: WHEN A FUNCTION IS FOLLOWED BY CURLY BRACES, YOU DONOT PUT A SEMICOLON
*/
void Complex::setReal(double rn)
{
    real = rn;
}
void Complex::setImag(double in)
{
    imag = in;
}

double Complex::getReal()
{
    return real;
}
double Complex::getImag()
{
    return imag;
}
void Complex::display()
{
    if (getImag() < 0)
    {
        cout << "Complex Number is: \t" << getReal() << "-i " << -getImag() << endl;
    }
    else
    {
        cout << "Complex Number is: \t" << getReal() << "+i " << getImag() << endl;
    }
}

Complex Complex::add(Complex cn1, Complex cn2)
{
    Complex result;
    result.real = cn1.real + cn2.real;
    result.imag = cn1.imag + cn2.imag;
    return result;
}

double Complex::magnitude()
{
    double result;
    result = hypot(real, imag); //hypot function is imported from the cmath library and calculates the magnitude
    return result;
}

double Complex::phase()
{
    return ((atan2(imag, real) * 180) / PI);
}

Complex Complex::conjugate()
{
    Complex result;
    result.real = real;
    result.imag = -imag;
    return result;
}

Complex Complex::multiply(Complex cn1, Complex cn2)
{
    Complex result;
    result.real = cn1.real * cn2.real - cn1.imag * cn2.imag;
    result.imag = cn1.real * cn2.imag + cn1.imag * cn2.real;
    return result;
}
Complex Complex::p2r(double mag, double theta)
{
    Complex result;
    result.real = mag * cos(theta * PI / 180);
    result.imag = mag * sin(theta * PI / 180);
    return result;
}
Complex Complex::divide(Complex cn1, Complex cn2)
{
    double mag1, mag2;
    double ph1, ph2;
    mag1 = cn1.magnitude();
    mag2 = cn2.magnitude();
    ph1 = cn1.phase();
    ph2 = cn2.phase();
    Complex result;
    result = p2r(mag1 / mag2, ph1 - ph2);
    return result;
}

int main()
{
    Complex num1;
    Complex num2;

    num1.display();
    num1.setReal(1.0);
    num1.setImag(1.0);
    num1.display();

    num2.setReal(2.0);
    num2.setImag(-2.0);
    num2.display();
    Complex result, conjugate, product, rectangular, division;
    result = num1.add(num1, num2);
    result.display();
    conjugate = result.conjugate();
    conjugate.display();
    product = result.multiply(conjugate, result);
    product.display();
    cout << "Magnitude of Complex Number:" << product.magnitude() << endl;
    cout << "Phase of Complex Number:" << product.phase() << endl;
    rectangular = rectangular.p2r(product.magnitude(), product.phase());
    rectangular.display();
    division = division.divide(num1, num2);
    division.display();
    return 0;
}
