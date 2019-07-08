/*  C++ Basics 14
    
    Write a comment to explain the output

	--> First, we pass to funcCaller an A object so it calls both A::bar() and A::baz().
	--> Second, we pass a B object but funcCaller uses an A*. This A* pointer will call A::baz() and 
	--> B::bar().
	--> Why B::bar() and not A::baz()? Because bar() is defined as virtual in A. Converting the B object 
	--> to an A object will use the virtual methods defined in the derived class. B.

    José Moreno 06 July 2019
*/

#include <iostream>

class A
{
public:
    void baz()      { std::cout << "Calling A::baz() " << std::endl; }
    virtual void bar()      { std::cout << "Calling A::bar() " << std::endl; }
};

class B : public A
{
public:
    void baz()      { std::cout << "Calling B::baz() " << std::endl; }
    virtual void bar()      { std::cout << "Calling B::bar() " << std::endl; }
};

void funcCaller(A* someA)
{
	if (someA)
	{
		someA->baz();
		someA->bar();
	}
}

int main(int argc, char* argv[])
{
	A someA;
	B someB;
	
	funcCaller(&someA);
	funcCaller(&someB);

	return 0;
}

/* OUTPUT:
Calling A::baz()
Calling A::bar()
Calling A::baz()
Calling B::bar()
*/