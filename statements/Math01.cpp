/*  C++ Maths 1
    
    Write a function WithinMaxAngle that checks if the angle between two arbitrary vectors is less than MAX_DEGREES.

    José Moreno 06 July 2019
*/

#include <iostream>
#include <cmath>

struct Vec3
{
    float x, y, z;
};

const double PI = 3.14159265358;
const float MAX_DEGREES = 43.f;

//Helper vector operations:
//  dot product of 2 vectors
inline float operator*(const Vec3 &v, const Vec3 &u){ return v.x*u.x + v.y*u.y + v.z*u.z; }
//  module of 2 vectors
inline float module(const Vec3 &v) { return sqrt(v.x*v.x + v.y*v.y + v.z*v.z); }

bool WithinMaxAngle(const Vec3 &v1, const Vec3 &v2)
{
    float alpha = acos (v1*v2 / (module(v1)*module(v2)) ); //alpha is in radians
    return (alpha*180.f/PI) <= MAX_DEGREES;
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