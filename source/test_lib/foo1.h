#ifndef ___FOO1_H___
#define ___FOO1_H___

class StateMachine
{
    public:
        enum State
        {
            initializing,
            active,
            error,
        };
        StateMachine();
        void nextState();
        State getState();
    private:
        State mState;
};


#endif