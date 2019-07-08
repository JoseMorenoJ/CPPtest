/*  C++ Basics 13
    
    You are working on a Space Simulator game. For some reason, ships in your game are sometimes failing to die (but sometimes they work). 
    Debugging has shown that the Ship::GetHit method is properly called with the proper damage. 

    Fix the problems in the class below.

    José Moreno 06 July 2019
*/

class Ship
{
    Ship() : m_IsAlive(true) {}

    void GetHit(unsigned damage)
    {
        //m_Health is unsigned int. If we try to substract more than its value it will not get a negative number.
        //  it will get a very big number.

        if (m_Health > damage)
        {
            m_Health -= damage; //Substract the damage only if it is bigger.
        }
        else //Reduce to 0 the health and call GetDestroyed()
        {
            m_Health = 0;
            GetDestroyed();
        }
    }

    void GetDestroyed()
    {
        m_IsAlive = false;
        //Plays an animation for getting destroyed
    }	

private:
    bool m_IsAlive;
    unsigned m_Health;
};

int main(int argc, char* argv[])
{
    // Game code goes here :)
	return 0;
}