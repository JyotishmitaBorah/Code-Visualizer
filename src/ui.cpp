#include <iostream>
#include <vector>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showHeader() {
    cout << "===== INTERACTIVE CODE VISUALIZER =====\n";
}

void displaySteps(vector<string> steps) {
    cout << "\nSteps:\n";
    for (auto s : steps)
        cout << "-> " << s << endl;
}

void displayStructure(string s) {
    cout << "\nStructure:\n" << s << endl;
}