#include <Novice.h>

#include "Matrix4x4Functions.h"

const char kWindowTitle[] = "LD2A_02_ジェイムズディアンカイ_MT3_00_04";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//インスタンス生成
	Matrix4x4Functions* matrix4x4Func = new Matrix4x4Functions();

	// 変数と初期化
	Vector3 rotate = { 0.4f,1.43f,-0.8f };
	Matrix4x4 rotateXMatrix = matrix4x4Func->MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = matrix4x4Func->MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = matrix4x4Func->MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateXYZMatrix = matrix4x4Func->Multiply(rotateXMatrix, matrix4x4Func->Multiply(rotateYMatrix, rotateZMatrix));

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

		matrix4x4Func->MatrixScreenPrintf(0, 128 * 0, rotateXMatrix, "rotateXMatrix");
		matrix4x4Func->MatrixScreenPrintf(0, 128 * 1, rotateYMatrix, "rotateYMatrix");
		matrix4x4Func->MatrixScreenPrintf(0, 128 * 2, rotateZMatrix, "rotateZMatrix");
		matrix4x4Func->MatrixScreenPrintf(0, 128 * 3, rotateXYZMatrix, "rotateXYZMatrix");

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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
