#include "../include/Stack.h"
#include <sstream>

vector<string> StackDS::insert(int x) {
    st.push(x);
    return {"Pushed " + to_string(x)};
}

vector<string> StackDS::remove(int) {
    if (st.empty()) return {"Empty stack"};

    int v = st.top();
    st.pop();
    return {"Popped " + to_string(v)};
}

string StackDS::getStructure() {
    stack<int> temp = st;
    stringstream ss;

    ss << "Top\n";
    while (!temp.empty()) {
        ss << "| " << temp.top() << " |\n";
        temp.pop();
    }
    return ss.str();
}