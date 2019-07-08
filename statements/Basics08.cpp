/*  C++ Basics 8
    
    Write a comment explaining the output of the code below
    
    --> The && operand will not evaluate the right side if the left side is already false.
    --> The || operand will not evaluate the right side if the left side is aleady true.

    José Moreno 06 July 2019
*/

#include <iostream>

bool func0() { std::cout << "Func0" << std::endl ; return false; }
bool func1() { std::cout << "Func1" << std::endl ; return true; }

int main(int argc, char* argv[])
{
    if (func0() && func1()) //Func0 --> false. Skips the other side of the && operand.
    {
        std::cout << "Main0";
    }

    if (func1() || func0()) //Func1 --> true. It doesn't check the rest of the conditional statement
    {
        std::cout << "Main1"; //Main1, just printed that.
    }

	return 0;
}
/*
OUTPUT:
Func0
Func1
Main1
 */