#include <cmath>
#include <string>

#include "TeleportEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Resources.hpp"

PlayScene* TeleportEffect::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
TeleportEffect::TeleportEffect(float x, float y) : Sprite("play/teleport (1).png", x, y), timeTicks(0) {
	for (int i = 1; i <= 4; i++) {
		bmps.push_back(Engine::Resources::GetInstance().GetBitmap("play/teleport (" + std::to_string(i) + ").png"));
	}
}
void TeleportEffect::Update(float deltaTime) {
	timeTicks += deltaTime;
	if (timeTicks >= timeSpan) {
		getPlayScene()->EffectGroup->RemoveObject(objectIterator);
		return;
	}
	int phase = floor(timeTicks / timeSpan * bmps.size());
	bmp = bmps[phase];
	Sprite::Update(deltaTime);
}
