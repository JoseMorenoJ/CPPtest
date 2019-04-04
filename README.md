# What is CPPtest?
A C++ knowledge test given to me from a company during the selection procces for a C++ developer position.

When I received it I didn't have much experience with C++ or as a developer, moreover, they rejected me. I was supposed to finish the test in 6 hours. Well, I had 6 hours to do as much as I could but, still today, I am not sure if they were expecting me (or the selected candidate) to finish all the exercises.

## What to find in this repo?
When I did the test, I failed big time. But I also learnt about what was expected from me as a candidate. In this repo I will repeat the test, exercise by exercise, explaining the solutions the best I can. Maybe even showing alternative solutions.
- The solutions for the problems
- The explanation for each soution
- Additional links to external info

## How can you contribute?
Actually, as I still consider myself new in development, I would like to encourage you to give your opinion about the solutions. Give me alternative solutions, faster or just more elegant. Also, english is not my native language so feel free to correct straight away any typo.
- Give me your opinion, correct my solution if it is wrong
- Give an alternative to my solution (faster, more elegant...)
- Correct any typo 

# Organization
I will try to use tags to set the different milestones in the proyect.

### Branches
I have the intention to use one branch for each kind of problem (Basic, Algorithms, Maths and Advanced) to be able to isolate the different sets of porblems.

### Releases
#### Statements
This extract the code from "Statements" version and you will get only that, the statements. Not a single problem solved.

#### Basics (in progress)
As soon as I finish the Basic problems I will release another version called "Basics".

### To do
I plan to do a realease after I solve every different sets of problems.

# Basics
### Basics 05
`dynamic_cast` can only be used with pointers and references to classes (or with void*). Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.

`static_cast` can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), but also downcasts (from pointer-to-base to pointer-to-derived). No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.

`reinterpret_cast` converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

`const_cast` manipulates the constness of the object pointed by a pointer, either to be set or to be removed. For example, in order to pass a const pointer to a function that expects a non-const argument: