/*  C++ Basics 2
    
    Write code that will allocate and then delete an array of 10 arrays of 8 ints each

    José Moreno 06 July 2019
*/

#include <iostream>

#include <vector>

int main(int argc, char* argv[])
{
    // Allocate array of arrays
    //This way we will allocate an std::vector which, in the end, is an array.
    auto pArray = new std::vector< std::vector<int> >(10, std::vector<int>(8));

    //This would be a more traditional array definition
    int** array = new int*[10];
    for (int i=0; i<10; i++)
    {
        array[i] = new int[8];
    }

    // Delete it
    //To delete the vector we just call 'delete', the compiler will take care of deleting every element.
    delete pArray;

    //To delete the more 'traditional array' we have to call element for element.
    for (int i=0; i<10; i++)
    {
        delete [] array[i];
    }
    delete [] array;

	return 0;
}