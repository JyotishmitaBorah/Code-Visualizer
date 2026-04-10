#include "../include/BST.h"
#include <iostream>
using namespace std;

BST::BST() {
    root = NULL;
}

// ================= INSERT =================
BSTNode* BST::insertNode(BSTNode* node, int x, vector<string>& steps) {
    if (!node) {
        steps.push_back("Inserted " + to_string(x));
        return new BSTNode{x, NULL, NULL};
    }

    if (x < node->data) {
        steps.push_back("Go Left from " + to_string(node->data));
        node->left = insertNode(node->left, x, steps);
    } else {
        steps.push_back("Go Right from " + to_string(node->data));
        node->right = insertNode(node->right, x, steps);
    }

    return node;
}

vector<string> BST::insert(int x) {
    vector<string> steps;
    root = insertNode(root, x, steps);
    return steps;
}

// ================= DELETE =================
BSTNode* BST::minValueNode(BSTNode* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

BSTNode* BST::deleteNode(BSTNode* node, int key, vector<string>& steps) {
    if (!node) return node;

    if (key < node->data) {
        steps.push_back("Go Left from " + to_string(node->data));
        node->left = deleteNode(node->left, key, steps);
    }
    else if (key > node->data) {
        steps.push_back("Go Right from " + to_string(node->data));
        node->right = deleteNode(node->right, key, steps);
    }
    else {
        steps.push_back("Deleted " + to_string(key));

        // One child or no child
        if (!node->left) return node->right;
        else if (!node->right) return node->left;

        // Two children
        BSTNode* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data, steps);
    }

    return node;
}

vector<string> BST::remove(int x) {
    vector<string> steps;
    root = deleteNode(root, x, steps);
    return steps;
}

// ================= PRINT TREE =================
void BST::printTree(BSTNode* node, string prefix, bool isLeft, string& res) {
    if (!node) return;

    res += prefix;

    if (prefix != "") {
        res += (isLeft ? "/-- " : "\\-- ");
    }

    res += to_string(node->data) + "\n";

    printTree(node->left, prefix + (isLeft ? "|   " : "    "), true, res);
    printTree(node->right, prefix + (isLeft ? "|   " : "    "), false, res);
}

// ================= STRUCTURE =================
string BST::getStructure() {
    if (!root) return "Empty BST";

    string res = "";
    printTree(root, "", false, res);
    return res;
}