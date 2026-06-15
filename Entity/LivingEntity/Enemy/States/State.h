//
// Created by Admin on 13/06/2026.
//

#ifndef BATTLEARENA_STATE_H
#define BATTLEARENA_STATE_H

class Enemy;

//Base Class for the State for the State Machine pattern
class State {
public:
    virtual State* StateUpdate();
    virtual void SetEnemy(Enemy* enemy);
    bool IsEnemySet();

protected:
    Enemy* enemy;
};


#endif //BATTLEARENA_STATE_H
