#include "../include/Queue.h"
#include <sstream>

vector<string> QueueDS::insert(int x) {
    q.push(x);
    return {"Enqueued " + to_string(x)};
}

vector<string> QueueDS::remove(int) {
    if (q.empty()) return {"Empty queue"};

    int v = q.front();
    q.pop();
    return {"Dequeued " + to_string(v)};
}

string QueueDS::getStructure() {
    queue<int> temp = q;
    stringstream ss;
    ss << "{\"type\": \"queue\", \"nodes\": [";
    bool first = true;
    while (!temp.empty()) {
        if (!first) ss << ", ";
        ss << temp.front();
        temp.pop();
        first = false;
    }
    ss << "]}";
    return ss.str();
}