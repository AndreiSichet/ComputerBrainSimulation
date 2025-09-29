#include "FunCenter.h"
#include <iostream>
using namespace std;
void FunCenter::process(const string& text) {
    for (size_t i = 0; i < funcNames.size(); i++) {
        if (funcNames[i] == text) {
            cout << "[FunCenter] Executing: " << text << endl;
            funcPtrs[i]();  
            return;
        }
    }
    cout << "[FunCenter] Function does not exist: " << text << endl;
}
string FunCenter::getName() const {
    return "FunCenter";
}
void FunCenter::addFunction(const string& name, FuncPtr func) {
    funcNames.push_back(name);
    funcPtrs.push_back(func);
}
