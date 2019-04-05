/*  C++ Algorithms 1
    
    Consider the following sequence : 0,1,1,2,3,5,8,13,21,34,55,89,144...
    Write an iterative function to return the nth element of the sequence.

*/

#include <iostream>

int fibonacci(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n > 2){
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int sequence(unsigned n)
{
    return fibonacci(n);
}

int main(int argc, char* argv[])
{
    std::cout << sequence(25) << std::endl;

	return 0;
}