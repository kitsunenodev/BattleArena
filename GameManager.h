//
// Created by f.collet on 07/11/2024.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <cmath>
#include "Background.h"
#include "SpriteManager.h"
#include "Weapon/WeaponValues.h"
#include "Ammo/Ammunition.h"
#include "Entity/LivingEntity/Enemy/Enemy.h"
#include "Entity/LivingEntity/Player.h"
#include "Wave/Wave.h"

//Struct holding the variables of the weapon
struct WeaponValue {
    int MagazineCapacity; // Number of ammunition in a magazine
    float ReloadTime; // Time required to reload the Weapon
    float FireRate; // Time between two shots fired
};

//Struct Holding the variables of the ammunitions
struct AmmunitionValue {
    int Damage;
    float speed;
};

//Struct Holding the variables of the Enemies
struct EnemyValue{
    int maxHealth;
    int armorPoint;
    float speed;
};

//Singleton that will Manage the Game
class GameManager {
protected:

    std::vector<Entity*> entities_;
    std::vector<Wave*> Waves;
    Background background;
    void NextWave();
    int CurrentWaveIndex;
    int NbEnemySpawned;
    std::vector<std::pair<EnemyType, float>> DefaultSpawner = {
            {REGULAR, 0},
            {ARMORED, 10},
            {FAST, 5}
    };

public:
    void AddPlayer(Player* player);

    //Class Holding the filepath of all the sprites
    SpriteManager spriteManager;


    sf::RenderWindow window_;

    //time passed since last frame
    float deltaTime;
    ~GameManager() = default;
    static GameManager& GetInstance();
    void Update();
    void Display(sf::RenderWindow &window);
    void SetBackGround(Background& background);

    //Return the bounds of the arena
    sf::Vector2u GetArenaSize();

    //Handle the creation of a projectiles shot by the player
    void PlayerShoot(AmmoType type,sf::Vector2f ammunitionSpawnPosition);

    //Default Values for the different weapons of the game
    const std::map<AmmoType, WeaponValue> WeaponValues = {
            {REGULAR_AMMO,   {10,  1.f, 0.5f}},
            {EXPLOSIVE_AMMO, {1, 2.f, 1.f}},
            {FAST_AMMO, {200, 1.f, 0.1f}}
    };

    //Default values for the different ammunition of the game
    const std::map<AmmoType, AmmunitionValue> AmmunitionValues = {
        {REGULAR_AMMO, {5, 400.f}},
        {EXPLOSIVE_AMMO, {30, 150.f}},
        {FAST_AMMO, {2, 600.f}}
    };

    //Default values for the different enemy of the game
    const std::map<EnemyType, EnemyValue> EnemyValues = {
            {REGULAR, {20, 0, 90}},
            {ARMORED, {50, 10, 50}},
            {FAST, {10,0, 150}},
    };

    //Return the distance from the closest player and set the closest player to the variable given in parameters
    float GetDistanceFromClosestPlayer(sf::Vector2f position, Player*& ClosestPlayer);

    //Return the distance between two points
    float GetDistanceBetweenEntities(sf::Vector2f position1, sf::Vector2f position2);

    //Handle the spawn of an enemy
    void GenerateEnemy(EnemyType type, sf::Vector2<unsigned int> vector2);

    //Add a wave to the wave pool of the game
    void AddWaves(std::vector<Wave*>& WaveCollection);

    //Generate a default set of waves
    void GenerateWaves();

private:
        GameManager();

};



#endif //GAMEMANAGER_H
