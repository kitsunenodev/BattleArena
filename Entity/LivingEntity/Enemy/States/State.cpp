//
// Created by Admin on 13/06/2026.
//

#include "State.h"

void State::SetEnemy(Enemy *enemy) {
    this->enemy = enemy;
}

State *State::StateUpdate() {
    return this;
}

bool State::IsEnemySet() {
    return enemy != nullptr;
}
