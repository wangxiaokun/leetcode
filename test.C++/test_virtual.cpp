#include <iostream>
using namespace std;

class Base
{
//public:
private:
    virtual void func() {cout<<"Base virtual func"<<endl;}
};

class Derived: public Base
{
//private:
public:
    virtual void func() {cout<<"Derived virtual func"<<endl;}
};

int main()
{
    Base* pBase = new Derived();
    pBase->func();
    cin.get();
    return 0;
}

