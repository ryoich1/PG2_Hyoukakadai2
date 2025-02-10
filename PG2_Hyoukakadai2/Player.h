#pragma once
#include "Bullet.h"
#include "Player.h"
class Player
{
public:
	Bullet* bullet_;
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetRadius() { return radius_; };
	int GetSpeed() { return speed_; };
	int GetIsAlive() { return isAlive_; };

	Player();
	~Player();

	void Update(char* keys, char* preKeys);

	void Draw() const;

private:
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	int isAlive_;

};


