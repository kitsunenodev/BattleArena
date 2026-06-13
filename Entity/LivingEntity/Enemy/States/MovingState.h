//
// Created by Admin on 13/06/2026.
//

#ifndef BATTLEARENA_MOVINGSTATE_H
#define BATTLEARENA_MOVINGSTATE_H


#include "State.h"

class IdleState;

class MovingState : public State{
public:
    MovingState() = default;
    void SetIdleState(IdleState* NewIdleState);
    void SetEnemy(Enemy *enemy) override;
    State * StateUpdate() override;

protected:
    IdleState* idleState;

};


#endif //BATTLEARENA_MOVINGSTATE_H
