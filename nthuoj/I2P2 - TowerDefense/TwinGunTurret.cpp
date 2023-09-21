#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "SlowBullet.hpp"
#include "Group.hpp"
#include "TwinGunTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int TwinGunTurret::Price = 80;
TwinGunTurret::TwinGunTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "tower/4.png", x, y, 300, Price, 0.75) {

    TurretType = 49;
}
void TwinGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new SlowBullet(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SlowBullet(Position + normalized * 64, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav"); 
}
