#include <Novice.h>

#include "Vector3Functions.h"

const char kWindowTitle[] = "LD2A_02_ジェイムズディアンカイ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// インスタンス生成
	Vector3Functions* vector3Func = new Vector3Functions();

	// 変数と初期化
	Vector3 v1 = { 1.0f,3.0f,-5.0f };
	Vector3 v2 = { 4.0f,-1.0f,2.0f };
	float k = 4.0f;


	Vector3 resultAdd = { 0.0f,0.0f,0.0f };
	Vector3 resultSubtract = { 0.0f,0.0f,0.0f };
	Vector3 resultMultiply = { 0.0f,0.0f,0.0f };
	float resultDot = 0.0f;
	float resultLength = 0.0f;
	Vector3 resultNormalize = { 0.0f,0.0f,0.0f };

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

		resultAdd = vector3Func->Add(v1, v2);
		resultSubtract = vector3Func->Subtract(v1, v2);
		resultMultiply = vector3Func->Multiply(k, v1);
		resultDot = vector3Func->Dot(v1, v2);
		resultLength = vector3Func->Length(v1);
		resultNormalize = vector3Func->Normalize(v2);

		///
		/// ↑更新処理ここまで
		///

		vector3Func->Vector3ScreenPrintf(16, 16 * 1, resultAdd, "Add");
		vector3Func->Vector3ScreenPrintf(16, 16 * 2, resultSubtract, "Subtract");
		vector3Func->Vector3ScreenPrintf(16, 16 * 3, resultMultiply, "Multiply");
		Novice::ScreenPrintf(16, 16 * 4, "%0.2f : Dot", resultDot);
		Novice::ScreenPrintf(16, 16 * 5, "%0.2f : Length", resultLength);
		vector3Func->Vector3ScreenPrintf(16, 16 * 6, resultNormalize, "Normalize");

		///
		/// ↓描画処理ここから
		///

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

	// インスタンス削除
	delete vector3Func;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
