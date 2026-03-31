#ifndef AVL_H
#define AVL_H

#include "DataStructure.h"
#include <vector>
#include <string>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

class AVL : public DataStructure {
private:
    AVLNode* root;

public:
    AVL();
    vector<string> insert(int x) override;
    vector<string> remove(int x) override;
    string getStructure() override;
};

#endif