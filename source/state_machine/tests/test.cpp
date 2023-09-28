#include <gtest/gtest.h>
#include <state_machine/state_machine.h>

namespace tb = testbed;

TEST(state_machine_test, cycle) {
  auto machine = tb::StateMachine();
  EXPECT_EQ(tb::State::inactive, machine.getState());
  machine.setEngineState(true);
  machine.step();
  EXPECT_EQ(tb::State::ready, machine.getState());
  machine.setActuationState(true);
  machine.step();
  EXPECT_EQ(tb::State::active, machine.getState());
  machine.setActuationState(false);
  machine.step();
  EXPECT_EQ(tb::State::ready, machine.getState());
  machine.setActuationState(true);
  machine.step();
  EXPECT_EQ(tb::State::active, machine.getState());
  machine.setEngineState(false);
  machine.step();
  EXPECT_EQ(tb::State::error, machine.getState());
  machine.setEngineState(true);
  machine.step();
  EXPECT_EQ(tb::State::inactive, machine.getState());
}
