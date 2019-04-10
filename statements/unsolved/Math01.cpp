/*  C++ Maths 1
    
    Write a function WithinMaxAngle that checks if the angle between two arbitrary vectors is less than MAX_DEGREES.
*/

#include <iostream>

struct Vec3
{
    float x, y, z;
};

const float MAX_DEGREES = 43.f;

bool WithinMaxAngle(const Vec3 &v1, const Vec3 &v2)
{
    return (bool) 3;
}

int main(int argc, char* argv[])
{
    Vec3 a = {1, 1, 1};
    Vec3 b = {0.3f, 0, 1};
    Vec3 c = {0.5f, 0, 1};
	std::cout << std::boolalpha;
    std::cout << WithinMaxAngle(a, b) << std::endl;
    std::cout << WithinMaxAngle(a, c) << std::endl;

	return 0;
}