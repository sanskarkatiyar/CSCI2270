#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    // can add other properties like weight
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        void addEdge(std::string v1, std::string v2, bool verbose=true, bool create_node=true);
        void addVertex(std::string name, bool verbose=true);
        void removeEdge(std::string v1, std::string v2, bool verbose=true);
        void removeVertex(std::string v, bool verbose=true);

        bool edgeExists(std::string s1, std::string s2);
        void displayEdges();
        vertex* findVertexPointer(std::string toFind);

    private:
        std::vector<vertex*> vertices;

};

#endif // GRAPH_H