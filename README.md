# What is [CPPtest](https://josemorenoj.github.io/CPPtest/)?
A C++ knowledge test given to me from a company during the selection procces for a C++ developer position.

When I received it I didn't have much experience with C++ or as a developer, moreover, they rejected me. I had 6 hours to do as much as I could but, still today, I am not sure if they were expecting me (or the selected candidate) to finish all the exercises.

## What to find in this repo?
Go straight to the [explanation](#solutions) of the problems.
When I did the test, I failed big time. But I also learnt about what was expected from me as a candidate. In this repo I will repeat the test, exercise by exercise, explaining the solutions the best I can. Maybe even showing alternative solutions.
- The solutions for the problems
- The explanation for each solution
- Additional links to external info

## How can you contribute?
Actually, as I still consider myself new in development, I would like to encourage you to give your opinion about the solutions. Give me alternative solutions, faster or just more elegant. Also, english is not my native language so feel free to correct straight away any typo.
- Give me your opinion, correct my solution if it is wrong
- Give an alternative to my solution (faster, more elegant...)
- Correct any typo 

# Organization
We will use tags to set the different milestones in the proyect.

## Branches
The work in the code will be done in the specific branches:
  - **basic**: to work in the _Basics_ problems solutions.
  - **math**: to work in the _Math_ problems solutions.
  - **algo**: to work in the _Algo_ problems solutions.
  - **advanced**: to work in the _Advanced_ problems solutions.

All the branches will merge with **master** once they are solved. Also, the explanations are in the README file which will be edited from the master branch.

## Releases
### v.0 : Statements
This release contains the Statements as they were, before solving them. Although the changes in the general structure are added also to this version and it will be updated with the changes as we develop the other branches. 

Get the zip file with the [statements](https://github.com/JoseMorenoJ/CPPtest/archive/v.0-Statements.zip).

### v.1 : Basics
This release contains the solution for the "Basics" problems. It has the explanation in the README.md file and the problems in the Statements folder are solved.

Get the zip file with the [statements](https://github.com/JoseMorenoJ/CPPtest/archive/v.1-Basics.zip).

### v.2 : Maths
This release contains the solution for the "Basics" problems. It has the explanation in the README.md file and the problems in the Statements folder are solved.

Get the zip file with the [statements](https://github.com/JoseMorenoJ/CPPtest/archive/v.2-Maths.zip).

### Next releases
There will be a release for every kind of problem. Each release will also have the content of the previous versions.

# In Progress
This is what we are doing now:
   - Review the explanations of Basics and Math.
   - Finish the Algorithm explanations.
   - Finish the Advance problems, double check them and merge the branch.
   - Then, comment the solutions of advance aswell.

# Solutions
In this section you will find the explanations to the solutions. You will also have a link to the code before and after solving it. We recommend **to have the code open** in another editor/window to follow the solutions easily.

As always when learning something, it is better if you try it on your own first.

## Index

   1. [Basics](#basics)
       - [Basics 01](#basics-01): Function template.
       - [Basics 02](#basics-02): Array of array.
       - [Basics 03](#basics-03): Virtual destructor.
       - [Basics 04](#basics-04): Variable scopes.
       - [Basics 05](#basics-05): C++ casting.
       - [Basics 06](#basics-06): Pointer value.
       - [Basics 07](#basics-07): Bit operations.
       - [Basics 08](#basics-08): AND and OR.
       - [Basics 09](#basics-09): Function pointer types.
       - [Basics 10](#basics-10): Rule of 3 and Rule of 5.
       - [Basics 11](#basics-11): Pure virtual class.
       - [Basics 12](#basics-12): Macros.
       - [Basics 13](#basics-13): Unsigned int.
       - [Basics 14](#basics-14): Inheritance.

   2. [Maths](#maths)
       - [Math 01](#math-01): Within max angle.
       - [Math 02](#math-02): Rotation of a point.
       - [Math 03](#math-03): 3D arithmetics.
       - [Math 04](#math-04): Transforms in 3D space.

   3. [Algorithms](#algorithms)
       - [Algorithms 01](#algorithms-01): Fibonacci.
       - [Algorithms 02](#algorithms-02): Random and vector acces.
       - [Algorithms 03](#algorithms-03): Graphs.
       - [Algorithms 04](#algorithms-04): Binary tree.

   4. [Advanced](#advanced) (in progres...)

## Basics
### Basics 01
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics01.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics01.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Unify the definitions of the two sumArray functions into one._

The best way of unify two definitions of a function in c++ is to abstract them in a template function. Even more when one of the function is an overloaded version of the other.

In this case:
```
template <class T>
T sumArray(T *a, int count) {...}
```

We must leave `count` as an `int` because it is the size of the array which is always going to be an integer value independently of the array type.

### Basics 02
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics02.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics02.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Write code that will allocate and then delete an array of 10 arrays of 8 ints each._

There are different ways of doing this, finally I decided for allocate an array of 10 pointers to int:
```
int **array = new int*[10];
``` 
and then we assign the address of an array of 8 ints to every element:
```
for (int i=0; i<10; i++)
    array[i] = new int[8];
```

The same way, we need to use another for loop to delete the inner arrays before deleting the array variable. If we erase first the array, we won't be able to access the inner arrays.

Note that we need to use the `delete[]` operand to do this.

#### Alternative
We can use the `std::vector` instead of plain arrays. We can declare a vector of vectors of ints like this:
```
std::vector < std::vector<int> > array(10, std::vector<int>(8))
```

We are using the [fill constructor](http://www.cplusplus.com/reference/vector/vector/vector/) to initialize it with 10 elements, each of those, initialized as a vector of int of 8 elements.

As we didn't specify any value in the vector of size 8, it will initialize each element with 0.

### Basics 03
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics03.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics03.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Fix the problem with the code below._
_Write a comment to explain the output._

Even though the "fix" is just adding `virtual` to the destructor of the class A, it is important to understand why would we want that to be it.

When the class B is created, it calls the constructor `A()` before calling its own constructor. You can see it _as if_ it was specified in the initialization area of `B()`: 
```
B(): A(), m_BData(new int()) { ... }
```
In the same way, the destructor `~A()` is going to be called if the destructor `~B()` is called. 

The problem here, is that we have an object of the class B in the variable `someA`, which is a pointer of A (`A*`). When we call `delete someA` the compiler will **not call** the destructor `~B()` (and then `~A()`), but `~A()` straight away.

Specifying the `virtual` in the destructor of `~A()` we make sure that it calls the destructor of `~B()` aswell.

### Basics 04
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics04.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics04.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Write a comment explaining the problem with the code below._

Well, that problem with the code, as we understand it, is that we define `i` as an alias of whatever the function `func()` returns. And this function returns a variable declared in the scope of `func()`. Meaning, when we come back from `func()` to `main()`, **the memory** used by `i` **is freed** and available to any other function that might need it. 

Thus, we **cannot be sure** that the value stored is going to be the same.

### Basics 05
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics05.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics05.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Add code that will make the template function add() work for objects of class Vec3._ 
_In this case it should call the Vec3::add() method._

From [cplusplus.com](http://www.cplusplus.com/doc/tutorial/typecasting/):
>`dynamic_cast` can only be used with pointers and references to classes (or with void*). Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.

>`static_cast` can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), but also downcasts (from pointer-to-base to pointer-to-derived). No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.

>`reinterpret_cast` converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

>`const_cast` manipulates the constness of the object pointed by a pointer, either to be set or to be removed. For example, in order to pass a const pointer to a function that expects a non-const argument.

Keeping those definitions in mind:
- line 30, `dynamic_cast`:  `logClass()` receives a pointer to A but then uses it as a pointer to B. We have to make sure wether we have pointer to B or not.
- line 41 `const_cast`: in order to use a `const` vairable in a `non-const` way.
- line 42 `static_cast`: we want to use `B::baz()`, and `pb` is `A*` type. **We know** that `pb` is obtained as `new B` and that is why we can use this kind of cast.
- line 42 `dynamic_cast` and `const_cast`: to make sure that `pa` is treated as a `B*` if it really is an object of type B. Also, we need to make it `non-const` to be able to cast it.
- line 44 `reinterpret_cast` and `const_cast`: we want to cast a `const` variable so we need the `const_cast`. After that, we want to use it as if it was a pointer to an int. We can only do this with the `reinterpret_cast` because there is no relationship between `int` and `A`.

### Basics 06
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics06.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics06.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Fix the problem with the code below._

The problem is that `printValuePlus2()` receives a `int*` but then, it doesn't treat it as a pointer but as an `int`. Thus, it adds 2 to the address (which is the value of a pointer).

The solution is as simple as dereferencing the pointer in the `std::cout` statement.

### Basics 07
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics07.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics07.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Rewrite the implementation of the class Flags so it is more memory efficient for the given value of `MAX_FLAGS`._
_(without using any external container classes from the STL)._

The value of `MAX_FLAGS` is 32 which is the number of bits that an integer has. Knowing that, we will use each bit of an integer (`unsigned int _flags;`) as a flag instead of an array of 32 bool.

This way, `getFlag(int i)` will now return the value of the bit in the _ith_ position. We achieve that using the bit shift operator `<<` to move a '1' to the bit in the _i_ position in our `mask` variable. The rest of the bits will be '0'. The return value, `return mask & _flags;`, will be `true` only if the bit in the _i_ position of our `_flags` variable is also a '1'.

Likewise, we modify `setFlag(int i, bool v);` in a similar way. We use a `mask` with all '0' but a '1' in the _ith_ position. Then, depending on the value of `bool v`, we set the _ith_ flag to true: 
```_flags = _flags | mask;```
or we set the _ith_ flag to false: 
```_flags = _flags & ~mask;```

Take in account that `~mask` (NOT mask) is the inverse of `mask`. All '1' but a '0' in the _ith_ position.


_Document any limitations this imposes on other possible `MAX_FLAGS` values._

Obviously if the value is other than 32, we wouldn't have the same number of bits as flags. If we need less flags, we could consider to use a `char` or a `short`. If we need more, a `long`.

As a downside, when the number of bits is not exactly the number of flags, this won't be as intuitive. 

Also, this implementation will be system dependent since not all the computers have the same size for all the types.

### Basics 08
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics08.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics08.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Write a comment explaining the output of the code below._

The output of the code is the following:
```
    Func0
    Func1
    Main1
```

As we can see, despite having 4 calls to the functions in the if statements, they have been called only 2 times. This is because of the particularity of the `&&` and `||` operands. 

The `&&` operand, will return `true` **only if both sides** are `true`. So, once it knows that the left side is already `false`, it returns `false` without checking the right side. Thus, we only execute the call to `func0()` in the first if statement.

Similarly, with the `||` operand, it will return `true` if **at least one side** is `true`. So, when it knows that the left side, `func1()`, is `true` it returns `true` without checking the right side.

### Basics 09
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics09.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics09.cpp) _(_**_ctrl + click_** _to open new in tab)_

_In the code below change the auto in front of f and g to the most specific possible concrete types._

The first one is a pointer to a function, so we give it the usual type name:
```   return type(*variable name) (input type list)```
Thus, a pointer to the function `int mulBy2(float)` will be: 
```   int(*name) (float)```

This gets more complex when we move to the next 'auto'. Here we have a lambda function. And as told [here](https://blog.feabhas.com/2014/03/demystifying-c-lambdas/): 
> A lambda is an object (hence why we’re referring to it as a functor, rather than a function) so has a type and can be stored. However, **the type of the lambda is only known by the compiler** (since it is compiler-generated), so you must use auto for declaration instances of the lambda.

Usually we would leave the auto like that but in order to find an alternative we will use `std::function` (check the [cplusplus reference](http://www.cplusplus.com/reference/functional/function/) if you need). This is a function wrapper, it will get the lambda and make an object that you can copy and pass around the program.

On this case, we might prefer using the `auto` instead but we also propose to use the `std::function` class trying to go a step further on the solution.

### Basics 10
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics10.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics10.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Fix the problem with the class in the use case below._
_Write a comment about what methods are missing from the class definition if it needs to correctly handle all possible cases with optimal performance._

_Consider you're compiling in post C++11 when writing your answer._

Before going through the solution we should clarify that a class will have defined by default a **_destructor_**, a **_copy constructor_** and a **_copy assignment operator_**. If you need to redefine any of the three, you will need, most likely to redefine the three of them. This is called [the rule of three](https://en.cppreference.com/w/cpp/language/rule_of_three).

Now, since **C++11**, we have the move operations and, also, implicit definitions of the **_move constructor_** and the **_move assignment operator_**. As with the rule of three, any definition we could do of any of the 5 will prevent the implicit definition of the 5 of them. Check [this question](https://stackoverflow.com/questions/4782757/rule-of-three-becomes-rule-of-five-with-c11) from stackoverflow.com.

#### Copy constructor
Now, one of the problems you see in the class FunArray is that it is using the default copy constructor: `FunArray* b = new FunArray(a);` in `main` but it has not redefined it. The default copy constructor will make a "shallow copy" of the object. This means that it will copy the pointer but not duplicate the "pointed" data. Thus, we will have two objects using the same data.
Our definition:
```FunArray(const FunArray &f)```

Also, in order to create the arrays properly, we defined a private variable for the class: `m_Size` of type `size_t`. It will be '0' until we call `GenerateData(int dataSize)`. Then, it will have the value of `dataSize`.

Or, it will get the value from another object if we are using the copy constructor.

#### Rule of 3
Since we added the _copy constructor_, we should define the _default constructor_, the _destructor_ and the _copy assignment operator_.
In this program, the _destructor is already defined_ and we don't use the **assignment operator** so we didn't defined it. See here an example of what it could be:
```
FunArray& FunArray::operator=(const FunArray &f){
    //Similar to the copy constructor.
    m_Data = new uint8_t[f.m_Size];
    m_Size = f.m_Size;
    for (int i = 0; i < m_Size; ++i)
        ((uint8_t* )m_Data)[i] = ((uint8_t*)f.GetArray())[i];
    return *this;
}
```

#### Rule of 5
And to complete the definition of the class with the C++11 move features. The [move constructor](https://en.cppreference.com/w/cpp/language/move_constructor) and the [move assignment operator](https://en.cppreference.com/w/cpp/language/move_assignment):
```
//Move constructor:
FunArray::FunArray(FunArray &&f){
    //fill the FunArray object using std::move operations
}

//Move assignment operator:
FunArray& FunArray::operator=(FunArray &&f){
    return *this;
}
```

We recommend to check the references above to understand in more detail how the move operations are performed.

### Basics 11
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics11.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics11.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Change the definition of class TypePrinter in such a way that it would be impossible for a descendant class to not define the method printClass._

That is the definition a **_pure virtual method_** and in order to make `printClass` pure virtual, we have to **assign it to 0** in addition to use the _virtual_ modifier.

Being pure virtual, the compiler will not allow to not be redefined in a derived class. Thus, it will not use the definition from the base class (because there is no such definition);

### Basics 12
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics12.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics12.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Fix the macro SQUARE to return the intended result in all cases._
_How can you make the program run twice as fast while still producing the same result?_

If we make the substitution we can clearly see the problem:
```
SQUARE(slowThink() + 8)

slowThink() + 8 * slowThink() + 8
```
We can see that it will do the multiplication before the sum. We will obtain `(42 + (8*42) + 8)`, instead of the square of '42+8'.
In order to make sure that it solves first the sum we have to add parenthesis to the macro:

```#define SQUARE(x) (x) * (x)```

### Basics 13
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics13.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics13.cpp) _(_**_ctrl + click_** _to open new in tab)_

_You are working on a Space Simulator game. For some reason, ships in your game are sometimes failing to die (but sometimes they work)._
_Debugging has shown that the Ship::GetHit method is properly called with the proper damage._
_Fix the problems in the class below._

As we can see, the variable `m_Health` is an `unsigned int` so it will not represent negative values. The problem with the `GetHit(unsigned damage)` method will be that if the value of damage is higher than the current value of `m_Health`, it will assign to `m_Health` a negative value. But, what the value of `m_Health` will store is actually going to be a very big possitive value. 

As an example, if we assign -1 to an unsigned int we will obtain the value 4294967294 (2^32 - 1).

Thus, we can also modify the if statement to check only `(m_Health == 0)` since it will never be lower than '0'.

As an alternative, we can change the type of the `m_Health` and `damage` to be an int.

### Basics 14
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Basics14.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Basics14.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Write a comment to explain the output._

The output:
```
    Calling A::baz()
    Calling A::bar()
    Calling A::baz()
    Calling B::bar()
```
This is produced by the following code:
```
    funcCaller(&someA);
    funcCaller(&someB);
```
But,instead of seeing two calls to methods from A and then 2 calls to methods from B, we see that `funcCaller(&someB);` calls `A::baz()` **despite being redefined in B**, `B::baz()`.

The problem is that we haven't defined the method `A::baz()` as virtual. So, when the `funcCaller(A* someA)` calls `baz()`, it gets the method from A.

Basicaly, **in this code**, the definition of `B::baz()` **is useless**.

## Maths
### Math 01
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Math01.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Math01.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Write a function WithinMaxAngle that checks if the angle between two arbitrary vectors is less than MAX_DEGREES._

In order to solve the problem we will use some operations with vectors which are not defined in the C++ library. These functions are:
   - dot product of 2 vectors (overloading the * operator)
   ```
   inline float operator*(const Vec3 &v, const Vec3 &u){ return v.x*u.x + v.y*u.y + v.z*u.z; }
   ```

   - module of 2 vectors
   ```
   inline float module(const Vec3 &v) { return sqrt(v.x*v.x + v.y*v.y + v.z*v.z); }
   ```

We have defined them as inline functions together with the constant PI (3,1415...).

The problem is to see if the angle between two vectors is within a threshold, in our case 43 degrees.

Now, by definition, the dot product of a vector is equal to the product of the vectors modules and the cosine of the angle between them. Using that, we can obtain the cosine of the angle as the dot product divided by the product of the modules. Thus, the angle will be the arcosine of all that.

Because we defined the operations already, this will fit in one line like this:
```
float alpha = acos (v1*v2 / (module(v1)*module(v2)) );
```

The last thing we do is to convert the angle from radians to degrees and check if it is within our reference agle `MAX_DEGREES`.

### Math 02
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Math02.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Math02.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Given an origin O and 2 points A and B in 3D, write a function that calculates the parameters of a rotation that will rotate point A in the direction of point B regarding the origin._

Similarly to the previous problem, we will use the module function and the dot product overloaded operator (*). Also, we will add the following:
   - substraction of vectors (overloading the - operator)
   ```
    inline Vec3 operator-(const Vec3 &v, const Vec3 &u){ 
        return Vec3 {v.x-u.x, v.y-u.y, v.z-u.z}; 
    }
   ```
   - cross product of two vectors
   ```
    inline Vec3 crossProd(const Vec3 &v, const Vec3 &u){ 
        return Vec3{(v.y*u.z - v.z*u.y), (v.z*u.x - v.x*u.z), (v.x*u.y - v.y*u.x)}; 
    }
   ```
Focusing on the problem, we are asked to obtain the necesary angle to move point `A` to the position of point `B` keeping `O` as the center. This is a rotation, which axis will pass through `O` and will be perpendicular to the triangle formed by the three points (this is always better seen if you draw it).
So we will use the following vectors, `OA` and `OB`. Note that the vector between two points is just the last point minus the first point.

By definition, the cross product of two vectors is another vector perpendicular to the other two. So, there we have our axis.
```
axis = crossProd((a-o), (b-o));
```

Now, for the angle, we can repeat the operation we used in the previous problem. The angle will be the arcosine of the dot product divided by the product of the modules.
```
angle = acos( (a-o)*(b-o) / (module(a-o)*module(b-o) ));
```

### Math 03
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Math03.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Math03.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Given points A and B and a number T, write a function to calculate the position of a point P on the line between A and B with the property |AP| / |AB| = T_

In this problem we start with the assumption that |AP| / |AB| = t.

Also, we know that A, B and P are in the same line. We should be able to deduce from the representation of the points that: AB + BP = AP

Taking in account that any vector from X to Y (XY) is the same as Y-X. We can solve the point P using the equations:
1. AP = t*AB
2. AB + BP = AP

Substituting AP in the 2nd equation:
- AB + BP = t\*AB ==> BP = AB\*t-AB = AB(t-1)
- BP = P-B ==> __P = AB(t-1) + B__

Which in our code is:
```
Vec3 { (b.x-a.x)*(t-1) + b.x,
       (b.y-a.y)*(t-1) + b.y,
       (b.z-a.z)*(t-1) + b.z };
```

### Math 04
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Math04.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Math04.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Using the primitives below, write as many type definitions for a transform in 3D space as you can think of._
_Add comments about the constraints and advantages of each the new types, if any._

I have to admit that I am not sure of what is expected to answer in this problem. It asks you to write transforms in 3D space, [which we can see here what the are](https://en.wikipedia.org/wiki/Transformation_matrix#Examples_in_3D_computer_graphics), but I am not sure on the format.

I decided to write different structs. A rotation matrix (X axis) and a symetry matrix. I guess you could write different matrixes depending on the rotation axis or even you could write the rotation matrix in 3 axes (the Euler angles) but it seemed like a copy-paste activity without much to learn from it.

## Algorithms
### Algorithms 01
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Algo01.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Algo01.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Consider the following sequence : 0,1,1,2,3,5,8,13,21,34,55,89,144..._
_Write an iterative function to return the nth element of the sequence._

The famous fibonacci sequence.

We have implemented the sequence in a recursively manner. We call the function with the element that we want to retrieve. We will return the sum of the previous 2 elements of the sequence. There it is the recursiveness.

```
int fibonacci(int n){
    return fibonacci(n-1) + fibonacci(n-2);
}
```

But then, if we leave it like this, we will never get out of the loop. We need to specify in the function when it should stop calling itself. In this case, if we want the first or the second number, there are no 2 previous numbers. That would be when we return just '0' for the first or '1' for the second.

Leaving the function like this:
```
int fibonacci(int n){
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else if (n > 2){
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
```

### Algorithms 02
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Algo02.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Algo02.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Write a function that removes K random elements from a std::vector as efficiently as you can._
_The function should work in place, but does not need to preserve the order of elements._






### Algorithms 03
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Algo03.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Algo03.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Given the struct Vertex, representing vertices in a graph, write a function DFVisit() that traverses the graph and fills_
_the vector result with all connected vertices in Depth First order. Write a comment with the time complexity of your implementation._






### Algorithms 04
[unsolved](https://josemorenoj.github.io/CPPtest/statements/unsolved/Algo04.cpp) /
[solved](https://josemorenoj.github.io/CPPtest/statements/Algo04.cpp) _(_**_ctrl + click_** _to open new in tab)_

_Given the struct BSTNode which represents a node in a binary search tree, write a function BSTMerge() that will merge the contents of two search trees into one._
-The function does not need to preserve the contents of the input trees._







_The end..._