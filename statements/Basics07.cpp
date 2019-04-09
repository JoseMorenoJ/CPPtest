/*  C++ Basics 7
    
    Rewrite the implementation of the class Flags so it is more memory efficient for the given value of MAX_FLAGS
	(without using any external container classes from the STL).
    Document any limitations this imposes on other possible MAX_FLAGS values.
*/

#include <iostream>
#include <random>

class Flags
{
public:
    static const int MAX_FLAGS = 32;

    Flags():_flags(0) {}

    bool getFlag(int i) { 
        unsigned int mask = (1 << i); //a '1' bit in the ith position
        return mask & _flags;
    }
    void setFlag(int i, bool v) { 
        std::cout << i << std::endl;
        unsigned int mask = (1 << i);
        _flags = _flags | mask; //add the '1' of the mask
        }
private:
    unsigned int _flags; //each bit is a flag
};


int main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> randIndex(0, Flags::MAX_FLAGS - 1);

    Flags flags;
    flags.setFlag(randIndex(rng), true);
    flags.setFlag(randIndex(rng), true);

    for (int i = 0; i < Flags::MAX_FLAGS; ++i)
    {
        std::cout << i << "->" << flags.getFlag(i) << std::endl;
    }

	return 0;
}