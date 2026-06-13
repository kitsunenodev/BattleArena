//
// Created by Admin on 13/06/2026.
//

#include "IdleState.h"
#include "MovingState.h"
#include "../../../../GameManager.h"


void IdleState::SetMovingState(MovingState *NewMovingState) {
    movingState = NewMovingState;
}

void IdleState::SetEnemy(Enemy *enemy) {
    State::SetEnemy(enemy);
    if (movingState != nullptr && !movingState->IsEnemySet()) movingState->SetEnemy(enemy);
}

State *IdleState::StateUpdate() {
    if (GameManager::GetInstance().GetDistanceFromClosestPlayer(enemy->GetSprite().getPosition(), enemy->CurrentTarget) < enemy->DetectionRange
    && GameManager::GetInstance().GetDistanceBetweenEntities(enemy->GetSprite().getPosition(), enemy->CurrentTarget->GetSprite().getPosition()) > enemy->ShootingRangeMax)
        return movingState;
    if (enemy->CurrentTarget != nullptr && GameManager::GetInstance().GetDistanceBetweenEntities(
            enemy->GetSprite().getPosition(), enemy->CurrentTarget->GetSprite().getPosition()) < enemy->ShootingRangeMax){
        enemy->Shoot();
    }

    return State::StateUpdate();
}
