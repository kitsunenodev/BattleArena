//
// Created by f.collet on 07/11/2024.
//

#ifndef EXPLOSIVEAMMO_H
#define EXPLOSIVEAMMO_H
#include "Ammunition.h"


class ExplosiveAmmo: public Ammunition{
public:
    ExplosiveAmmo();
    void Update() override;
    void Rotate() override;

};



#endif //EXPLOSIVEAMMO_H
