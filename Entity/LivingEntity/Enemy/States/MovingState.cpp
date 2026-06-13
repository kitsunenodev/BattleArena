//
// Created by Admin on 13/06/2026.
//

#include "MovingState.h"
#include "IdleState.h"


void MovingState::SetIdleState(IdleState* NewIdleState){
    this->idleState = NewIdleState;
}

void MovingState::SetEnemy(Enemy *enemy) {
    State::SetEnemy(enemy);
    if (idleState != nullptr && !idleState->IsEnemySet()) idleState->SetEnemy(enemy);
}

State *MovingState::StateUpdate() {
    if (GameManager::GetInstance().GetDistanceFromClosestPlayer(enemy->GetSprite().getPosition()) > enemy->DetectionRange
    || (GameManager::GetInstance().GetDistanceFromClosestPlayer(enemy->GetSprite().getPosition()) < enemy->ShootingRangeMin))
        return idleState;
    return State::StateUpdate();
}
