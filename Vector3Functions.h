#pragma once

#include "Vector3.h"

class Vector3Functions
{
public:
	Vector3Functions();
	~Vector3Functions();
public:
	// 和
	Vector3 Add(const Vector3& v1, const Vector3& v2);
	// 差
	Vector3 Subtract(const Vector3& v1, const Vector3& v2);
	// 積
	Vector3 Multiply(float scalar, const Vector3& v);
	// 内積
	float Dot(const Vector3& v1, const Vector3& v2);
	// 長さ
	float Length(const Vector3& v);
	// 正規化
	Vector3 Normalize(const Vector3& v);
	// スクリーンに簡易描画
	void Vector3ScreenPrintf(int x, int y, const Vector3& v, const char* label);
private:
};

