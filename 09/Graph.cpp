#include "Graph.hpp"
#include <vector>
#include <queue>
#include <stack>
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

void Graph::setVisitedFalse()
{
    for(int i = 0; i < vertices.size(); i++) {
        vertices[i]->visited = false;
    }
}

void Graph::addEdge(std::string s1, std::string s2, bool verbose, bool create_node)
{
    // arg: create_node == true creates the nodes if they don't exist in graph

    // if edge already exists then nothing to do
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
    cout << endl << "[DISPLAY EDGES]" << endl;
    for(int i = 0; i < vertices.size(); i++) {
        for(int j = 0; j < vertices[i]->adj.size(); j++) {
            cout << "(" << vertices[i]->name << ", " << vertices[i]->adj[j].v->name << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::breadthFirstTraverse_iterative(string sourceVertex){
    // Find the starting vertex
    // Need a pointer to keep track of starting vertex
    vertex *vStart = findVertexPointer(sourceVertex); 
    if(!vStart) {
        cout << "Vertex " << sourceVertex << " does not exist!" << endl;
        return;
    }

    setVisitedFalse(); // set all nodes to not visited

    cout << "BFS Iter (source): " << vStart->name;
    vStart->visited = true;

    // Use the STL queue to keep track of visited vertices
    queue<vertex*> q;

    // Enqueue the starting vertex
    q.push(vStart);    // enqueue

    // Need another vertex pointer
    vertex *n;

    while(!q.empty()){
        n = q.front(); // peek 
        q.pop();       // dequeue

        // scan the adj list of each element in Q
        for( int x = 0; x < n->adj.size(); x++ )
        {
            // check if vertex visited
            if(n->adj[x].v->visited == false)
            {
                n->adj[x].v->visited = true;
                q.push(n->adj[x].v);
                cout << " -> " << n->adj[x].v->name;
            }
        }
    }
    cout << "\n\n";
}

void Graph::depthFirstTraverse_iterative(string sourceVertex){
    // Find the starting vertex
    // Need a pointer to keep track of starting vertex
    vertex *vStart = findVertexPointer(sourceVertex); 
    if(!vStart) {
        cout << "Vertex " << sourceVertex << " does not exist!" << endl;
        return;
    }

    setVisitedFalse(); // set all nodes to not visited

    cout << "DFS Iter (source): ";
    vStart->visited = true;

    // Use the STL stack to backtrack
    stack<vertex*> s;

    // Push the starting vertex
    s.push(vStart);    // push

    // Need another vertex pointer
    vertex *n;

    while(!s.empty()){
        n = s.top();   // peek 
        cout << n->name;
        s.pop();       // pop

        // scan the adj list of each element in s
        for(int x = 0; x < n->adj.size(); x++)
        {
            // check if vertex visited
            if(n->adj[x].v->visited == false)
            {
                n->adj[x].v->visited = true;
                s.push(n->adj[x].v);
            }
        }
        if(!s.empty()) cout << " -> ";
    }
    cout << "\n\n";
}


void dfs_recursive_helper(vertex* s) 
{
    s->visited = true;
    cout << s->name << " -> ";
    for(int i = 0; i < s->adj.size(); i++) {
        if (s->adj[i].v->visited == false) {
            dfs_recursive_helper(s->adj[i].v);
        }
    }
}

void Graph::depthFirstTraverse_recursive(string sourceVertex){
    // Find the starting vertex
    // Need a pointer to keep track of starting vertex
    vertex *vStart = findVertexPointer(sourceVertex); 
    if(!vStart) {
        cout << "Vertex " << sourceVertex << " does not exist!" << endl;
        return;
    }
    
    setVisitedFalse();

    cout << "DFS Recur (source): ";
    
    dfs_recursive_helper(vStart);
    cout << endl << endl;

}

void bfs_recursive_helper(queue<vertex*> q) 
{
    if (q.empty()) return;

    vertex* s = q.front();
    cout << s->name << " -> ";
    q.pop();

    for(int i = 0; i < s->adj.size(); i++) {
        if (s->adj[i].v->visited == false) {
            s->adj[i].v->visited = true;
            q.push(s->adj[i].v);
        }
    }

    bfs_recursive_helper(q);
}

void Graph::breadthFirstTraverse_recursive(string sourceVertex){
    // Find the starting vertex
    // Need a pointer to keep track of starting vertex
    vertex *vStart = findVertexPointer(sourceVertex); 
    if(!vStart) {
        cout << "Vertex " << sourceVertex << " does not exist!" << endl;
        return;
    }
    
    setVisitedFalse();

    vStart->visited = true;
    queue<vertex*> q;
    q.push(vStart);

    cout << "BFS Recur (source): ";
    bfs_recursive_helper(q);
    cout << endl << endl;

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