#include <Novice.h>
#include "Function.h"

static const int kColumnWidth = 60;

// 加算
Vector3 Add(const Vector3& a, const Vector3& b) {
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

// 減算
Vector3 Subtract(const Vector3& a, const Vector3& b) {
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

// スカラー乗算
Vector3 Multiply(const Vector3& a, float scalar) {
	return Vector3(a.x * scalar, a.y * scalar, a.z * scalar);
}

// 乗算
Vector3 Multiply(const Vector3& a, const Vector3& b) {
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

// 内積
float Dot(const Vector3& a, const Vector3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// 外積
Vector3 Cross(const Vector3& a, const Vector3& b) {
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

// ノルム（ベクトルの長さ）
float Norm(const Vector3& a) {
	return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

// 正規化
Vector3 Normalize(const Vector3& a) {
	float n = Norm(a);
	if (n == 0) return Vector3(0, 0, 0); // ゼロベクトルの正規化はゼロベクトルを返す
	return Vector3(a.x / n, a.y / n, a.z / n);
}

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

