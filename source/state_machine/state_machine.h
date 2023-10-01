#ifndef ___STATE_MACHINE_H___
#define ___STATE_MACHINE_H___

#if defined(_WIN32) && defined(BUILD_SHARED)
#if defined(EXPORTING_STATE_MACHINE)
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif
#else // non windows
#define DECLSPEC
#endif

namespace testbed {

enum class State {
  inactive,
  ready,
  active,
  error,
};

class DECLSPEC StateMachine {
public:
  StateMachine();
  void setEngineState(bool state);
  void setActuationState(bool state);
  State getState() const;
  void step();

private:
  State mState = State::inactive;
  bool mEngineState = false;
  bool mActuationState = false;
};

} // namespace testbed
#endif