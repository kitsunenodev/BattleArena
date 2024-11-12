//
// Created by f.collet on 31/10/2024.
//

#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H
#include "../Entity.h"


class LivingEntity : public Entity {
protected:
    int maxHealth;
    int currentHealth;
    int armorPoint;

public:
    LivingEntity(const std::string &filename, int maxHealth, int armor, float speed);
    void TakeDamage(int damageAmount);
};



#endif //LIVINGENTITY_H
