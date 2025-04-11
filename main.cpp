#include <Novice.h>

#include "Matrix4x4Functions.h"

const char kWindowTitle[] = "LD2A_02_ジェイムズディアンカイ_MT3_00_02";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// インスタンス生成
	Matrix4x4Functions* matrix4x4Func = new Matrix4x4Functions();

	// 変数と初期化
	Matrix4x4 m1;
	m1 = {
		3.2f,0.7f,9.6f,4.4f,
		5.5f,1.3f,7.8f,2.1f,
		6.9f,8.0f,2.6f,1.0f,
		0.5f,7.2f,5.1f,3.3f
	};

	Matrix4x4 m2;
	m2 = {
		4.1f,6.5f,3.3f,2.2f,
		8.8f,0.6f,9.9f,7.7f,
		1.1f,5.5f,6.6f,0.0f,
		3.3f,9.9f,8.8f,2.2f
	};

	Matrix4x4 resultAdd;
	Matrix4x4 resultSubtract;
	Matrix4x4 resultMultiply;
	Matrix4x4 inverseM1;
	Matrix4x4 inverseM2;
	Matrix4x4 transposeM1;
	Matrix4x4 transposeM2;
	Matrix4x4 identify;

	resultAdd = matrix4x4Func->Add(m1, m2);
	resultSubtract = matrix4x4Func->Subtract(m1, m2);
	resultMultiply = matrix4x4Func->Multiply(m1, m2);
	inverseM1 = matrix4x4Func->Inverse(m1);
	inverseM2 = matrix4x4Func->Inverse(m2);
	transposeM1 = matrix4x4Func->Transpose(m1);
	transposeM2 = matrix4x4Func->Transpose(m2);
	identify = matrix4x4Func->MakeIdentify4x4();

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

		// 行列の中身を描画する
		matrix4x4Func->MatrixScreenPrintf(0, 0, resultAdd, "Add");
		matrix4x4Func->MatrixScreenPrintf(0, 128 * 1, resultSubtract, "Subtract");
		matrix4x4Func->MatrixScreenPrintf(0, 128 * 2, resultMultiply, "Multiply");
		matrix4x4Func->MatrixScreenPrintf(0, 128 * 3, inverseM1, "InverseM1");
		matrix4x4Func->MatrixScreenPrintf(0, 128 * 4, inverseM2, "InverseM2");
		matrix4x4Func->MatrixScreenPrintf(512, 0, transposeM1, "TransposeM1");
		matrix4x4Func->MatrixScreenPrintf(512, 128 * 1, transposeM2, "TransposeM2");
		matrix4x4Func->MatrixScreenPrintf(512, 128 * 2, identify, "Identify");

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
