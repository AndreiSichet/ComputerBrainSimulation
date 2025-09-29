#ifndef MATHCENTER_H
#define MATHCENTER_H
#include "Center.h"
#include <string>
#include <stack>
#include <deque>
using namespace std;
class MathCenter : public Center {
public:
    MathCenter() = default;
    ~MathCenter() = default;
    void process(const string& text) override;
    string getName() const override;
private:
    int evaluateExpression(const string& expr);
    int applyOperator(int a, int b, char op);
    int precedence(char op);
};

#endif 
