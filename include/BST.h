#ifndef BST_H
#define BST_H

#include "DataStructure.h"

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

class BST : public DataStructure {
    BSTNode* root;

    BSTNode* insertNode(BSTNode*, int, vector<string>&);

public:
    BST();
    vector<string> insert(int) override;
    vector<string> remove(int) override;
    string getStructure() override;
};

#endif