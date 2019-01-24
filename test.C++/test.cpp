#include <iostream>

using namespace std;


class Base
{
public:
    Base() { cout << "Base" << endl;}
    virtual ~Base() { cout << "~Base" << endl;}

};


class Derive : public Base
{
public:
    Derive() { cout << "Derive" << endl;}
    ~Derive() { cout << "~Derive" << endl;}
};


int main()
{
    Base* pBase = new Derive();

    delete pBase;

    return 0;
}

