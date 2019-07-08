/*  C++ Algorithms 3
    
    Given the struct Vertex, representing vertices in a graph, write a function DFVisit() that traverses the graph and fills 
    the vector result with all connected vertices in Depth First order. Write a comment with the time complexity of your implementation.
    
    José Moreno 06 July 2019
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Vertex
{
    std::vector<Vertex*> m_adjacent;
};

//about the complexity: 
//  This recursive approach will iterate for each adjacent vertex of every adjacent vertex.
//      Increasing at a rate of the square of vertexes. O(N^2).
//  Also, we have to take in account the speed of the std::find function which is linear time.
//      Considering aswell that we are using find in a vector, which is faster than any other container.
//      Considering also that we are using pointers, that would make it slower.
void DFVisit(Vertex* v, std::vector<Vertex*>& visit)
{
    //If it is the first vertex, we add it to the visited vector
    if (visit.size() == 0) visit.push_back(v);
    //Then iterate through its adjacent vertex
    for (Vertex* vert : v->m_adjacent){
        if(std::find(visit.begin(), visit.end(), vert) == visit.end()){
            visit.push_back(vert);
            DFVisit(vert, visit);
        }
    }
}

int main(int argc, char* argv[])
{
    Vertex a, b, c, d;
    a.m_adjacent.push_back(&b);
    b.m_adjacent.push_back(&c);
    c.m_adjacent.push_back(&d);
    d.m_adjacent.push_back(&b);

    std::vector<Vertex*> visited;
    DFVisit(&d, visited);

    std::cout << "Number of visited vertices: " << visited.size() << std::endl;

	return 0;
}