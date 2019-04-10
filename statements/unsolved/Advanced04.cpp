/*  C++ Advanced 4
    
    Explain the result of running the program. Explain how its execution will end.
*/

#include <iostream>

int main(int argc, char* argv[])
{
    int c = 0;
    while (c < 5, ++c)
        std::cout << c << std::endl;

	return 0;
}