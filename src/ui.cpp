#include <iostream>
#include <vector>
using namespace std;

// CLEAR SCREEN
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// HEADER
void showHeader() {
    cout << "===== INTERACTIVE CODE VISUALIZER =====\n";
    cout << "--------------------------------------\n";
}

// SHOW STEPS
void displaySteps(vector<string> steps) {
    cout << "\nSteps:\n";
    for (auto s : steps)
        cout << "-> " << s << endl;
}

// SHOW STRUCTURE (WORKS FOR ALL DS)
void displayStructure(string s) {
    cout << "\nStructure:\n";
    cout << "----------------\n";

    // 👉 For stack/queue/LL → string comes
    if (s != "")
        cout << s << endl;

    // 👉 For BST/AVL → already printed inside function

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}