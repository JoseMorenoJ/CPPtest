# What is CPPtest?
A C++ knowledge test given to me from a company during the selection procces for a C++ developer position.

When I received it I didn't have much experience with C++ or as a developer, moreover, they rejected me. I had 6 hours to do as much as I could but, still today, I am not sure if they were expecting me (or the selected candidate) to finish all the exercises.

## What to find in this repo?
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

### Branches
There is one branch for each kind of problem (Basic, Algorithms, Maths and Advanced) to be able to isolate the different sets of porblems.
  - basics: to work in the _Basics_ problems solutions.
  - maths: to work in the _Math_ problems solutions.
  - algo: to work in the _Algo_ problems solutions.
  - advanced: to work in the _Advanced_ problems solutions.

All the branches will merge with master once they are solved. 

### Releases
#### v.0 : Statements
This release contains the Statements as they were, before solving them. Although the changes in the general structure are added also to this version and it will be updated with the changes as we develop the other branches.

#### Next releases
There will be a release for every kind of problem. Each release will also have the content of the previous versions.

# In Progress
- Right now, we are structuring the README file so it will be easy to navigate through the different problems and solutions.
- Considering to keep a copy of the Statements as part of the code to be able to compare when presenting the solution. This is, having **both** the statement and the solution. 
  - Maybe we can just call a link to the _diff_ utility between versions.

# Solutions
## Index
   1. [Basics](#basics)
     - [Basics 01](#basics-01): 
     - [Basics 02](#basics-02)
     - [Basics 03](#basics-03)
     - [Basics 04](#basics-04)
     - [Basics 05](#basics-05)
     - [Basics 06](#basics-06)
     - [Basics 07](#basics-07)
   2. [Maths](#maths)
   3. [Algorithms](#algorithms)
   4. [Advanced](#advanced)

## Basics
### Basics 01
_Unify the definitions of the two sumArray functions into one._

The only way of unify two definitions of a function (an overloaded function) is to abstract them in a template function.

In this case:
```
template <class T>
T sumArray(T *a, int count) {...}
```

We must leave `count` as an `int` because it is the size of the array which is always going to be an integer value independently of the array type.

### Basics 02
_Write code that will allocate and then delete an array of 10 arrays of 8 ints each._

There are different ways of doing this, finally I decided for allocate an array of 10 pointers to int (`int*`):
`int **array = new int*[10];`
and then we assign the address of an array of 8 ints to every element:
```
for (int i=0; i<10; i++)
    array[i] = new int[8];
```

The same way, we need to use another for loop to delete the inner arrays before deleting the array variable. If we erase first the array, we won't be able to access the inner arrays.

Note that we need to use the `delete[]` operand to do this.

#### Alternative
We can use the `std::vector` instead of plain arrays. We can declare a vector of vectors of ints like this:
`std::vector < std::vector<int> > array(10, std::vector<int>(8))`

We are using the [fill constructor](http://www.cplusplus.com/reference/vector/vector/vector/) to initialize it with 10 elements, each of those, initialized as a vector of int of 8 elements.

Because we didn't specify anything in the vector of size 8, it will fill the vector with the value 0.

### Basics 03
_Fix the problem with the code below._
_Write a comment to explain the output._

Even though the "fix" is just adding `virtual` to the destructor of the class A, it is important to understand why would we want that to be it.

When the class B is created, it calls the constructor `A()` before calling its own constructor. You can see it as if it was specified in the initialization area of `B()`: 
`B(): A(), m_BData(new int()) { ... }`
In the same way, the destructor `~A()` is going to be called if the destructor `~B()` is called. 

The problem here, is that we have an object of the class B in the variable `someA`, which is a pointer of A (`A*`). When we call `delete someA` the compiler will **not call** the destructor `~B()` (and then `~A()`), but `~A()` straight away.

Specifying the `virtual` in the destructor of `~A()` we make sure that it calls the destructor of `~B()` aswell.

### Basics 04
_Write a comment explaining the problem with the code below._

Well, that problem with the code, as we understand it, is that we define `i` as an alias of whatever the function `func()` returns. And this function returns a variable declared in the scope of `func()`. Meaning, when we come back from `func()` to `main()`, the memory used by `i` is freed and available to any other function that might need it. 

Thus, we **cannot be sure** that the value stored is going to be the same.

### Basics 05
`dynamic_cast` can only be used with pointers and references to classes (or with void*). Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.

`static_cast` can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), but also downcasts (from pointer-to-base to pointer-to-derived). No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.

`reinterpret_cast` converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

`const_cast` manipulates the constness of the object pointed by a pointer, either to be set or to be removed. For example, in order to pass a const pointer to a function that expects a non-const argument.

Keeping those definitions in mind:
- line 30, `dynamic_cast`:  `logClass()` receives a pointer to A but then uses it as a pointer to B. Like this we make sure that we pointer to B or not.
- line 41 `const_cast`: in order to use a `const` vairable in a `non-const` way.
- line 42 `static_cast`: we want to use B::baz(), and `pb` is `A*` type. We know that pb is obtained as `new B` and that is why we can use this kind of cast.
- line 42 `dynamic_cast` and `const_cast`: to make sure that `pa` is treated as a `B*` if it really is. Also, we need to make it `non-const` to be able to cast it.
- line 44 `reinterpret_cast` and `const_cast`: we want to cast a `const` variable so we need the `const_cast`. After that, we want to use it as if it was a pointer to an int. We can only do this with the `reinterpret_cast` because there is no relationship between `int` and `A`.

### Basics 06

### Basics 07

### Basics 08

### Basics 09
