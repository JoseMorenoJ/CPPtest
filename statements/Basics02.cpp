/*  C++ Basics 2
    
    Write code that will allocate and then delete an array of 10 arrays of 8 ints each
*/

#include <iostream>

int main(int argc, char* argv[])
{
    // Allocate array of arrays
    int **array = new int*[10];

    for (int i=0; i<10; i++){
        array[i] = new int[8];
        for(int j=0; j<8; j++){
            array[i][j] = 10*i + j;
        }
    }

    // Delete it
    for (int i=0; i<10; i++)
        delete[] array[i];
    delete[] array;

	return 0;
}