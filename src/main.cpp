#include <iostream>
#include <vector>
#include "../include/LinkedList.h"
#include "../include/Stack.h"
#include "../include/Queue.h"
#include "../include/BST.h"
#include "../include/AVL.h"

using namespace std;

void clearScreen();
void showHeader();
void displaySteps(vector<string>);
void displayStructure(string);

int main() {
    LinkedList ll;
    StackDS st;
    QueueDS q;
    BST bst;
    AVL avl;

    while (true) {
        clearScreen();
        showHeader();

        cout << "\n1. Linked List\n2. Stack\n3. Queue\n4. BST\n5. AVL\n6. Exit\nChoice: ";
        int ds; cin >> ds;

        if (ds == 6) break;

        while (true) {
            cout << "\n1. Insert\n2. Delete\n3. Back\nChoice: ";
            int op; cin >> op;

            if (op == 3) break;

            int val;
            cout << "Enter value: ";
            cin >> val;

            vector<string> steps;
            string structure;

            switch (ds) {
                case 1: steps = (op==1)?ll.insert(val):ll.remove(val); structure = ll.getStructure(); break;
                case 2: steps = (op==1)?st.insert(val):st.remove(val); structure = st.getStructure(); break;
                case 3: steps = (op==1)?q.insert(val):q.remove(val); structure = q.getStructure(); break;
                case 4: steps = (op==1)?bst.insert(val):bst.remove(val); structure = bst.getStructure(); break;
                case 5: steps = (op==1)?avl.insert(val):avl.remove(val); structure = avl.getStructure(); break;
            }

            displaySteps(steps);
            displayStructure(structure);
        }
    }
}