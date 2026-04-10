#ifndef BST_H
#define BST_H

#include "DataStructure.h"
#include <vector>
#include <string>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

class BST : public DataStructure {
    BSTNode* root;

    // Existing
    BSTNode* insertNode(BSTNode*, int, vector<string>&);

    // ✅ ADD THESE
    BSTNode* deleteNode(BSTNode*, int, vector<string>&);
    BSTNode* minValueNode(BSTNode*);

    // ✅ FIX SIGNATURE
    void printTree(BSTNode*, string, bool, string&);

public:
    BST();
    vector<string> insert(int) override;
    vector<string> remove(int) override;
    string getStructure() override;
};

#endif