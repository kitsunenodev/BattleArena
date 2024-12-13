cmake_minimum_required(VERSION 3.29)
project(BattleArena)

set(CMAKE_CXX_STANDARD 20)

# Use static SFML libraries
set(SFML_STATIC_LIBRARIES TRUE)

# SFML_STATIC definition
add_definitions(-DSFML_STATIC)

# SFML paths
set(SFML_DIR "C:/SFML-2.6.1")
set(SFML_INCLUDE_DIR "${SFML_DIR}/include")
set(SFML_LIBRARY_DIR "${SFML_DIR}/lib")


# Include and library directories
include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})



add_executable(BattleArena main.cpp
        Entity/Entity.cpp
        Entity/Entity.h
        Entity/LivingEntity/LivingEntity.cpp
        Entity/LivingEntity/LivingEntity.h
        Entity/LivingEntity/Player.cpp
        Entity/LivingEntity/Player.h
        Background.cpp
        Background.h
        Ammo/Ammunition.h
        Weapon/Weapon.h
        Weapon/Weapon.cpp
        Ammo/Ammunition.cpp
        GameManager.cpp
        GameManager.h
        Entity/LivingEntity/Enemy/Enemy.cpp
        Entity/LivingEntity/Enemy/Enemy.h
        Entity/LivingEntity/Enemy/RegularEnemy.cpp
        Entity/LivingEntity/Enemy/RegularEnemy.h
        Ammo/RegularAmmo.cpp
        Ammo/RegularAmmo.h
        Ammo/ExplosiveAmmo.cpp
        Ammo/ExplosiveAmmo.h
        Ammo/PenetrativeAmmo.cpp
        Ammo/PenetrativeAmmo.h
        Ammo/AmmoFactory.cpp
        Ammo/AmmoFactory.h
        Weapon/WeaponFactory.cpp
        Weapon/WeaponFactory.h
        Entity/Entity.cpp
        SpriteManager.h
        Entity/LivingEntity/Enemy/EnemyFactory.cpp
        Entity/LivingEntity/Enemy/EnemyFactory.h
        Entity/LivingEntity/Enemy/ArmoredEnemy.cpp
        Entity/LivingEntity/Enemy/ArmoredEnemy.h
        Entity/LivingEntity/Enemy/FastEnemy.cpp
        Entity/LivingEntity/Enemy/FastEnemy.h
        Wave.cpp
        Wave.h
        WeaponValues.h)

# Debug or release libs based on config type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(${PROJECT_NAME}
            sfml-graphics-s-d
            sfml-window-s-d
            sfml-system-s-d
            sfml-audio-s-d
            freetype
            opengl32
            winmm
            gdi32
            openal32
            flac
            vorbisenc
            vorbisfile
            vorbis
            ogg
            ws2_32)
else()
    target_link_libraries(${PROJECT_NAME}
            sfml-graphics-s
            sfml-window-s
            sfml-system-s
            sfml-audio-s
            freetype
            opengl32
            winmm
            gdi32
            openal32
            flac
            vorbisenc
            vorbisfile
            vorbis
            ogg
            ws2_32)
endif()
