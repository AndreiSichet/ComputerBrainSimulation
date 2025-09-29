#include "LogicCenter.h"
#include <iostream>
#include <sstream>
#include<vector>
#include<stack>
using namespace std;
void LogicCenter::process(const string& text) {
    cout << "[LogicCenter] Evaluating: " << text << endl;
    shared_ptr<LogicNode> root = buildTree(text);
    if (!root) {
        cout << "[LogicCenter] Invalid expression!" << endl;
        return;
    }
    bool result = evaluateTree(root);
    cout << "[LogicCenter] Result: " << (result ? "TRUE" : "FALSE") << endl;
}
string LogicCenter::getName() const {
    return "LogicCenter";
}
shared_ptr<LogicNode> LogicCenter::buildTree(const string& expr) {
    vector<string> output;
    stack<string> ops;
    istringstream iss(expr);
    string token;

    while (iss >> token) {
        if (token == "TRUE" || token == "FALSE") {
            output.push_back(token);
        }
        else if (token == "AND" || token == "OR" || token == "NOT") {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                output.push_back(ops.top());
                ops.pop();
            }
            ops.push(token);
        }
        else if (token == "(") {
            ops.push(token);
        }
        else if (token == ")") {
            while (!ops.empty() && ops.top() != "(") {
                output.push_back(ops.top());
                ops.pop();
            }
            if (!ops.empty()) ops.pop(); 
        }
    }

    while (!ops.empty()) {
        output.push_back(ops.top());
        ops.pop();
    }
    stack<shared_ptr<LogicNode>> st;
    for (auto& tok : output) {
        if (tok == "TRUE" || tok == "FALSE") {
            st.push(make_shared<LogicNode>(tok));
        }
        else if (tok == "NOT") {
            auto node = make_shared<LogicNode>(tok);
            node->right = st.top(); st.pop();
            st.push(node);
        }
        else if (tok == "AND" || tok == "OR") {
            auto node = make_shared<LogicNode>(tok);
            auto right = st.top(); st.pop();
            auto left = st.top(); st.pop();
            node->left = left;
            node->right = right;
            st.push(node);
        }
    }

    if (!st.empty()) return st.top();
    return nullptr;
}

bool LogicCenter::evaluateTree(shared_ptr<LogicNode> node) {
    if (!node) return false;

    string val = node->value;
    if (val == "TRUE") return true;
    if (val == "FALSE") return false;
    if (val == "NOT") return !evaluateTree(node->right);
    if (val == "AND") return evaluateTree(node->left) && evaluateTree(node->right);
    if (val == "OR") return evaluateTree(node->left) || evaluateTree(node->right);

    return false;
}
