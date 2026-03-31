#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "DataStructure.h"

struct Node {
    int data;
    Node* next;
};

class LinkedList : public DataStructure {
    Node* head;

public:
    LinkedList();
    vector<string> insert(int) override;
    vector<string> remove(int) override;
    string getStructure() override;
};

#endif