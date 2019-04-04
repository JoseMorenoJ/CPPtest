/*  C++ Basics 5
    
    In the code below, change all C style type-casts to C++ static_cast, dynamic_cast, reinterpret_cast or const_cast, depending on the programmer intent
*/

#include <iostream>

class A
{
public:
    virtual void foo(A& a) { std::cout << "A::foo" << std::endl; }
};

class B: public A
{
public:
    void baz(B* b) 
    {
        if (!b)
            return;
        std::cout << "B::baz" << std::endl;
    }
};

void logPtr(int* c) { std::cout << std::hex << c << std::endl; }

void logClass(A* a)
{
    // is 'a' pointing to an object of class B?
    if (dynamic_cast<B*>(a) != nullptr)
        std::cout << "class B" << std::endl;
    else
        std::cout << "class A" << std::endl;
}

int main(int argc, char* argv[])
{
    const A* pa = new A();
    A* pb = new B();

    const_cast<A*>(pa)->foo(*pb);
    static_cast<B*>(pb)->baz( dynamic_cast<B*>( const_cast<A*>(pa) ) );

    logPtr( reinterpret_cast<int*>( const_cast<A*>(pa) ) );

    logClass((A*)pa);
    logClass(pb);

    delete pb;
    delete pa;

	return 0;
}
/* OUTPUT
before:
    A::foo
    B::baz
    0x1e6a50 //just an address
    class B
    class B
after:
    A::foo
    0x936a50 //random address
    class A
    class B
*/