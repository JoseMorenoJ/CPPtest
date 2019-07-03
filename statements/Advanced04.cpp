/*  C++ Advanced 4
    
    Explain the result of running the program. Explain how its execution will end.
*/

#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
    int c = 0;

    //it is executing "c < 5" and then evaluating "++c" which will always be true.

    while (c < 5, ++c)
        std::cout << c << std::endl;

    //It will arrive to the maximum integuer possible (2147483647) and then ++c will return -2147483646.
    //  After this, it will add 1 by 1 until it reaches 0, thus, false.

	return 0;
}