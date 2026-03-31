#include "../include/BST.h"
#include <sstream>

BST::BST() { root = NULL; }

BSTNode* BST::insertNode(BSTNode* node, int x, vector<string>& steps) {
    if (!node) {
        steps.push_back("Inserted " + to_string(x));
        return new BSTNode{x, NULL, NULL};
    }

    if (x < node->data)
        node->left = insertNode(node->left, x, steps);
    else
        node->right = insertNode(node->right, x, steps);

    return node;
}

vector<string> BST::insert(int x) {
    vector<string> steps;
    root = insertNode(root, x, steps);
    return steps;
}

vector<string> BST::remove(int) {
    return {"Delete not implemented"};
}

string BST::getStructure() {
    return "BST working (tree UI optional)";
}