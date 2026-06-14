//
// Created by f.collet on 12/11/2024.
//

#include <iostream>
#include "EnemyFactory.h"

#include "ArmoredEnemy.h"
#include "FastEnemy.h"
#include "RegularEnemy.h"
#include "../../../GameManager.h"

Enemy *EnemyFactory::CreateEnemy(EnemyType type, sf::Vector2u vector2U) {
    Enemy* enemy;
    auto* WalkingState = new MovingState();
    auto* idleState = new IdleState();
    WalkingState->SetIdleState(idleState);
    idleState->SetMovingState(WalkingState);
    switch (type) {
        case FAST:
            enemy = new FastEnemy(GameManager::GetInstance().spriteManager.enemySprites[1],
                                  GameManager::GetInstance().EnemyValues.find(REGULAR)->second.maxHealth,
                                  GameManager::GetInstance().EnemyValues.find(REGULAR)->second.armorPoint,
                                  GameManager::GetInstance().EnemyValues.find(REGULAR)->second.speed,
                                  idleState);
            break;

        case ARMORED:
            enemy = new ArmoredEnemy(GameManager::GetInstance().spriteManager.enemySprites[2],
                                     GameManager::GetInstance().EnemyValues.find(REGULAR)->second.maxHealth,
                                     GameManager::GetInstance().EnemyValues.find(REGULAR)->second.armorPoint,
                                     GameManager::GetInstance().EnemyValues.find(REGULAR)->second.speed,
                                     idleState);
            break;

        default:
            enemy = new RegularEnemy(GameManager::GetInstance().spriteManager.enemySprites[0],
                                         GameManager::GetInstance().EnemyValues.find(REGULAR)->second.maxHealth,
                                         GameManager::GetInstance().EnemyValues.find(REGULAR)->second.armorPoint,
                                         GameManager::GetInstance().EnemyValues.find(REGULAR)->second.speed,
                                         idleState);
            break;
    }
    WalkingState->SetEnemy(enemy);
    enemy->SetPosition(vector2U.x, vector2U.y);
    return enemy;
}

