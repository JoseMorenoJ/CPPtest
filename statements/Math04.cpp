/*  C++ Maths 4
    
    Using the primitives below, write as many type definitions for a transform in 3D space as you can think of.
    Add comments about the constraints and advantages of each the new types, if any.
*/

#include <iostream>

struct Quaternion
{
    float w, x, y, z;
};

struct Vec3
{
    float x, y, z;
};

struct Matrix3x3
{
    float m[3][3];
};

struct Matrix4x4
{
    float m[4][4];
};

//We just happend to see wikipedia: https://en.wikipedia.org/wiki/Transformation_matrix#Examples_in_3D_computer_graphics
//  So we can define this different transforms:
struct RotationX
{
    float angle;
    float rot[3][3];
    // we should add methods that fill up this matrixes. Like:
    void generateRotMatrix(){
        rot[1][1] = 1;
        /*
         *
         */
        rot[3][3] = cos(angle);
    }
};

struct Reflection
{
    //symetry plane: ax + by + cz = 0
    Vec3 plane; //vector normal to the symetry plane: {a, b, c}
    float ref[3][3];
    
    void generateRefMatrix(){
        ref[1][1] = 1-2*plane.x*plane.x;
        /*
         *
         */
        ref[3][3] = 1 - 2*plane.z*plane.z;
    }
};

int main(int argc, char* argv[])
{
    std::cout << "I know maths, really." << std::endl;

	return 0;
}