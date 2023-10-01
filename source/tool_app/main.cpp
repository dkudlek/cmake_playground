#include <iostream>

#include "state_machine.h"

namespace tb = testbed;

std::string print(tb::State state) {
  if (tb::State::inactive == state) {
    return "inactive";
  } else if (tb::State::ready == state) {
    return "ready";
  } else if (tb::State::active == state) {
    return "active";
  }
  if (tb::State::error == state) {
    return "error";
  }
  return "NOP";
}

int main() {
  tb::StateMachine machine = tb::StateMachine();
  std::cout << print(machine.getState()) << std::endl;
  machine.setEngineState(true);
  std::cout << print(machine.getState()) << std::endl;
  machine.setActuationState(true);
  std::cout << print(machine.getState()) << std::endl;
}
