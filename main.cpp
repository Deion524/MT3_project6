#include <Novice.h>

#include "Matrix4x4Functions.h"

const char kWindowTitle[] = "LD2A_02_ジェイムズディアンカイ_MT3_00_05";

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
	Matrix4x4 orthographicMatrix = matrix4x4Func->MakeOrthographicMatrix(-160.0f, 160.0f, 200.0f, 300.0f, 0.0f, 1000.0f);
	Matrix4x4 perspectiveFovMatrix = matrix4x4Func->MakePerspectiveFovMatrix(0.63f, 1.33f, 0.1f, 1000.0f);
	Matrix4x4 viewportMatrix = matrix4x4Func->MakeViewportMatrix(100.0f, 200.0f, 600.0f, 300.0f, 0.0f, 1.0f);

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

		matrix4x4Func->MatrixScreenPrintf(0, 0, orthographicMatrix, "orthograhpMatrix");
		matrix4x4Func->MatrixScreenPrintf(0, 128, perspectiveFovMatrix, "perspectiveFovMatrix");
		matrix4x4Func->MatrixScreenPrintf(0,128*2, viewportMatrix, "viewportMatrix");

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
