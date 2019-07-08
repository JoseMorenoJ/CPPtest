/*  C++ Basics 7
    
    Rewrite the implementation of the class Flags so it is more memory efficient for the given value of MAX_FLAGS
	(without using any external container classes from the STL).
    Document any limitations this imposes on other possible MAX_FLAGS values.

    --> Because MAX_FLAGS is 32, same number of bits in an int I will redefine the array of bool in a single int.
    --> Also redefine the operations getFlag() and setFlag().
    --> This implementation should use less memory but:
    -->     if we need to increase the number of MAX_FLAGS, we cannot use the int anymore.
    -->     it might no be so easy to maintain.
    -->     it is platform dependent now, not always an int is 32 bits.

    José Moreno 06 July 2019
*/

#include <iostream>
#include <random>

class Flags
{
public:
    static const int MAX_FLAGS = 32;

    Flags(): m_flags(0) {} //we initialize it to 0;

    bool getFlag(int i)         
    { 
        unsigned int mask = (1 << i); //a '1' bit in the ith position
        return mask & m_flags;
    }
    void setFlag(int i, bool v) 
    { 
        std::cout << i << std::endl; //debug
        unsigned int mask = (1 << i); 
        if (v){
            m_flags = m_flags | mask; //add the '1' of the mask
        }
        else{
            m_flags = m_flags & ~mask; //reset the '1' of the mask
        }
    }

private:
    unsigned int m_flags;
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