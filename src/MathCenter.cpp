#include "MathCenter.h"
#include <iostream>
#include <cctype>
using namespace std;
void MathCenter::process(const string& text) {
    cout << "[MathCenter] Calculating: " << text << endl;
    int result = evaluateExpression(text);
    cout << "[MathCenter] Result: " << result << endl;
}
string MathCenter::getName() const {
    return "MathCenter";
}
int MathCenter::evaluateExpression(const string& expr) {
    stack<int> values;       
    stack<char> ops;         
    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (isdigit(c)) {
            int val = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            i--; 
            values.push(val);
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            if (!ops.empty()) ops.pop(); 
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperator(a, b, op));
    }

    return values.top();
}

int MathCenter::applyOperator(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b != 0 ? a / b : 0; 
    }
    return 0;
}

int MathCenter::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
