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

    ss << "Front -> ";
    while (!temp.empty()) {
        ss << temp.front() << " ";
        temp.pop();
    }
    ss << "<- Rear";

    return ss.str();
}