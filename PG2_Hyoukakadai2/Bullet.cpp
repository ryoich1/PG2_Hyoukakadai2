#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(int posX, int posY, int speed, int isShot) {

	posX_ = posX;
	posY_ = posY;
	speed_ = speed;
	radius_ = 10;
	isShot_ = isShot;

}

void Bullet::Update() {

	if (isShot_) {
		posY_ -= speed_;
	}

	if (posY_ <= 0 - radius_) {
		isShot_ = false;
	}

}

void Bullet::Draw() const {

	if (isShot_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}

}

void Bullet::SetIsShot() {

	isShot_ = true;

}

void Bullet::SetIsShotFalse() {

	isShot_ = false;

}

void Bullet::SetPosition(int x, int y) {

	posX_ = x;
	posY_ = y;

}