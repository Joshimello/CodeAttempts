#ifndef TWINGUNTURRET_HPP
#define TWINGUNTURRET_HPP
#include "Turret.hpp"

class TwinGunTurret : public Turret {
public:
    static const int Price;
    TwinGunTurret(float x, float y);
    void CreateBullet() override;
};
#endif // TWINGUNTURRET_HPP
