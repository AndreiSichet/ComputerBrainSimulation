#ifndef LOGICCENTER_H
#define LOGICCENTER_H
#include "Center.h"
#include <string>
#include <memory>
using namespace std;
struct LogicNode {
    string value;                 
    shared_ptr<LogicNode> left;
    shared_ptr<LogicNode> right;
    LogicNode(const string& val) : value(val), left(nullptr), right(nullptr) {}
};
class LogicCenter : public Center {
public:
    LogicCenter() = default;
    ~LogicCenter() = default;
    void process(const string& text) override;
    string getName() const override;
private:
    shared_ptr<LogicNode> buildTree(const string& expr);
    bool evaluateTree(shared_ptr<LogicNode> node);
};

#endif 
