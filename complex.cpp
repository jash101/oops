#include <iostream>
#include <math.h>
using namespace std;

class complex
{
    double real, imag;

  public:
    complex()
    {
    }
    complex(double real, double imag)
    {
        setr(real);
        seti(imag);
    };
    void set(double, double);
    void setr(double);
    void seti(double);
    void disp();
    double mag();

    double getr()
    {
        return real;
    }
    double geti()
    {
        return imag;
    }

    complex operator-(complex b)
    {
        complex result;
        double r = real - b.getr();
        double i = imag - b.geti();
        result.set(r, i);
        return result;
    }
};
void complex::set(double r, double i)
{
    real = r;
    imag = i;
}
complex operator+(complex a, complex b)
{
    complex result;
    double r = a.getr() + b.getr();
    double i = a.geti() + b.geti();
    result.set(r, i);
    return result;
}

complex operator*(complex a, complex b)
{
    complex result;
    double r = a.getr() * b.getr() - a.geti() * b.geti();
    double i = a.getr() * b.geti() + a.geti() * b.getr();
    result.set(r, i);
    return result;
}


//NEED TO REPEAT ABOVE FOR OTHER MATHTEMATICAL OPERATIONS

int main()
{
    complex number;
    number.setr(5);
    number.seti(4);
    number.disp();
    complex two(3, 4);
    two.disp();
    complex r = number - two;
    r.disp();
    cout<<endl<<"Mag: "<<number.mag();
    return 0;
}
void complex::setr(double real)
{
    this->real = real;
}
void complex::seti(double imag)
{
    this->imag = imag;
}
void complex::disp()
{
    cout << "REAL: " << real << " IMAG: " << imag;
}

double complex::mag()
{
    return (sqrt(real*real + imag*imag));
}