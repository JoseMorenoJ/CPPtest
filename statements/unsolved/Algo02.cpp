/*  C++ Algorithms 2
    
    Write a function that removes K random elements from a std::vector as efficiently as you can. 
    The function should work in place, but does not need to preserve the order of elements.
*/

#include <iostream>
#include <vector>

void removeK(std::vector<int>& v, unsigned k)
{
    // This vector has it coming...
}

int main(int argc, char* argv[])
{
    std::vector<int> arr;
    for (int i = 0; i < 50; ++i)
        arr.push_back(i);

    removeK(arr, 5);

    for (auto i: arr)
        std::cout << i << std::endl;

	return 0;
}