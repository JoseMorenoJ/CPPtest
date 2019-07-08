/*  C++ Advanced 4
    
    Explain the result of running the program. Explain how its execution will end.
    --> The comma operator will execute the left side before evaluating the right side.
    --> This means, the while loop is considering "++c" as loop condition.
    --> Since ++c is returning an int. It will only be false when it gets to 0.
    -->    So, it will print all the numbers until the maximum value of the int.
    -->    ++c when c is already the max value will give turn around the value to the lowest value.
    -->    Then ++c will keep adding 1 until we get to 0, evaluate false, get out of the loop.

    José Moreno 06 July 2019
*/

#include <iostream>

int main(int argc, char* argv[])
{
    int c = 0;
    while (c < 5, ++c)
        std::cout << c << std::endl;

	return 0;
}