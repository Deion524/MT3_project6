#include <Novice.h>

#include "Matrix4x4Functions.h"
#include "Vector3Functions.h"

const char kWindowTitle[] = "LC1A_09_ジェイムズディアンカイ_MT3_00_03";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//インスタンス生成
	Matrix4x4Functions* matrix4x4Func = new Matrix4x4Functions();
	Vector3Functions* vector3Func = new Vector3Functions();

	// 変数と初期化
	Vector3 translate = { 4.1f,2.6f,0.8f };
	Vector3 scale = { 1.5f,5.2f,7.3f };
	Matrix4x4 translateMatrix = matrix4x4Func->MakeTranslateMatrix(translate);
	Matrix4x4 scaleMatrix = matrix4x4Func->MakeScaleMatrix(scale);
	Vector3 point = { 2.3f,3.8f,1.4f };
	Matrix4x4 tranformMatrix = {
		1.0f,2.0f,3.0f,4.0f,
		3.0f,1.0f,1.0f,2.0f,
		1.0f,4.0f,2.0f,3.0f,
		2.0f,2.0f,1.0f,3.0f
	};
	Vector3 transformed = matrix4x4Func->Transform(point, tranformMatrix);

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		vector3Func->Vector3ScreenPrintf(0, 0, transformed, "transformed");
		matrix4x4Func->MatrixScreenPrintf(0, 32, translateMatrix, "translateMatrix");
		matrix4x4Func->MatrixScreenPrintf(0, 128, scaleMatrix, "scaleMatrix");

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
	delete matrix4x4Func;
	delete vector3Func;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
