/*  C++ Basics 3
    
    Fix the problem with the code below
    Write a comment to explain the output

    José Moreno 06 July 2019
*/

#include <iostream>

class A
{
public:
    A(): m_AData(new int()) { std::cout << "Calling A::A() " << std::endl; }
    // Without this method being virtual, instances of B that are not specifically in a B type variable,
    //  would not be destroyed.
    virtual ~A()            { std::cout << "Calling A::~A() " << std::endl; delete m_AData; }
private:
    int* m_AData;
};
class B : public A
{
public:
    B(): m_BData(new int()) { std::cout << "Calling B::B() " << std::endl;}
    ~B()                    { std::cout << "Calling B::~B() " << std::endl; delete m_BData; }
private:
    int* m_BData;
};

int main(int argc, char* argv[])
{
    A* someA = new B(); //We know someA is pointing a B object.
    delete someA; //But without the virtual destructor in A, this only calls ~A();
    B b;

	return 0;
}
/* 1st OUTPUT:
Calling A::A()
Calling B::B()
Calling A::~A() --> It only calls ~A(). m_BData is not deleted. Memory leek.
Calling A::A()
Calling B::B()
Calling B::~B()
Calling A::~A() 

2nd OUTPUT:
Calling A::A()
Calling B::B()
Calling B::~B() --> Now it calls also ~B().
Calling A::~A()
Calling A::A()
Calling B::B()
Calling B::~B()
Calling A::~A()

*/