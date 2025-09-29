#include "SpeechCenter.h"
#include <iostream>
using namespace std;
void SpeechCenter::process(const string& text) {
    if (saidBefore.count(text) > 0) {
        cout << "[SpeechCenter] Already said that: " << text << endl;
    }
    else {
        cout << "[SpeechCenter] You said: " << text << endl;
        saidBefore.insert(text);
    }
}
string SpeechCenter::getName() const {
    return "SpeechCenter";
}
