#ifndef MEMORYCENTER_H
#define MEMORYCENTER_H
#include "Center.h"
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class MemoryCenter : public Center {
private:
    unordered_map<string, queue<string>> history;
    size_t maxHistorySize = 5;
public:
    MemoryCenter() = default;
    ~MemoryCenter() = default;
    void process(const string& text) override;
    string getName() const override;
    void setMaxHistorySize(size_t size);
};

#endif 
