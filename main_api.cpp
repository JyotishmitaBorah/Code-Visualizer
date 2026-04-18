#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
#include "AVL.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cout << "Invalid input";
        return 0;
    }

    string type = argv[1];
    vector<string> ops;
    for (int i = 2; i < argc; i++) {
        ops.push_back(argv[i]);
    }

    DataStructure* ds = nullptr;

    if (type == "ll") ds = new LinkedList();
    else if (type == "stack") ds = new StackDS();
    else if (type == "queue") ds = new QueueDS();
    else if (type == "bst") ds = new BST();
    else if (type == "avl") ds = new AVL();

    vector<string> steps;

    for (string op : ops) {
        if (op.empty()) continue;
        char action = op[0];
        int v = stoi(op.substr(1));
        
        vector<string> temp;
        if (action == 'i') {
            temp = ds->insert(v);
        } else if (action == 'd') {
            temp = ds->remove(v);
        }
        steps.insert(steps.end(), temp.begin(), temp.end());
    }

    // Inject steps as a "messages" array into the JSON structure
    string structJson = ds->getStructure();
    
    // Find the last closing brace
    size_t lastBrace = structJson.find_last_of('}');
    if (lastBrace != string::npos) {
        structJson.erase(lastBrace);
        
        structJson += ", \"messages\": [";
        for (size_t i = 0; i < steps.size(); i++) {
            structJson += "\"" + steps[i] + "\"";
            if (i < steps.size() - 1) structJson += ", ";
        }
        structJson += "]}";
    }

    cout << structJson;

    delete ds;
    return 0;
}