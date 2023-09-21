#ifndef SPINBULLET_HPP
#define SPINBULLET_HPP
#include "Bullet.hpp"
#include "SpinTurret.hpp"

class Enemy;
namespace Engine {
    struct Point;
}  // namespace Engine

class SpinBullet : public Bullet {
public:
    explicit SpinBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, SpinTurret* parent, float angle);
    void OnExplode(Enemy* enemy) override;
    void Update(float deltaTime) override;

    int CX, CY;
    float Angle = 0;
    SpinTurret* Par;

    ~SpinBullet();
};
#endif // SPINBULLET_HPP
