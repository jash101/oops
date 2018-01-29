//pre processor directive
#include <iostream>
#include <cmath>
#define PI 3.14159265

using namespace std;
class ComplexNumber
{
//fields instance variable
private:
double realNumber;
double imagNumber;
//declaration
public:
void setRealNumber(double);
void setImagNumber(double);
double getRealNumber();
double getImagNumber();
void display();
ComplexNumber add(ComplexNumber, ComplexNumber);
ComplexNumber sub(ComplexNumber,ComplexNumber);
ComplexNumber multiply(ComplexNumber,ComplexNumber);
ComplexNumber divide(ComplexNumber,ComplexNumber);
ComplexNumber conjugate();
double magnitude();
double phase();
ComplexNumber p2r(double, double);
};

void ComplexNumber::setRealNumber(double rn)
{
realNumber=rn;
}
void ComplexNumber::setImagNumber(double in)
{
imagNumber=in;
}

double ComplexNumber::getRealNumber()
{
return realNumber;
}
double ComplexNumber::getImagNumber()
{
return imagNumber;
}
void ComplexNumber::display()
{
if (getImagNumber()<0)
{
cout<<"Complex Number is: \t"<<getRealNumber()<<"-j"<<-getImagNumber()<<endl;
}
else
{
cout<<"Complex Number is: \t"<<getRealNumber()<<"+j"<<getImagNumber()<<endl;
}
}

ComplexNumber ComplexNumber::add (ComplexNumber cn1, ComplexNumber cn2)
{
ComplexNumber result;
result.realNumber=cn1.realNumber+cn2.realNumber;
result.imagNumber=cn1.imagNumber+cn2.imagNumber;
return result;
}
double ComplexNumber:: magnitude()
{
double result;
result=hypot(realNumber,imagNumber);
return result;
}
double ComplexNumber:: phase()
{
return ((atan2(imagNumber,realNumber)*180)/PI);
}

ComplexNumber ComplexNumber::conjugate()
{
ComplexNumber result;
result.realNumber=realNumber;
result.imagNumber=-imagNumber;
return result;
}

ComplexNumber ComplexNumber::multiply (ComplexNumber cn1,ComplexNumber cn2)
{
ComplexNumber result;
result.realNumber=cn1.realNumber*cn2.realNumber-cn1.imagNumber*cn2.imagNumber;
result.imagNumber=cn1.realNumber*cn2.imagNumber+cn1.imagNumber*cn2.realNumber;
return result;
}
ComplexNumber ComplexNumber::p2r(double mag, double theta)
{
ComplexNumber result;
result.realNumber=mag*cos(theta*PI/180);
result.imagNumber=mag*sin(theta*PI/180);
return result;
}
ComplexNumber ComplexNumber:: divide(ComplexNumber cn1, ComplexNumber cn2)
{
double mag1, mag2;
double ph1,ph2;
mag1=cn1.magnitude();
mag2=cn2.magnitude();
ph1=cn1.phase();
ph2=cn2.phase();
ComplexNumber result;
result=p2r(mag1/mag2,ph1-ph2);
return result;
}

int main()
{
ComplexNumber obj;
ComplexNumber obj1;

obj.display();
obj.setRealNumber(1.0);
obj.setImagNumber(1.0);
obj.display();
obj1.setRealNumber(2.0);
obj1.setImagNumber(-2.0);
obj1.display();
ComplexNumber res,conj,prod,rect,div;
res=obj.add(obj,obj1);
res.display();
conj=res.conjugate();
conj.display();
prod=res.multiply(conj,res);
prod.display();
cout<<"Magnitude of Complex Number:"<<prod.magnitude()<<endl;
cout<<"Phase of Complex Number:"<<prod.phase()<<endl;
rect=rect.p2r(prod.magnitude(),prod.phase());
rect.display();
div=div.divide(obj,obj1);
div.display();
return 0;
}
