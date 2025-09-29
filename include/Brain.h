#ifndef BRAIN_H
#define BRAIN_H
#include <string>
#include <unordered_map>
#include <memory>
#include "Center.h"
using namespace std;
class Brain {
private:
    unordered_map<string, unique_ptr<Center>> centers;
public:
    void addCenter(const string& name, unique_ptr<Center> center);
    void processInput(const string& input);
    void listCenters() const;
};

#endif 
