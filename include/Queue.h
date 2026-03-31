#ifndef QUEUE_H
#define QUEUE_H

#include "DataStructure.h"
#include <queue>

class QueueDS : public DataStructure {
    queue<int> q;

public:
    vector<string> insert(int) override;
    vector<string> remove(int) override;
    string getStructure() override;
};

#endif