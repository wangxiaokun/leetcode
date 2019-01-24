#include <iostream>

#include <unistd.h>

using namespace std;


class Base
{
public:
    Base() {}
    ~Base() {}
    
    void getPublic() {}
    int public_;
    
protected:
    void getProtected() {}
    int protected_;
    
private:
    void getPrivate() {}
    int private_;
};

int main()
{
    Base base;
    
    base.public_ = 1;
    base.protected_ = 1;        // error: ‘int Base::protected_’ is protected
    base.private_ = 1;          // error: ‘int Base::private_’ is private

    base.getPublic();
    base.getProtected();        // error: ‘void Base::getProtected()’ is protected
    base.getPrivate();          // error: ‘void Base::getPrivate()’ is private
    
    return 0;
}

