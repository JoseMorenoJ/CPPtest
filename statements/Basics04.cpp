/*  C++ Basics 4
    
    Write a comment explaining the problem with the code below

    José Moreno 06 July 2019
*/

#include <iostream>

int& func(int i)
{
    int a = i + 3;
    // We are returning a local variable by reference.
    return a;
}

int g(int a)
{
    return a;
}
void callFunc(){
    func(0);
}
int main(int argc, char* argv[])
{
    int &i = func(5);
    // Here we happen to have still a value in i. 
    std::cout << i << " " << g(3) << std::endl;
    // And even if I call here func again, it will still have the value.
    func(10);
    std::cout << i << std::endl;

    // If we add a call of func() inside another function, the address of i, stops meaning anything.
    callFunc();
    std::cout << i << std::endl; //this prints 0. The memory stored in i has been wiped from the stack.

	return 0;
}