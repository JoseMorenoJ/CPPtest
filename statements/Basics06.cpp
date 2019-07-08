/*  C++ Basics 6
    
    Fix the problem with the code below

    José Moreno 06 July 2019
*/

#include <iostream>

void printValuePlus2(int *p)
{
    //It is using the pointer without dereferencing. It prints the address, not the int.
    //Dereferencing it should fix it.
    std::cout << *p + 2 << std::endl;
}

int main(int argc, char* argv[])
{
    int a = 5;
    printValuePlus2(&a); // 7

	return 0;
}