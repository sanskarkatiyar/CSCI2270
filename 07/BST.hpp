#pragma once
#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
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
        void traverse(int order);
        void print();
};