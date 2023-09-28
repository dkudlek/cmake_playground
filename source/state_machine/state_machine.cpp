#include "state_machine.h"

namespace tb = testbed;

tb::StateMachine::StateMachine() {}

void tb::StateMachine::step() {
  if (State::inactive == mState) {
    if (mEngineState) {
      mState = State::ready;
    }
  } else if (State::ready == mState) {
    if (mActuationState) {
      mState = State::active;
    }
  } else if (State::active == mState) {
    if (!mEngineState) {
      mState = State::error;
    } else if (!mActuationState) {
      mState = State::ready;
    }
  } else if (State::error == mState) {
    if (mEngineState) {
      mState = State::inactive;
    }
  }
}

void tb::StateMachine::setEngineState(bool state) { mEngineState = state; }

void tb::StateMachine::setActuationState(bool state) {
  mActuationState = state;
}

tb::State tb::StateMachine::getState() const { return mState; }
