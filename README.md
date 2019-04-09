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
   2. [Maths](#maths)
   3. [Algorithms](#algorithms)
   4. [Advanced](#advanced)

## Basics
### Basics 05
`dynamic_cast` can only be used with pointers and references to classes (or with void*). Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.

`static_cast` can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), but also downcasts (from pointer-to-base to pointer-to-derived). No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.

`reinterpret_cast` converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

`const_cast` manipulates the constness of the object pointed by a pointer, either to be set or to be removed. For example, in order to pass a const pointer to a function that expects a non-const argument:
