#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "SpinBullet.hpp"
#include "Group.hpp"
#include "SpinTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int SpinTurret::Price = 40;
SpinTurret::SpinTurret(float x, float y) :
    Turret("play/tower-base.png", "tower/3.png", x, y, 300, Price, 0.75) {
    BulletCount = 0;
    isShoot = false;

    TurretType = 2;
}

void SpinTurret::CreateBullet() {
    /*if (BulletCount < 1) {
        getPlayScene()->BulletGroup->AddNewObject(new SpinBullet(Position, Engine::Point(0, 0), 0, this, 90));
        AudioHelper::PlayAudio("gun.wav");
        BulletCount++;
    }*/
    if (BulletCount == 0){
        isShoot = true;
        getPlayScene()->BulletGroup->AddNewObject(pew[0] = new SpinBullet(Position, Engine::Point(0, 0), 0, this, 135));
        getPlayScene()->BulletGroup->AddNewObject(pew[1] = new SpinBullet(Position, Engine::Point(0, 0), 0, this, 90));
        getPlayScene()->BulletGroup->AddNewObject(pew[2] = new SpinBullet(Position, Engine::Point(0, 0), 0, this, 45));
        getPlayScene()->BulletGroup->AddNewObject(pew[3] = new SpinBullet(Position, Engine::Point(0, 0), 0, this, 0));
        BulletCount = 4;
    }
}

SpinTurret::~SpinTurret() {
    if (isShoot) {
        BulletCount = 0;
        for (int i = 0; i < 4; i++) {
            pew[i]->Visible = false;
        }
    }
}