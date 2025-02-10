#include "Player.h"
#include "Novice.h"

Player::Player() {

	posX_ = 100;
	posY_ = 600;
	radius_ = 20;
	speed_ = 8;
	bullet_ = new Bullet(0, 0, 10, false);
	isAlive_ = true;

}

Player::~Player() {
	delete bullet_;
}

void Player::Update(char* keys, char* preKeys) {

	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
	if (keys[DIK_D]) {
		posX_ += speed_;
	}
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}

	Novice::ScreenPrintf(0, 0, "%d", bullet_->GetIsShot());
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE]) {

		if (bullet_->GetIsShot() == false) {
			bullet_->SetPosition(posX_, posY_);
		}
		bullet_->SetIsShot();

	}

	if (bullet_->GetIsShot()) {
		bullet_->Update();
	}

}

void Player::Draw() const {

	if (bullet_->GetIsShot()) {
		bullet_->Draw();
	}
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);

}
