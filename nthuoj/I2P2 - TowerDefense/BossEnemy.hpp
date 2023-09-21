#ifndef BOSSENEMY_HPP
#define BOSSENEMY_HPP
#include "Enemy.hpp"

class BossEnemy : public Enemy {
public:
    BossEnemy(int x, int y);
    void Update(float deltaTime) override;
    bool Phase1;
    bool Phase2;
};
#endif // BOSSENEMY_HPP
