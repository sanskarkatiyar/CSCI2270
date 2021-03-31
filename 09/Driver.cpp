#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main()
{
    // edges are undirected
    Graph g;

    g.addVertex("Boulder");
    g.addVertex("Denver");
    // g.addVertex("Cheyenne"); // to demonstrate edge feature
    g.addVertex("Fruita");
    // g.addVertex("Moab");  // to demonstrate edge feature
    g.addVertex("Las Vegas");
    g.addEdge("Cheyenne","Moab"); // will create the node as well
    g.addEdge("Boulder", "Denver");
    g.addEdge("Boulder", "Cheyenne");
    g.addEdge("Boulder", "Fruita");
    g.addEdge("Fruita", "Denver");
    g.addEdge("Moab","Fruita");
    g.addEdge("Las Vegas","Moab");
    g.removeVertex("Las Vegas");
    g.addEdge("Las Vegas","Moab");

    g.displayEdges();
    cout << endl;

    return 0;
}