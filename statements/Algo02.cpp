/*  C++ Algorithms 2
    
    Write a function that removes K random elements from a std::vector as efficiently as you can. 
    The function should work in place, but does not need to preserve the order of elements.
*/

#include <iostream>
#include <vector>
#include <random>

void removeK(std::vector<int>& v, unsigned k)
{
    //Appartently with MingW the random_device is not properly implemented and it doesn't provide
    //  a random seed. So you will see the same sequence of numbers deleted all the time.
    std::random_device rd;
    std::default_random_engine rng(rd());
    
    for(int i=0; i<k; i++){
        std::uniform_int_distribution<int> randIndex(0, v.size() - 1);
        v.erase(v.begin() + randIndex(rng));
    }
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