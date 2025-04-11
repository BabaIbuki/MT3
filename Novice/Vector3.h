#pragma once
#include <cmath>

struct Vector3 {
	// メンバ変数
	float x, y, z;

	// コンストラクタ
	Vector3() : x(0), y(0), z(0) {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	// ベクトルの加算
	Vector3 operator+(const Vector3& other) const {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	// 減算演算子オーバーロード
	Vector3 operator-(const Vector3& other) const {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	// スカラー乗算演算子オーバーロード
	Vector3 operator*(float scalar) const {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	// 内積
	float dot(const Vector3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	// 外積
	Vector3 cross(const Vector3& other) const {
		return Vector3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	// ノルム（ベクトルの長さ）
	float norm() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	// 正規化
	Vector3 normalize() const {
		float n = norm();
		if (n == 0) return Vector3(0, 0, 0); // ゼロベクトルの正規化はゼロベクトルを返す
		return Vector3(x / n, y / n, z / n);
	}

};