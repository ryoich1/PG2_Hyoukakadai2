#pragma once
class Bullet
{
public:

	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeed() { return speed_; };
	int GetRadius() { return radius_; };
	int GetIsShot() { return isShot_; };
	void SetIsShot();
	void SetIsShotFalse();
	void SetPosition(int x, int y);

	Bullet(int posX, int posY, int speed, int isShot);

	void Update();

	void Draw() const;

private:
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	int isShot_;
};

