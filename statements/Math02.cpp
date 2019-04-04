/*  C++ Maths 2
    
    Given an origin O and 2 points A and B in 3D, write a function that calculates the parameters of a rotation that will rotate point A in the direction of point B regarding the origin.
*/

#include <iostream>
#include <cmath>

struct Vec3
{
    float x, y, z;
};

const double PI = 3.14159265358;

//dot product of 2 vectors
inline float operator*(const Vec3 &v, const Vec3 &u){ return v.x*u.x + v.y*u.y + v.z*u.z; }
//module of 2 vectors
inline float module(const Vec3 &v) { return sqrt(v.x*v.x + v.y*v.y + v.z*v.z); }
//substraction of two points
inline Vec3 operator-(const Vec3 &v, const Vec3 &u){ return Vec3 {v.x-u.x, v.y-u.y, v.z-u.z}; }

inline Vec3 crossProd(const Vec3 &v, const Vec3 &u){ return Vec3{(v.y*u.z - v.z*u.y), (v.z*u.x - v.x*u.z), (v.x*u.y - v.y*u.x)}; }

void CalcRotation(const Vec3 &o, const Vec3 &a, const Vec3 &b, Vec3 &axis, float &angle)
{
    angle = acos( (a-o)*(b-o) / (module(a-o)*module(b-o) )); //angle between OA and OB

    //axis will be the vectorial product of OA x OB
    axis = crossProd((a-o), (b-o));
}

int main(int argc, char* argv[])
{
    Vec3 o = {2, 2, 2};
    Vec3 a = {1, 1, 1};
    Vec3 b = {0.5f, 0, 1.5f};

    Vec3 axis;
    float angle;
    CalcRotation(o, a, b, axis, angle);
    std::cout << "Axis: " << axis.x << ", " << axis.y << ", " << axis.z << " angle: " << angle << std::endl;

	return 0;
}