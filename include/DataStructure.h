#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <vector>
#include <string>
using namespace std;

class DataStructure {
public:
    virtual vector<string> insert(int) = 0;
    virtual vector<string> remove(int) = 0;
    virtual string getStructure() = 0;
};

#endif