#ifndef ___STATE_MACHINE_H___
#define ___STATE_MACHINE_H___

namespace testbed {

enum class State {
  inactive,
  ready,
  active,
  error,
};

class StateMachine {
public:
  StateMachine();
  void setEngineState(bool state);
  void setActuationState(bool state);
  State getState() const;
  void step();

private:
  State mState= State::inactive;
  bool mEngineState=false;
  bool mActuationState=false;
};

} // namespace testbed
#endif