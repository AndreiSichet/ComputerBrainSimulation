#include <iostream>
#include <memory>
#include "Brain.h"
#include "SpeechCenter.h"
#include "MathCenter.h"
#include "LogicCenter.h"
#include "MemoryCenter.h"
#include "FunCenter.h"
using namespace std;
void tellAJoke() {
    cout << "Why did the computer go to the doctor? Because it caught a virus!" << endl;
}

void thinkOfSomethingFun() {
    cout << "Imagine a robot dancing salsa while juggling pizzas!" << endl;
}
int main() {
    Brain brain;
    brain.addCenter("speech", make_unique<SpeechCenter>());
    brain.addCenter("math", make_unique<MathCenter>());
    brain.addCenter("logic", make_unique<LogicCenter>());
    brain.addCenter("memory", make_unique<MemoryCenter>());
    unique_ptr<FunCenter> funCenter = make_unique<FunCenter>();
    funCenter->addFunction("joke", tellAJoke);
    funCenter->addFunction("fun", thinkOfSomethingFun);
    brain.addCenter("fun", move(funCenter));

    cout << "--- DEMO Brain ---" << endl;
    brain.processInput("hello world");    
    brain.processInput("2 + 2");          
    brain.processInput("is 10 > 5?");     
    brain.processInput("remember cats");  
    brain.processInput("joke");          
    brain.processInput("fun");            
    brain.processInput("unknown command"); 

    return 0;
}
