#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"

class Matrix4x4Functions {
public:
	Matrix4x4Functions();
	~Matrix4x4Functions();
public:
	// 行列の和
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
	// 行列の差
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
	// 行列の積
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
	// 逆行列
	Matrix4x4 Inverse(const Matrix4x4& m);
	// 転置行列
	Matrix4x4 Transpose(const Matrix4x4& m);
	// 単位行列の作成
	Matrix4x4 MakeIdentify4x4();

	// 平行移動行列
	Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
	// 拡大縮小行列
	Matrix4x4 MakeScaleMatrix(const Vector3& scale);
	// 座標変換
	Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

	// X軸回転行列
	Matrix4x4 MakeRotateXMatrix(float radian);
	// Y軸回転行列
	Matrix4x4 MakeRotateYMatrix(float radian);
	// Z軸回転行列
	Matrix4x4 MakeRotateZMatrix(float radian);

	// 行列の描画
	void MatrixScreenPrintf(int x, int y, const Matrix4x4& m, const char* lavel);

private:
};

