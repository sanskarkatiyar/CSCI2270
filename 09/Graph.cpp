#include "Graph.hpp"
#include <vector>
#include <iostream>

using namespace std;

vertex* Graph::findVertexPointer(std::string toFind)
{
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->name == toFind) {
            return vertices[i];
        }
    }

    return nullptr;
}


void Graph::addEdge(std::string s1, std::string s2, bool verbose, bool create_node)
{
    // arg: create_node == true creates the nodes if they don't exist in graph
    if (edgeExists(s1, s2)) {
        if (verbose) cout << "Edge: " << s1 << " <-> " << s2 << " already exists" << endl;
        return;
    }

    vertex* v1 = findVertexPointer(s1);
    vertex* v2 = findVertexPointer(s2);

    if (!v1 && create_node) {
        addVertex(s1, true);
        v1 = findVertexPointer(s1);
    }

    if (!v2 && create_node) {
        addVertex(s2, true);
        v2 = findVertexPointer(s2);
    }

    if(v1 && v2 && v1 != v2) {
        adjVertex av1, av2;

        // edge from v2 to v1
        av1.v = v1;
        v2->adj.push_back(av1);

        // edge from v1 to v2
        av2.v = v2;
        v1->adj.push_back(av2);

        if(verbose) cout << "Edge Added: " << s1 << " <-> "<< s2 << endl;
    }
    else {
        if(verbose) cout << "[FAILED] Edge Insertion: " << s1 << " <-> "<< s2 << endl;
    }
}

void Graph::addVertex(string n, bool verbose){
    vertex* exists = findVertexPointer(n);
    if(!exists){
        vertex* v = new vertex;
        v->name = n;
        vertices.push_back(v);
        if(verbose) cout << "Vertex Added: " << n << endl;
    }
}

void Graph::removeEdge(std::string s1, std::string s2, bool verbose)
{
    vertex* v1 = findVertexPointer(s1);
    vertex* v2 = findVertexPointer(s2);
    int idx = -1;

    if(v1 && v2 && v1 != v2) {
        idx = -1;
        // delete v1->v2
        for (int i = 0; i < v1->adj.size(); i++) {
            if(v1->adj[i].v == v2) {
                idx = i;
                break;
            }
        }
        if (idx >= 0) v1->adj.erase(v1->adj.begin() + idx);

        idx = -1;
        // delete v2->v1
        for (int i = 0; i < v2->adj.size(); i++) {
            if(v2->adj[i].v == v1) {
                idx = i;
                break;
            }
        }
        if (idx >= 0) {
            v2->adj.erase(v2->adj.begin() + idx);
            if(verbose) cout << "Edge Deleted: " << s1 << " <-> "<< s2 << endl;
            return;
        }
    }
    if(verbose) cout << "[FAILED] Edge Deletion: " << s1 << " <-> "<< s2 << endl;
}

void Graph::removeVertex(std::string s, bool verbose)
{
    vertex* v = findVertexPointer(s);
    if(v) {
        int v_idx = 0;
        for(int i = 0; i < vertices.size(); i++) {
            if(v == vertices[i]) {
                v_idx = i;

                // remove all edges associated with v
                while(v->adj.size()) {
                    removeEdge(v->name, v->adj[0].v->name, false);
                }
            }
        }
        vertices.erase(vertices.begin() + v_idx); // delete vertex
        if (verbose) cout << "Vertex Deleted: " << s << endl;
    }
    else {
        if (verbose) cout << "[FAILED] Vertex Deletion: " << s << endl;
    }
}

void Graph::displayEdges(){
    // Recitation 09 Exercise
    // TODO: You should complete this
    cerr << "displayEdges() is INCOMPLETE" << endl;
}


bool Graph::edgeExists(string s1, string s2)
{
    vertex* v1 = findVertexPointer(s1);
    vertex* v2 = findVertexPointer(s2);

    int y = 0;
    if (v1 && v2) {
        // check v1's adj list for v2
        // works for both directed (v1->v2) and undirected (v1<->v2)
        // assuming undirected insertion is always correct.
        for(int i = 0; i < v1->adj.size(); i++) {
            if (v1->adj[i].v == v2) {
                y = 1;
                break;
            }
        }
    }

    return (bool) y;
}
