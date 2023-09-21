#ifndef TANKENEMY_HPP
#define TANKENEMY_HPP
#include "Enemy.hpp"

class TankEnemy : public Enemy {
public:
    TankEnemy(int x, int y);
    void OnExplode();
};
#endif // TANKENEMY_HPP
