#include <iostream>

#include <unistd.h>

using namespace std;


class Base
{
public:
    Base() {}
    virtual ~Base() {}
    
    void getPublic() {}
    int public_;
    
protected:
    void getProtected() {}
    int protected_;
    
private:
    void getPrivate() {}
    int private_;
};

class Derived : public Base
{
public:
    Derived() {}
    virtual ~Derived() {}
    
    void setPublic() {public_ = 1;}
    void setProtected() {protected_ = 1;}
    void setPrivate() {private_ = 1;}          // error: ‘int Base::private_’ is private
};


// 1. 公有继承(public)
// 公有继承的特点是基类的公有成员和保护成员作为派生类的成员时，它们都保持原有的状态，而基类的私有成员仍然是私有的，不能被这个派生类的子类所访问。


int main()
{
    Derived derived;
    
    // derived.public_ = 1;
    // derived.protected_ = 1;        // error: ‘int Base::protected_’ is protected
    // derived.private_ = 1;          // error: ‘int Base::private_’ is private
    // 
    // derived.getPublic();
    // derived.getProtected();        // error: ‘void Base::getProtected()’ is protected
    // derived.getPrivate();          // error: ‘void Base::getPrivate()’ is private
    
    return 0;
}

