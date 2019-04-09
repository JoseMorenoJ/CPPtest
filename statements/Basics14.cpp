/*  C++ Basics 14
    
    Write a comment to explain the output
*/

#include <iostream>

class A
{
public:
    void baz()              { std::cout << "Calling A::baz() " << std::endl; }
	//A::bar() will be overriden by a derived class when called
    virtual void bar()      { std::cout << "Calling A::bar() " << std::endl; }
};

class B : public A
{
public:
    void baz()              { std::cout << "Calling B::baz() " << std::endl; }
	//B::bar() can override A::bar() cause it is a virtual function
    virtual void bar()      { std::cout << "Calling B::bar() " << std::endl; }
};

void funcCaller(A* someA)
{
	if (someA)
	{
		//A::baz() will always be called cause is not a virtual function
		someA->baz();
		//B::bar() might be called when a &B given as a parameter of funcCaller()
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
/* output:
	Calling A::baz()
	Calling A::bar()
	Calling A::baz()
	Calling B::bar()
*/