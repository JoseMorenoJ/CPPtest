/*  C++ Basics 5
    
    In the code below, change all C style type-casts to C++ static_cast, dynamic_cast, reinterpret_cast or const_cast, depending on the programmer intent

    José Moreno 06 July 2019
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
    if (dynamic_cast<B*>(a) != nullptr) //to be sure wether 'a' is a B object or not.
        std::cout << "class B" << std::endl;
    else
        std::cout << "class A" << std::endl;
}

int main(int argc, char* argv[])
{
    const A* pa = new A();
    A* pb = new B();

    const_cast<A*>(pa)->foo(*pb); //We need to 'lose' the const to make that call.
    static_cast<B*>(pb)->baz(dynamic_cast<B*>(const_cast<A*>(pa))); 
                                    //1st, static_cast, we know it is a B*
                                    //2nd, dynamic_cast, to make the call of B if it is a B object
                                    //3rd, const_cast, in order to use the dynamic_cast we want to lose the const


    logPtr(reinterpret_cast<int*>(const_cast<A*>(pa))); //reinterpret to cast A* to int* which are not related classes
                                                        //const_cast to be able to use the reinterpret_cast

    logClass(const_cast<A*>(pa)); //Again, const_cast to be able to use the function.
    logClass(pb);

    delete pb;
    delete pa;

	return 0;
}