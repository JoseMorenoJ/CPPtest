/*  C++ Basics 1
    
    Unify the definitions of the two sumArray functions into one

    José Moreno 06 July 2019
*/

#include <iostream>
//We will use a template to unify the functions:
template <typename T>
int sumArray(T *a, int count)
{
    int sum = 0;
    for (int i = 0; i < count; ++i)
        sum += a[i];
    return sum;
}

//I was using Visual Code to work in the questions and compiling from the terminal didn't allow me to use 'void main()'
int main(int argc, char* argv[])
{
    int a[5] = { 1, 2, 3, 4, 5 };
    float f[5] = { 0.f, 1.f, 2.f, 3.f, 4.f };

    std::cout << sumArray(a, 5) << " " << sumArray(f, 5) << std::endl;
}