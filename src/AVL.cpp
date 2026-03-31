#include "../include/AVL.h"
#include <algorithm>

using namespace std;

int getHeight(AVLNode* n) {
    return n ? n->height : 0;
}

AVLNode* createNode(int x) {
    return new AVLNode{x, NULL, NULL, 1};
}

AVLNode* insertNode(AVLNode* node, int x, vector<string>& steps) {
    if (!node) {
        steps.push_back("Inserted " + to_string(x));
        return createNode(x);
    }

    if (x < node->data)
        node->left = insertNode(node->left, x, steps);
    else
        node->right = insertNode(node->right, x, steps);

    return node; // simplified (no rotations for now)
}

AVL::AVL() {
    root = NULL;
}

vector<string> AVL::insert(int x) {
    vector<string> steps;
    root = insertNode(root, x, steps);
    return steps;
}

vector<string> AVL::remove(int) {
    return {"Delete not implemented"};
}

string AVL::getStructure() {
    return "AVL working (basic)";
}