#include <iostream>
#include <cstring>
using namespace std;

class flight
{
    //Definition of private members
    int num;//flight name
    string dest;
    float dist;
    float fuel;
    void calfuel(float);

public:
    void feedinfo(int, string, float);
    void showinfo();
};

//Calculates fuels and stores in the fuel var in flight class; does not return a val
void flight::calfuel(float dist)
{
    (dist<=1000)?fuel = 500:((dist > 1000 && dist <=2000)?fuel = 1100:fuel = 2200);
}

//Takes in info provided by the user and stores in the class members; Does not return a val
void flight::feedinfo(int number, string destination, float distance)
{
    num = number;
    dest = destination;
    dist = distance;
    calfuel(dist);
}

//Display the members of the class flight when requested
void flight::showinfo()
{
    cout<<"\nShowing Flight Information for Flight Number: "<<num;
    cout<<"\nThe Flight Lands At: "<<dest;
    cout<<"\nThe Distance Of Flight From The Source To "<<dest<<" is: "<<dist;
    cout<<"\nTo Complete The Journey Successfully, Flight Would Require "<<fuel<<" Units Of Fuel";
}

int main()
{
    int number;
    string destination;
    float distance;
    cout<<"\nWelcome To Jash's Flight Interface";
    cout<<"\n-----------------------------------------------------------------------------";
    cout<<"\nEnter The Flight Number: ";
    cin>>number;
    cout<<"\nAlright...\nEnter Destination: ";
    cin>>destination;
    cout<<"\n That's a Nice Place!\nWhat's The Distance From Source? ";
    cin>>distance;

    flight data;
    data.feedinfo(number, destination, distance);

    cout<<"\nNow running the showinfo() function...";
    data.showinfo();
    int a;
    cin>>a;


    return 0;
}
