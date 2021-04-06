#pragma once
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class BST {
    private:
        Node* root;

    public:
        BST();
        ~BST();
        int search(int key);
        void insert(int key);
        void remove(int key);
        void traverse(int order);
        int find_max();
        int find_min();
        void print();
};