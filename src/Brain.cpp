#include "Brain.h"
#include <iostream>
using namespace std;
void Brain::addCenter(const string& name, unique_ptr<Center> center) {
    centers[name] = move(center);
}
void Brain::processInput(const string& input) {
    for (auto& kv : centers) {
        if (input.find(kv.first) != string::npos) {
            kv.second->process(input);
            return;
        }
    }
    cout << "[Brain] Did not find the correct input: " << input << endl;
}
void Brain::listCenters() const {
    cout << "[Brain] Available centers:" << endl;
    for (const auto& pair : centers) {
        cout << " - " << pair.first << endl;
    }
}
