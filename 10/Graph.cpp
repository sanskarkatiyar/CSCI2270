#include "Graph.hpp"
#include <vector>
#include <stack>
#include <queue>
#include <cfloat>
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

void Graph::setDistanceInfinity(vertex* s)
{
    for(int i = 0; i < vertices.size(); i++) {
        vertices[i]->prev = NULL;
        if(vertices[i] == s) {
            vertices[i]->distance = 0;
        }
        else {
            vertices[i]->distance = FLT_MAX;
        }
    }
}

void Graph::setVisitedFalse()
{
    for(int i = 0; i < vertices.size(); i++) {
        vertices[i]->visited = false;
    }
}

int Graph::getEdgeWeight(std::string s1, std::string s2)
{
    vertex* v1 = findVertexPointer(s1);
    vertex* v2 = findVertexPointer(s2);

    if(v1 && v2)
    {
        for(int i = 0; i < v1->adj.size(); i++) {
            if (v1->adj[i].v == v2) {
                return v1->adj[i].weight;
            }
        }
    }

    return -1;
}

void Graph::addEdge(std::string s1, std::string s2, int weight, bool verbose, bool create_node)
{
    // arg: create_node == true creates the nodes if they don't exist in graph

    // if edge already exists then nothing to do
    if (edgeExists(s1, s2)) {
        if (verbose) {
            cout << "[INFO] Edge: " << s1 << " <-> " << s2 << " already exists." << endl;
            int x = getEdgeWeight(s1, s2); 
            if(x > 0 && x != weight) {
                removeEdge(s1, s2, false);
                addEdge(s1, s2, weight, false);
                cout << "[INFO] " << s1 << " <-> " << s2 << " weight modified from "<< x << " to "<< weight << endl;
            } 
        }
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
        av1.weight = weight;
        v2->adj.push_back(av1);

        // edge from v1 to v2
        av2.v = v2;
        av2.weight = weight;
        v1->adj.push_back(av2);

        if(verbose) cout << "[INFO] Edge Added: " << s1 << " <-> "<< s2 << " [" << weight<< "] "<< endl;
    }
    else {
        if(verbose) cout << "[FAILED] Edge Insertion: " << s1 << " <-> "<< s2 << " [" << weight<< "] "<< endl;
    }
}

void Graph::addVertex(string n, bool verbose){
    vertex* exists = findVertexPointer(n);
    if(!exists){
        vertex* v = new vertex;
        v->name = n;
        vertices.push_back(v);
        if(verbose) cout << "[INFO] Vertex Added: " << n << endl;
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
            if(verbose) cout << "[INFO] Edge Deleted: " << s1 << " <-> "<< s2 << endl;
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
        if (verbose) cout << "[INFO] Vertex Deleted: " << s << endl;
    }
    else {
        if (verbose) cout << "[FAILED] Vertex Deletion: " << s << endl;
    }
}

void Graph::displayEdges(){
    cout << endl << "[DISPLAY EDGES]" << endl;
    for(int i = 0; i < vertices.size(); i++) {
        for(int j = 0; j < vertices[i]->adj.size(); j++) {
            cout << "(" << vertices[i]->name << ", " << vertices[i]->adj[j].v->name << ", " << vertices[i]->adj[j].weight << ") ";
        }
        cout << endl;
    }
    cout << endl;
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


void Graph::dijkstra_shortest_path_priority_queue(string sourceVertex){
    // Find the starting vertex
    // Need a pointer to keep track of starting vertex
    vertex *vStart = findVertexPointer(sourceVertex); 
    if(!vStart) {
        cout << "Vertex " << sourceVertex << " does not exist!" << endl;
        return;
    }

    setVisitedFalse();  // set all nodes to not visited
    setDistanceInfinity(vStart); // except this node set all distance to INF, prev to NULL

    priority_queue<vertex*, vector<vertex*>, CompareDistance> Q;  // create a priority_queue to keep track of unvisited nodes
    for(int i = 0; i < vertices.size(); i++) {
        vertex* tmp = vertices.at(i);
        Q.push(tmp);
    }

    cout << "[Dijkstra's PQ (source: " << vStart->name << ")] " << endl;
    while(!Q.empty()) {
        vertex* ver = Q.top(); // get element with min dist
        Q.pop(); // remove the item from the Q
        ver->visited = true;

        for(int j = 0; j < ver->adj.size(); j++) {
            if ((ver->distance + ver->adj[j].weight) < ver->adj[j].v->distance) {
                ver->adj[j].v->distance = ver->distance + ver->adj[j].weight;
                ver->adj[j].v->prev = ver;
            }
        }
    }

    stack<string> s;
    for(int i = 0; i < vertices.size(); i++) {
        // for disconnected components
        if(vertices[i]->prev) {
            cout << vertices[i]->name <<  ": " << vertices[i]->distance;
            vertex* v = vertices[i];
            while(v != NULL) {
                s.push(v->name);
                v = v->prev;
            }

            cout << " [";
            cout << s.top(); s.pop();
            while(!s.empty()) {
                cout << "->" << s.top();
                s.pop();
            }
            cout << "]" << endl;
        }
    }

    cout << "\n\n";
}

void Graph::dijkstra_shortest_path_pointer(string sourceVertex){
    // Find the starting vertex
    // Need a pointer to keep track of starting vertex
    vertex *vStart = findVertexPointer(sourceVertex); 
    if(!vStart) {
        cout << "Vertex " << sourceVertex << " does not exist!" << endl;
        return;
    }

    setVisitedFalse();  // set all nodes to not visited
    setDistanceInfinity(vStart); // except this node set all distance to INF, prev to NULL

    vector<vertex*> Q;  // create a vector to keep track of unvisited nodes
    for(int i = 0; i < vertices.size(); i++) {
        vertex* tmp = vertices.at(i);
        Q.push_back(tmp);
    }

    cout << "[Dijkstra's Normal (source: " << vStart->name << ")] " << endl;
    while(!Q.empty()) {
        // get element with min dist
        float mindist = FLT_MAX;
        int minidx = -1;
        for(int j = 0; j < Q.size(); j++) {
            if(Q[j]->distance < mindist) {
                mindist = Q[j]->distance;
                minidx = j;
            }
        }
        vertex* ver = Q[minidx];
        Q.erase(Q.begin() + minidx); // delete from the Q
        ver->visited = true;

        for(int j = 0; j < ver->adj.size(); j++) {
            if ((ver->distance + ver->adj[j].weight) < ver->adj[j].v->distance) {
                ver->adj[j].v->distance = ver->distance + ver->adj[j].weight;
                ver->adj[j].v->prev = ver;
            }
        }
    }

    stack<string> s;
    for(int i = 0; i < vertices.size(); i++) {
        // for disconnected components
        if(vertices[i]->prev) {
            cout << vertices[i]->name <<  ": " << vertices[i]->distance;
            vertex* v = vertices[i];
            while(v != NULL) {
                s.push(v->name);
                v = v->prev;
            }

            cout << " [";
            cout << s.top(); s.pop();
            while(!s.empty()) {
                cout << "->" << s.top();
                s.pop();
            }
            cout << "]" << endl;
        }
    }

    cout << "\n\n";

}