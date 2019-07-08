/*  C++ Basics 9
    
    In the code below change the auto in front of f and g to the most specific possible concrete types

    José Moreno 06 July 2019
*/

#include <iostream>
#include <functional> //std::function

int mulBy2(float a)
{
    return (int) (a*a);
}

int main(int argc, char* argv[])
{
    int (*f)(float) = mulBy2;
    float c = 3.f;
    std::function<float(float)> g = [=](float a) { return a * c; }; // float (*)(float): this won't work
    //We cannot get the type of a lambda expression, it is a unique type that only the compiler knows.
    //  That is why we would use auto or like now, wrap it in a std::function.

    std::cout << f(2.0f) << " " << g(2.0f) << std::endl;

	return 0;
}