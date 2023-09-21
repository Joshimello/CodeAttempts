#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "SlowBullet.hpp"
#include "Group.hpp"
#include "MoveTool.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int MoveTool::Price = 0;
MoveTool::MoveTool(float x, float y) :
    Turret("tower/blank.png", "tower/move.png", x, y, 32, Price, 0) {
    TurretType = 98;
}
void MoveTool::CreateBullet() {

}
