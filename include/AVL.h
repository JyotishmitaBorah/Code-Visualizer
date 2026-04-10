#ifndef AVL_H
#define AVL_H

#include "DataStructure.h"
#include <vector>
#include <string>
using namespace std;

struct AVLNode {
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;
};

class AVL : public DataStructure {
private:
    AVLNode* root;

    int getHeight(AVLNode*);
    int getBalance(AVLNode*);
    AVLNode* insertNode(AVLNode*, int, vector<string>&);
    AVLNode* deleteNode(AVLNode*, int, vector<string>&);

    AVLNode* leftRotate(AVLNode*);
    AVLNode* rightRotate(AVLNode*);
    AVLNode* minValueNode(AVLNode*);

    void build(AVLNode*, string, bool, string&);

public:
    AVL();

    vector<string> insert(int);
    vector<string> remove(int);

    string getStructure();
};

#endif