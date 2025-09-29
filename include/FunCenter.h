#ifndef FUNCENTER_H
#define FUNCENTER_H
#include "Center.h"
#include <string>
#include <vector>
using namespace std;
typedef void(*FuncPtr)();
class FunCenter : public Center {
private:
    vector<string> funcNames;  
    vector<FuncPtr> funcPtrs;  
public:
    FunCenter() = default;
    ~FunCenter() = default;
    void process(const string& text) override;
    string getName() const override;
    void addFunction(const string& name, FuncPtr func);
};

#endif 
