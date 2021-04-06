#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    float weight = 0;
};

class vertex{
    public:
        std::string name;
        bool visited = false;
        vertex* prev = NULL;
        float distance = 1.0e+9;
        std::vector<adjVertex> adj;
};


struct CompareDistance {
    bool operator()(vertex* const &l, vertex* const &r) {
        return l->distance > r->distance;
    }
};

class Graph
{
    public:
        void addEdge(std::string v1, std::string v2, int weight=1, bool verbose=true, bool create_node=true);
        void addVertex(std::string name, bool verbose=true);
        void removeEdge(std::string v1, std::string v2, bool verbose=true);
        void removeVertex(std::string v, bool verbose=true);
        void dijkstra_shortest_path_priority_queue(std::string sourceVertex);
        void dijkstra_shortest_path_pointer(std::string sourceVertex);

        int getEdgeWeight(std::string v1, std::string v2);
        bool edgeExists(std::string s1, std::string s2);
        void displayEdges();
        vertex* findVertexPointer(std::string toFind);
        void setVisitedFalse();
        void setDistanceInfinity(vertex* source);

    private:
        std::vector<vertex*> vertices;

};

#endif // GRAPH_H