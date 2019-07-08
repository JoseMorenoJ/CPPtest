/*  C++ Basics 12
    
    Fix the macro SQUARE to return the intended result in all cases.
    How can you make the program run twice as fast while still producing the same result?

    José Moreno 06 July 2019
*/

#include <iostream>
#include <chrono>
#include <thread>

#define SQUARE(x) (x) * (x) //We just need to add some parenthesis to avoid the operator hierarchy 
                            //  chagning the order of the operations.

int slowThink()
{
	// This puts the thread to sleep for 5 seconds to simulate
	// a heavy computation that cannot be optimized
	// Do not change anything here!
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 42;
}

int main(int argc, char* argv[])
{
    std::cout << SQUARE(slowThink() + 8) << std::endl;
	
	return 0;
}