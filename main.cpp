#include <Novice.h>

#include "Vector3Functions.h"
#include "Matrix4x4Functions.h"

const char kWindowTitle[] = "LD2A_02_ジェイムズディアンカイ_MT3_01_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//インスタンス生成
	Vector3Functions* vector3Func = new Vector3Functions();
	Matrix4x4Functions* matrix4x4Func = new Matrix4x4Functions();

	// 変数と初期化
	Vector3 v1 = { 1.2f,-3.9f,2.5f };
	Vector3 v2 = { 2.8f,0.4f,-1.3f };
	Vector3 cross = vector3Func->Cross(v1, v2);

	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;

	Vector3 rotate = { 0.0f,0.0f,0.0f };
	Vector3 translate = { static_cast<float>(kWindowWidth / 2),0.0f,100.0f };
	Vector3 cameraPos = { static_cast<float>(kWindowWidth / 2),static_cast<float>(kWindowHeight / 2),0.0f };

	Matrix4x4 worldMatrix = matrix4x4Func->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
	Matrix4x4 cameraMatrix = matrix4x4Func->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, cameraPos);
	Matrix4x4 viewMatrix = matrix4x4Func->Inverse(cameraMatrix);
	Matrix4x4 projectionMatrix = matrix4x4Func->MakePerspectiveFovMatrix(0.45f, static_cast<float>(kWindowWidth / kWindowHeight), 0.1f, 100.0f);
	Matrix4x4 worldViewProjection = matrix4x4Func->Multiply(worldMatrix, matrix4x4Func->Multiply(viewMatrix, projectionMatrix));
	Matrix4x4 viewPortMatrix = matrix4x4Func->MakeViewportMatrix(0, 0, static_cast<float>(kWindowWidth), static_cast<float>(kWindowHeight), 0.0f, 1.0f);

	float triangleWidth = 10.0f;
	float kMoveSpeed = 2.0f;
	Vector3 kLocalVertices[3];
	Vector3 screenVertices[3];
	kLocalVertices[0] = { translate.x,translate.y + triangleWidth / 2.0f,0.0f };
	kLocalVertices[1] = { translate.x - triangleWidth / 2.0f,translate.y - triangleWidth / 2.0f,0.0f };
	kLocalVertices[2] = { translate.x + triangleWidth / 2.0f,translate.y - triangleWidth / 2.0f,0.0f };

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

		// 座標を移動させる
		if (keys[DIK_W]) {
			translate.z += kMoveSpeed;
		} else if (keys[DIK_S]) {
			translate.z -= kMoveSpeed;
		}

		if (keys[DIK_D]) {
			translate.x += kMoveSpeed;
		} else if (keys[DIK_A]) {
			translate.x -= kMoveSpeed;
		}

		// 三角形の頂点の計算
		kLocalVertices[0] = { +0.0f, triangleWidth / 2.0f,0.0f };
		kLocalVertices[1] = { - triangleWidth / 2.0f,- triangleWidth / 2.0f,0.0f };
		kLocalVertices[2] = { + triangleWidth / 2.0f,- triangleWidth / 2.0f,0.0f };

		rotate.y += 0.02f;

		// 行列を作成
		worldMatrix = matrix4x4Func->MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
		worldViewProjection = matrix4x4Func->Multiply(worldMatrix, matrix4x4Func->Multiply(viewMatrix, projectionMatrix));

		// 座標変換
		for (int i = 0; i < 3; ++i) {
			Vector3 ndcVertex = matrix4x4Func->Transform(kLocalVertices[i], worldViewProjection);
			screenVertices[i] = matrix4x4Func->Transform(ndcVertex, viewPortMatrix);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		vector3Func->Vector3ScreenPrintf(0, 0, cross, "cross");

		Novice::DrawTriangle(
			static_cast<int>(screenVertices[0].x), static_cast<int>(screenVertices[0].y),
			static_cast<int>(screenVertices[1].x), static_cast<int>(screenVertices[1].y),
			static_cast<int>(screenVertices[2].x), static_cast<int>(screenVertices[2].y),
			0xFF0000FF, kFillModeSolid
		);

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
	delete matrix4x4Func;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
