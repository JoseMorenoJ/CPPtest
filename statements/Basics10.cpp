/*  C++ Basics 10
    
    Fix the problem with the class in the use case below.
    Write a comment about what methods are missing from the class definition if it needs to correctly handle all possible cases with optimal performance.
	Consider you're compiling in post C++11 when writing your answer.

    --> RULE OF 3:
    --> The compiler will define by default the copy constructor, the assignment operator and the destructor.
    --> In our case, we should redefine a copy constructor to avoid a shallow copy. Right now, we will try to 
    -->    delete twice the same content.
    -->    FunArray (const FunArray &f) { --our definition-- }
    --> The assignment operator will be redefine in a similar manner.
    -->    FunArray& FunArray::operator=(const FunArray &f) { --our definition-- }

    --> RULE OF 5:
    --> Since C++11 we have move operations so we would need to redefine aswell the move constructor and 
    -->    the move assignment operator.
    --> FunArray(FunArray &&f){ --redefine using some std::move operations-- }
    --> FunArray& FunArray::operator=(FunArray &&f){ --redefine using some std::move operations-- }

    José Moreno 06 July 2019
*/

#include <iostream>
#include <random>

class FunArray
{
public:
    //I will define a copy constructor so the program runs without crashing.
    FunArray(): m_Size(0){}
    //you need to redefine the copy constructor
    FunArray(const FunArray &f):m_Data(new uint8_t[f.m_Size]), m_Size(f.m_Size) {
        for (int i = 0; i < m_Size; ++i)
            ((uint8_t* )m_Data)[i] = ((uint8_t*)f.GetArray())[i];
    };
    //For the copy constructor definition.
    void* GetArray() const {return this->m_Data;}

    ~FunArray() { delete[] m_Data; }

    void GenerateData(int dataSize)
    {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<unsigned short> randData(std::numeric_limits<uint8_t>::min(), std::numeric_limits<uint8_t>::max());

        m_Data = new uint8_t[dataSize];
        for (int i = 0; i < dataSize; ++i)
            ((uint8_t *)m_Data)[i] = (uint8_t)randData(rng);
    }

    void Fun() { /* Do fun stuff */ }
private:
    void* m_Data;
    size_t m_Size; //for the copy constructor definition
};

int main(int argc, char* argv[])
{
    FunArray a;
    a.GenerateData(42);
    a.Fun();

    FunArray* b = new FunArray(a); //Here we use the copy constructor. Shallow copy.
    b->Fun();
    delete b; //This will delete the data pointed by m_Data.

	return 0; 
} //Here we will destroy all our objects, destroying again m_Data.