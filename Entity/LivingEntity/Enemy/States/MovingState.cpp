//
// Created by Admin on 13/06/2026.
//

#include "MovingState.h"
#include "IdleState.h"
#include "../../../../GameManager.h"


void MovingState::SetIdleState(IdleState* NewIdleState){
    this->idleState = NewIdleState;
}

void MovingState::SetEnemy(Enemy *enemy) {
    State::SetEnemy(enemy);
    if (idleState != nullptr && !idleState->IsEnemySet()) idleState->SetEnemy(enemy);
}

State *MovingState::StateUpdate() {
    if (GameManager::GetInstance().GetDistanceFromClosestPlayer(enemy->GetSprite().getPosition(), enemy->CurrentTarget) > enemy->DetectionRange
    || (GameManager::GetInstance().GetDistanceFromClosestPlayer(enemy->GetSprite().getPosition(), enemy->CurrentTarget) < enemy->ShootingRangeMin))
        return idleState;
    if (enemy->CurrentTarget != nullptr){
        enemy->Move(enemy->CurrentTarget->GetSprite().getPosition().x - enemy->GetSprite().getPosition().x,
                    enemy->CurrentTarget->GetSprite().getPosition().y - enemy->GetSprite().getPosition().y,
                    GameManager::GetInstance().deltaTime);
    }
    return State::StateUpdate();
}
