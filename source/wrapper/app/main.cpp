#include <iostream>

#include "foo1.h"


int main(){
    StateMachine machine = StateMachine();
    std::cout << machine.getState() << std::endl;
    machine.nextState();
    std::cout << machine.getState() << std::endl;
    machine.nextState();
    std::cout << machine.getState() << std::endl;
    machine.nextState();
}