#include "MemoryCenter.h"
#include <iostream>
using namespace std;
void MemoryCenter::process(const string& text) {
    string category = "general"; 
    queue<string>& q = history[category];
    if (q.size() >= maxHistorySize) {
        q.pop(); 
    }
    q.push(text);
    cout << "[MemoryCenter] History: " << category << ": ";
    queue<string> temp = q; 
    while (!temp.empty()) {
        cout << temp.front() << " | ";
        temp.pop();
    }
    cout << endl;
}
string MemoryCenter::getName() const {
    return "MemoryCenter";
}
void MemoryCenter::setMaxHistorySize(size_t size) {
    maxHistorySize = size;
}
