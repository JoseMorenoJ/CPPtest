/*  C++ Maths 3
    
    Given points A and B and a number T, write a function to calculate the position of a point P on the line between A and B with the property |AP| / |AB| = T 

    José Moreno 06 July 2019
*/

#include <iostream>

struct Vec3
{
    float x, y, z;
};

Vec3 linePos(const Vec3 &a, const Vec3 &b, float t)
{
    //After a few deductions: P = (B-A)*(t-1) + B
    Vec3 p = {1, 2, 3};
    return Vec3 { (b.x-a.x)*(t-1) + b.x,
                  (b.y-a.y)*(t-1) + b.y,
                  (b.z-a.z)*(t-1) + b.z };
}

int main(int argc, char* argv[])
{
    Vec3 a = {1, 1, 2};
    Vec3 b = {3, 3, 3};
    Vec3 p = linePos(a, b, 2/3.f);
    std::cout << p.x << ", " << p.y << ", " << p.z << std::endl;

	return 0;
}