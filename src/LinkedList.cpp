#include "../include/LinkedList.h"
#include <sstream>

LinkedList::LinkedList() { head = NULL; }

vector<string> LinkedList::insert(int x) {
    vector<string> steps;
    Node* n = new Node{x, NULL};

    if (!head) {
        head = n;
        steps.push_back("Inserted at head");
    } else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        steps.push_back("Inserted at end");
    }
    return steps;
}

vector<string> LinkedList::remove(int x) {
    if (!head) return {"Empty list"};

    if (head->data == x) {
        head = head->next;
        return {"Deleted head"};
    }

    Node* t = head;
    while (t->next && t->next->data != x)
        t = t->next;

    if (t->next) {
        t->next = t->next->next;
        return {"Deleted node"};
    }

    return {"Not found"};
}

string LinkedList::getStructure() {
    stringstream ss;
    Node* t = head;

    while (t) {
        ss << t->data << " -> ";
        t = t->next;
    }
    ss << "NULL";

    return ss.str();
}