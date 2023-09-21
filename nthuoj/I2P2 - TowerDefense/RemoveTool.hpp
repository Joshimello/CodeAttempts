#ifndef REMOVETOOL_HPP
#define REMOVETOOL_HPP
#include "Turret.hpp"

class RemoveTool : public Turret {
public:
    static const int Price;
    RemoveTool(float x, float y);
    void CreateBullet() override;
};
#endif // REMOVETOOL_HPP
