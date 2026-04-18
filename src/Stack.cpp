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
    vector<int> rev;
    while (!temp.empty()) {
        rev.push_back(temp.top());
        temp.pop();
    }
    stringstream ss;
    ss << "{\"type\": \"stack\", \"nodes\": [";
    for (int i = rev.size() - 1; i >= 0; i--) {
        ss << rev[i];
        if (i > 0) ss << ", ";
    }
    ss << "]}";
    return ss.str();
}