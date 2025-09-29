#ifndef SPEECHCENTER_H
#define SPEECHCENTER_H
#include "Center.h"
#include <string>
#include <unordered_set>
using namespace std;
class SpeechCenter : public Center {
private:
    unordered_set<string> saidBefore;
public:
    SpeechCenter() = default;
    ~SpeechCenter() = default;
    void process(const string& text) override;
    string getName() const override;
};

#endif 
