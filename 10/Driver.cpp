#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main()
{
    // edges are undirected
    Graph g;
    g.addEdge("A", "B", 15);
    g.addEdge("A", "C", 8);
    g.addEdge("B", "C", 4);
    g.addEdge("B", "E", 2);
    g.addEdge("C", "E", 6);
    g.addEdge("B", "D", 2);
    g.addEdge("D", "E", 1);
    g.addEdge("D", "F", 3);
    g.addEdge("E", "F", 7);

    g.displayEdges();
    cout << endl;
    
    g.dijkstra_shortest_path_priority_queue("A");
    g.dijkstra_shortest_path_pointer("A");


    return 0;
}