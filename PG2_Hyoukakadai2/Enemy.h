#pragma once
class Enemy
{
public:

	Enemy(float posX, float posY, int speedX, int speedY,int isAlive);

	void Update();

	void Draw();

	float GetPosX() { return posX_; };
	float GetPosY() { return posY_; };
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };
	int GetRadius() { return radius_; };
	int GetIsAlive() { return isAlive_; };
	int GetTimer() { return timer_; };
	void SetSpeed(int x, int y);
	void SetIsAliveFalse();

private:
	float posX_;
	float posY_;
	int speedX_;
	int speedY_;
	int radius_;
	int isAlive_;
	int timer_;

};

