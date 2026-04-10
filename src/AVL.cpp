#include "../include/AVL.h"
#include <algorithm>
using namespace std;

// CONSTRUCTOR
AVL::AVL() {
    root = NULL;
}

// HEIGHT
int AVL::getHeight(AVLNode* node) {
    if (!node) return 0;
    return node->height;
}

// BALANCE
int AVL::getBalance(AVLNode* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// RIGHT ROTATION
AVLNode* AVL::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// LEFT ROTATION
AVLNode* AVL::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// MIN VALUE NODE
AVLNode* AVL::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

// INSERT
AVLNode* AVL::insertNode(AVLNode* node, int x, vector<string>& steps) {
    if (!node) {
        steps.push_back("Inserted " + to_string(x));
        return new AVLNode{x, 1, NULL, NULL};
    }

    if (x < node->data) {
        steps.push_back("Go Left from " + to_string(node->data));
        node->left = insertNode(node->left, x, steps);
    } else {
        steps.push_back("Go Right from " + to_string(node->data));
        node->right = insertNode(node->right, x, steps);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && x < node->left->data) {
        steps.push_back("Right Rotation");
        return rightRotate(node);
    }

    // RR
    if (balance < -1 && x > node->right->data) {
        steps.push_back("Left Rotation");
        return leftRotate(node);
    }

    // LR
    if (balance > 1 && x > node->left->data) {
        steps.push_back("Left-Right Rotation");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && x < node->right->data) {
        steps.push_back("Right-Left Rotation");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

vector<string> AVL::insert(int x) {
    vector<string> steps;
    root = insertNode(root, x, steps);
    return steps;
}

// DELETE
AVLNode* AVL::deleteNode(AVLNode* node, int x, vector<string>& steps) {
    if (!node) return node;

    if (x < node->data) {
        node->left = deleteNode(node->left, x, steps);
    }
    else if (x > node->data) {
        node->right = deleteNode(node->right, x, steps);
    }
    else {
        steps.push_back("Deleted " + to_string(x));

        // one or zero child
        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }

        // two children
        AVLNode* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data, steps);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // balance after delete
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

vector<string> AVL::remove(int x) {
    vector<string> steps;
    root = deleteNode(root, x, steps);
    return steps;
}

// TREE PRINT (clean + branches)
void AVL::build(AVLNode* node, string prefix, bool isLeft, string& result) {
    if (!node) return;

    result += prefix;
    result += (isLeft ? "|-- " : "\\-- ");
    result += to_string(node->data) + "\n";

    build(node->left, prefix + (isLeft ? "|   " : "    "), true, result);
    build(node->right, prefix + (isLeft ? "|   " : "    "), false, result);
}

// FINAL STRUCTURE
string AVL::getStructure() {
    if (!root) return "Empty AVL";

    string result = to_string(root->data) + "\n";
    build(root->left, "", true, result);
    build(root->right, "", false, result);

    return result;
}