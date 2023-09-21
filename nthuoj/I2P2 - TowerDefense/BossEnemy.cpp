#include <string>
#include <algorithm>
#include <random>
#include <vector>

#include "BossEnemy.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"
#include "ExplosionEffect.hpp"
#include "TeleportEffect.hpp"

// Enemy::Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money)
BossEnemy::BossEnemy(int x, int y) : Enemy("play/enemy-6.png", x, y, 25, 15, 30, 50) {
	Phase1 = false;
	Phase2 = false;
}

void BossEnemy::Update(float deltaTime) {
	Enemy::Update(deltaTime);
	if (hp < 20 && !Phase1) {
		srand(time(0));
		Phase1 = true;
		std::vector<Engine::Point> TowerPoints;
		for (auto& it : getPlayScene()->TowerGroup->GetObjects()) {
			Turret* turret = dynamic_cast<Turret*>(it);
			TowerPoints.push_back(turret->Position);
		}
		auto rng = std::default_random_engine{};
		std::shuffle(std::begin(TowerPoints), std::end(TowerPoints), rng);
		for (auto& it : getPlayScene()->TowerGroup->GetObjects()) {
			Turret* turret = dynamic_cast<Turret*>(it);
			turret->Position = TowerPoints.back();
			TowerPoints.pop_back();
			getPlayScene()->EffectGroup->AddNewObject(new TeleportEffect(turret->Position.x, turret->Position.y));
		}
		speed = 60;
	}

	if (hp < 10 && !Phase2) {
		Phase2 = true;
		int TowerKilled = 0;
		for (auto& it : getPlayScene()->TowerGroup->GetObjects()) {
			Turret* turret = dynamic_cast<Turret*>(it);
			if (TowerKilled < 2) {
				TowerKilled++;
				getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(turret->Position.x, turret->Position.y));
				getPlayScene()->TowerGroup->RemoveObject(turret->GetObjectIterator());
			}
		}
	}
}