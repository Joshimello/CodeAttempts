#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "SpinBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Collider.hpp"
#include "SpinTurret.hpp"

SpinBullet::SpinBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, SpinTurret* parent, float angle) :
    Bullet("play/bullet-1.png", 300, 2, position, forwardDirection, rotation, parent) {
    CX = position.x;
    CY = position.y;
    Par = parent;
    Angle = angle;
}

int radius = 150;
void SpinBullet::Update(float deltaTime) {
    Bullet::Update(deltaTime);
    Position.x = CX + radius * cos(Angle);
    Position.y = CY + radius * sin(Angle);
    Angle += 0.05;
}

void SpinBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}

SpinBullet::~SpinBullet() {
    Par->BulletCount--;
}