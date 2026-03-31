#include <string>
using namespace std;

struct Command {
    string action;
    int value;
    string ds;
};

Command parse(string input) {
    Command cmd;
    // simple placeholder
    cmd.action = "insert";
    cmd.value = 10;
    cmd.ds = "linkedlist";
    return cmd;
}