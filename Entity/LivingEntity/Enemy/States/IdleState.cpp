//
// Created by Admin on 13/06/2026.
//

#include "IdleState.h"
#include "MovingState.h"
#include "../../../../GameManager.h"


void IdleState::SetMovingState(MovingState *NewMovingState) {

}

void IdleState::SetEnemy(Enemy *enemy) {
    State::SetEnemy(enemy);
    if (movingState != nullptr && !movingState->IsEnemySet()) movingState->SetEnemy(enemy);
}

State *IdleState::StateUpdate() {
    if (GameManager::GetInstance().GetDistanceFromClosestPlayer(enemy->GetSprite().getPosition()) < enemy->DetectionRange)
        return movingState;
    return State::StateUpdate();
}
