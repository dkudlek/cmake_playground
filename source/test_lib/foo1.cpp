#include "foo1.h"

StateMachine::StateMachine():mState(State::initializing){}

void StateMachine::nextState(){
    if (State::initializing == mState){
        mState = State::active;
    }else if (State::active == mState){
        mState = State::initializing;
    }else {
        mState = State::error;
    }
}

StateMachine::State StateMachine::getState(){
    return mState;
}