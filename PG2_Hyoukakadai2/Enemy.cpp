#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(float posX, float posY, int speedX, int speedY,int isAlive)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 8;
	isAlive_ = isAlive;
	timer_ = 60;
}

void Enemy::Update() {
	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void Enemy::Draw() {
	if (isAlive_) {
		Novice::DrawEllipse(int(posX_), int(posY_), radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::SetSpeed(int x, int y) {
	speedX_ = x;
	speedY_ = y;
}

void Enemy::SetIsAliveFalse() {
	isAlive_ = false;
}
