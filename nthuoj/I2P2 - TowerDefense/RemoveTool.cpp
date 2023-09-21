#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "SlowBullet.hpp"
#include "Group.hpp"
#include "RemoveTool.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int RemoveTool::Price = 0;
RemoveTool::RemoveTool(float x, float y) :
    Turret("tower/blank.png", "tower/remove.png", x, y, 32, Price, 0) {
    TurretType = 99;
}
void RemoveTool::CreateBullet() {

}
