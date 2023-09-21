#include <string>

#include "TankEnemy.hpp"
#include "DiceEnemy.hpp"
#include "PlayScene.hpp"

// Enemy::Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money)
TankEnemy::TankEnemy(int x, int y) : Enemy("play/enemy-4.png", x, y, 25, 20, 15, 10) {

}

void TankEnemy::OnExplode() {
	Enemy* enemy;
	getPlayScene()->EnemyGroup->AddNewObject(enemy = new DiceEnemy(Position.x, Position.y));
	enemy->UpdatePath(getPlayScene()->mapDistance);
}