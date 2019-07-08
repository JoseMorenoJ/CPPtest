/*  C++ Advanced 1
    
    Fix the problem with the code below. Write a comment explaining the cause.

    José Moreno 06 July 2019
*/

#include <iostream>

struct A
{
    A() { initData(); }

    virtual void initData() { m_data = 5; }
    virtual void processData() { m_data += 5; }

    int m_data;
};

struct B: public A
{
    //It will implicitly call A() thus, A::initData but not B::initData.
    B(){ initData(); }

    virtual void initData() { m_data = 6; }
    virtual void processData() { m_data += 4; }
};

int main(int argc, char* argv[])
{
    A a; //This calls A::initData() --> m_data = 5
    B b; //This calls also A::initData() from the A constructor. 
         //  After the fix, it also calls its own constructor and B::initData() --> m_data = 6
    
    a.processData(); //this is calling A::processData() --> m_data += 5. 10 in total.
    b.processData(); //this calls B::processData() --> m_data += 4. 9 in total (before the fix).
                     //  After the fix, m_Data = 6 thus --> m_data =+ 4. 10 in total.
    std::cout << a.m_data << std::endl;
    std::cout << b.m_data << std::endl;

	return 0;
}