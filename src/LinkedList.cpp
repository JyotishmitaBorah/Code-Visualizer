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
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return {"Deleted head"};
    }

    Node* t = head;
    while (t->next && t->next->data != x)
        t = t->next;

    if (t->next) {
        Node* toDelete = t->next;
        t->next = t->next->next;
        delete toDelete;
        return {"Deleted node"};
    }

    return {"Not found"};
}

string LinkedList::getStructure() {
    stringstream ss;
    ss << "{\"type\": \"linkedlist\", \"nodes\": [";
    Node* t = head;
    while (t) {
        ss << t->data;
        if (t->next) ss << ", ";
        t = t->next;
    }
    ss << "]}";
    return ss.str();
}