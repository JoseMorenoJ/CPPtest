/*  C++ Basics 4
    
    Write a comment explaining the problem with the code below
*/

#include <iostream>

int& func(int i)
{
    int a = i + 3;
    return a;
}

int g(int a)
{
    return a;
}

int main(int argc, char* argv[])
{
    // i is getting the reference of a variable out of scope.
    int &i = func(5);
    // Therefor, this might print anything.
    std::cout << i << " " << g(3) << std::endl;

	return 0;
}