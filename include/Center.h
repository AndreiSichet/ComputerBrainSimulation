#ifndef CENTER_H
#define CENTER_H
#include <string>
using namespace std;
class Center {
public:
    virtual ~Center() = default;
    virtual void process(const string& input) = 0;
    virtual string getName() const = 0;
};

#endif 
