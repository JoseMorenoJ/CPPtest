/*  C++ Basics 11
    
    Change the definition of class TypePrinter in such a way that it would be impossible for a descendant class to not define the method printClass

    --> This is by definition the pure virtual method. Add '= 0' to the virtual method.

    José Moreno 06 July 2019
*/

#include <iostream>

class TypePrinter
{
public:
    //
    virtual void printClass() = 0; // Children need to override this so it prints the correct class name
};

class A: public TypePrinter
{
    public:
    virtual void printClass(){
        std::cout << "A::printClass()" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    A a;
    a.printClass();

	return 0;
}