#include "Vector3Functions.h"

#include <math.h>
#include <Novice.h>

/*============================================
				コンストラクタ
============================================*/
Vector3Functions::Vector3Functions()
{

}

/*============================================
				デストラクタ
============================================*/
Vector3Functions::~Vector3Functions()
{

}

/*============================================
					和
============================================*/
Vector3 Vector3Functions::Add(const Vector3& v1, const Vector3& v2)
{
	Vector3 result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	return result;
}

/*============================================
					差
============================================*/
Vector3 Vector3Functions::Subtract(const Vector3& v1, const Vector3& v2)
{
	Vector3 result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	return result;
}

/*============================================
					積
============================================*/
Vector3 Vector3Functions::Multiply(float scalar, const Vector3& v)
{
	Vector3 result;

	result.x = scalar * v.x;
	result.y = scalar * v.y;
	result.z = scalar * v.z;

	return result;
}

/*============================================
					内積
============================================*/
float Vector3Functions::Dot(const Vector3& v1, const Vector3& v2)
{
	float result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return result;
}

/*============================================
					内積
============================================*/
Vector3 Vector3Functions::Cross(const Vector3& v1, const Vector3& v2)
{
	Vector3 result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;

	return result;
}

/*============================================
					長さ
============================================*/
float Vector3Functions::Length(const Vector3& v)
{
	float result;

	result = powf(v.x * v.x + v.y * v.y + v.z * v.z, 0.5f);

	return result;
}

/*============================================
					正規化
============================================*/
Vector3 Vector3Functions::Normalize(const Vector3& v)
{
	Vector3 result;
	float vector = Length(v);

	result.x = v.x / vector;
	result.y = v.y / vector;
	result.z = v.z / vector;

	return result;

}

/*============================================
				ScreenPrintf
============================================*/
void Vector3Functions::Vector3ScreenPrintf(int x, int y, const Vector3& v, const char* label)
{
	Novice::ScreenPrintf(x, y, "%0.2f", v.x);
	Novice::ScreenPrintf(x + 64 * 1, y, "%0.2f", v.y);
	Novice::ScreenPrintf(x + 64 * 2, y, "%0.2f", v.z);
	Novice::ScreenPrintf(x + 64 * 3, y, " : %s", label);
}