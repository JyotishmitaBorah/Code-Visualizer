#ifndef STACK_H
#define STACK_H

#include "DataStructure.h"
#include <stack>

class StackDS : public DataStructure {
    stack<int> st;

public:
    vector<string> insert(int) override;
    vector<string> remove(int) override;
    string getStructure() override;
};

#endif