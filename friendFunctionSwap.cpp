#include <iostream>
using namespace std;

class A;
class B
{
    private:
    int val2;
    
    public:
    void getdata(void)
    {
        val2 = 21;
    }
    void display(void)
    {
        cout<<"Value 2: "<<val2;
    }
    
    friend void exchange (B&, A&);
};

class A
{
    private:
    int val1;
    public:
    void get(void)
    {
        val1 = 12;
    }
    void disp(void)
    {
        cout<<"Value 1: "<<val1;
    }
    friend void exchange (B&, A&);
};

void exchange (B &x, A &y)
{
    int temp;
    temp = x.val2;
    x.val2 = y.val1;
    y.val1 = temp;
}

int main() {
	A abc;
	B bcd;
	abc.get();
	bcd.getdata();
	cout<<"Before exchange\n";
	abc.disp();
	bcd.display();
	exchange(bcd, abc);
	cout<<"After exchange\n";
	abc.disp();
	bcd.display();
	return 0;
}
