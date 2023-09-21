#ifndef SPINTURRET_HPP
#define SPINTURRET_HPP
#include "Turret.hpp"

class SpinTurret : public Turret {
public:
    bool isShoot;
    Bullet* pew[4];
    static const int Price;
    SpinTurret(float x, float y);
    void CreateBullet() override;
    ~SpinTurret();
};
#endif // SPINTURRET_HPP
