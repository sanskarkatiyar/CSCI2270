#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main()
{
    // edges are undirected
    Graph g;

    g.addVertex("B");
    g.addVertex("D");
    // g.addVertex("C"); // to demonstrate edge feature
    g.addVertex("F");
    // g.addVertex("M");  // to demonstrate edge feature
    g.addVertex("L");
    g.addEdge("C","M"); // will create the node as well
    g.addEdge("B", "D");
    g.addEdge("B", "C");
    g.addEdge("B", "F");
    g.addEdge("F", "D");
    g.addEdge("M","F");
    g.addEdge("L","M");
    g.removeVertex("L");
    g.addEdge("L","M");
    g.addEdge("L", "M"); // check edge exists
    g.displayEdges();
    cout << endl;



    g.breadthFirstTraverse_iterative("C");
    g.breadthFirstTraverse_recursive("C");

    g.depthFirstTraverse_iterative("C");
    g.depthFirstTraverse_recursive("C");

    return 0;
}