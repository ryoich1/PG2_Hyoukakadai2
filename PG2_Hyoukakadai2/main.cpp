#include<Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

const char kWindowTitle[] = "GC1D_09_モトハシ_リョウイチ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Enemy* enemyA = new Enemy(100.0f, 300.0f, 4, 0,true);
	Enemy* enemyB = new Enemy(300.0f, 300.0f, -4, 0,true);

	Player* player;
	player = new Player;

	Bullet* bullet;
	bullet = new Bullet(0, 0, 10, false);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (enemyA->GetIsAlive()) {
			enemyA->Update();
		}
		enemyB->Update();
		player->Update(keys, preKeys);

		// エネミー同士の当たり判定処理
		float distX = enemyA->GetPosX() - enemyB->GetPosX();
		float distY = enemyA->GetPosY() - enemyB->GetPosY();
		float dist = (distX * distX) + (distY * distY);
		int radius = enemyA->GetRadius() + enemyB->GetRadius();
		if (dist <= radius * radius) {
			enemyA->SetSpeed(enemyA->GetSpeedX() * -1, 4);
			enemyB->SetSpeed(enemyB->GetSpeedX() * -1, 3);
		}

		//弾と敵の当たり判定
		float aDistX = bullet->GetPosX() - enemyA->GetPosX();
		float aDistY = bullet->GetPosY() - enemyA->GetPosY();
		float aDist = (aDistX * aDistX) + (aDistY * aDistY);
		int aRadius = bullet->GetRadius() + enemyA->GetRadius();
		if (aDist <= aRadius * aRadius) {
			enemyA->SetIsAliveFalse();
			bullet->SetIsShotFalse();
		}

		//自分と敵の当たり判定


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(0, 20, "%d",bullet->GetIsShot());
		Novice::ScreenPrintf(0, 40, "%d", enemyA->GetIsAlive());
		enemyA->Draw();
		enemyB->Draw();
		player->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
