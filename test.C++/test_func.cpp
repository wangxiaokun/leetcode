#include <iostream>
using namespace std;

class Base
{
public:
    Base() {}
    ~Base() {}
    
    void func() {cout<<"Base func"<<endl;}
};

class Derived: public Base
{
public:
    Derived() {}
    ~Derived() {}
    
    void func() 
    {
        Base::func();
        cout<<"Derived func"<<endl;
    }
};

int main()
{
    Derived* pDerived = new Derived();
    pDerived->func();
    
    cin.get();
    return 0;
}

