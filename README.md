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

# Maths
### Math03
In this problem we start with the assumption that |AP| / |AB| = t.

Also, we know that A, B and P are in the same line. We should be able to deduce from the representation of the points that: AB + BP = AP

Taking in account that any vector from X to Y (XY) is the same as Y-X. We can solve the point P using the equations:
1. AP = t*AB
2. AB + BP = AP

Substituting AP in the 2nd equation:
- AB + BP = t\*AB ==> BP = AB\*t-AB = AB(t-1)
- BP = P-B ==> _P = AB(t-1) + B_
