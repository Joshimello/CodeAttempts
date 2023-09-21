#ifndef MOVETOOL_HPP
#define MOVETOOL_HPP
#include "Turret.hpp"

class MoveTool : public Turret {
public:
    static const int Price;
    MoveTool(float x, float y);
    void CreateBullet() override;
};
#endif // MOVETOOL_HPP
