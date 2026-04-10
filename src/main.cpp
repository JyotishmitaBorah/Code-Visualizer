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

        cout << "\nSelect Data Structure:\n";
        cout << "1. Linked List\n2. Stack\n3. Queue\n4. BST\n5. AVL\n6. Exit\nChoice: ";

        int ds;
        cin >> ds;

        if (ds == 6) break;

        while (true) {
            clearScreen();
            showHeader();

            // 🔥 Dynamic menu based on DS
            if (ds == 2) {
                cout << "\n1. Push\n2. Pop\n3. Back\nChoice: ";
            }
            else if (ds == 3) {
                cout << "\n1. Enqueue\n2. Dequeue\n3. Back\nChoice: ";
            }
            else {
                cout << "\n1. Insert\n2. Delete\n3. Back\nChoice: ";
            }

            int op;
            cin >> op;

            if (op == 3) break;

            vector<string> steps;
            string structure;

            // 🔥 Handle operations properly
            switch (ds) {

                case 1: { // Linked List
                    int val;
                    cout << "Enter value: ";
                    cin >> val;
                    steps = (op==1)?ll.insert(val):ll.remove(val);
                    structure = ll.getStructure();
                    break;
                }

                case 2: { // Stack
                    if (op == 1) {
                        int val;
                        cout << "Enter value: ";
                        cin >> val;
                        steps = st.insert(val); // push
                    } else {
                        steps = st.remove(0); // pop (no input needed)
                    }
                    structure = st.getStructure();
                    break;
                }

                case 3: { // Queue
                    if (op == 1) {
                        int val;
                        cout << "Enter value: ";
                        cin >> val;
                        steps = q.insert(val); // enqueue
                    } else {
                        steps = q.remove(0); // dequeue
                    }
                    structure = q.getStructure();
                    break;
                }

                case 4: { // BST
                    int val;
                    cout << "Enter value: ";
                    cin >> val;
                    steps = (op==1)?bst.insert(val):bst.remove(val);
                    structure = bst.getStructure();
                    break;
                }

                case 5: { // AVL
                    int val;
                    cout << "Enter value: ";
                    cin >> val;
                    steps = (op==1)?avl.insert(val):avl.remove(val);
                    structure = avl.getStructure();
                    break;
                }
            }

            displaySteps(steps);
            displayStructure(structure);

            cout << "\nPress Enter...";
            cin.ignore();
            cin.get();
        }
    }
}