#include <iostream>
#include <memory>

using namespace std;


class Test
{
public:
    Test() {cout<<"Test"<<endl;}
    ~Test() {cout<<"~Test"<<endl;}

    int a;
    int b;
};

int main()
{
    shared_ptr<Test> t = make_shared<Test>();


    return 0;
}


