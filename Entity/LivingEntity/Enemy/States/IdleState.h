//
// Created by Admin on 13/06/2026.
//

#ifndef BATTLEARENA_IDLESTATE_H
#define BATTLEARENA_IDLESTATE_H


#include "State.h"
class MovingState;
class IdleState : public State {
public:
    IdleState() = default;
    void SetMovingState(MovingState* NewMovingState);
    void SetEnemy(Enemy* enemy) override;
    State * StateUpdate() override;
protected:
    MovingState* movingState;

};


#endif //BATTLEARENA_IDLESTATE_H
