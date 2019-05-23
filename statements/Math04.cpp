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

//Rotation in the X axis
struct RotationX
{
    RotationX (float angle){
        generateRotMatrix();
    }
    float angle;
    float rot[3][3];
    void generateRotMatrix(){
        rot[1][1] = 1;
        /*
         *
         */
        rot[3][3] = cos(angle);
    }
};

//Reflection from a plane
struct Reflection
{
    Reflection(Vec3 plane){
        generateRefMatrix();
    }
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