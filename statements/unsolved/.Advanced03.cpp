/*  C++ Advanced 3
    
    You are debugging a program using your usual debugger and it always crashes on the same memory address because it has been corrupted. 
    The problem is that you don’t know when it could happen and you don’t know what line of source code is causing the crash 
    (And you can’t check all the code... That would take too much time). 
    
    Write a comment explaining the steps you will take in order to find the cause of the problem.
*/

#include <iostream>

int main(int argc, char* argv[])
{
    *(int *) 42 = 0;

	return 0;
}