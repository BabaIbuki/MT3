#include <Novice.h>
#include "Function.h"

static const int kColumnWidth = 60;
static const int kRowHeight = 20;

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

Matrix4x4 Add(const Matrix4x4& a, const Matrix4x4& b) {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			result.m[i][j] = a.m[i][j] + b.m[i][j];
	return result;
}

Matrix4x4 Subtract(const Matrix4x4& a, const Matrix4x4& b) {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			result.m[i][j] = a.m[i][j] - b.m[i][j];
	return result;
}

Matrix4x4 Multiply(const Matrix4x4& a, const Matrix4x4& b) {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				result.m[i][j] += a.m[i][k] * b.m[k][j];
	return result;
}

Matrix4x4 Inverse(const Matrix4x4& mat)
{
	Matrix4x4 result;
	float det;

	det = mat.m[0][0] * mat.m[1][1] * mat.m[2][2] * mat.m[3][3] + mat.m[0][0] * mat.m[1][2] * mat.m[2][3] * mat.m[3][1] + mat.m[0][0] * mat.m[1][3] * mat.m[2][1] * mat.m[3][2]
		- mat.m[0][0] * mat.m[1][3] * mat.m[2][2] * mat.m[3][1] - mat.m[0][0] * mat.m[1][2] * mat.m[2][1] * mat.m[3][3] - mat.m[0][0] * mat.m[1][1] * mat.m[2][3] * mat.m[3][2]
		- mat.m[0][1] * mat.m[1][0] * mat.m[2][2] * mat.m[3][3] - mat.m[0][2] * mat.m[1][0] * mat.m[2][3] * mat.m[3][1] - mat.m[0][3] * mat.m[1][0] * mat.m[2][1] * mat.m[3][2]
		+ mat.m[0][3] * mat.m[1][0] * mat.m[2][2] * mat.m[3][1] + mat.m[0][2] * mat.m[1][0] * mat.m[2][1] * mat.m[3][3] + mat.m[0][1] * mat.m[1][0] * mat.m[2][3] * mat.m[3][2]
		+ mat.m[0][1] * mat.m[1][2] * mat.m[2][0] * mat.m[3][3] + mat.m[0][2] * mat.m[1][3] * mat.m[2][0] * mat.m[3][1] + mat.m[0][3] * mat.m[1][1] * mat.m[2][0] * mat.m[3][2]
		- mat.m[0][3] * mat.m[1][2] * mat.m[2][0] * mat.m[3][1] - mat.m[0][2] * mat.m[1][1] * mat.m[2][0] * mat.m[3][3] - mat.m[0][1] * mat.m[1][3] * mat.m[2][0] * mat.m[3][2]
		- mat.m[0][1] * mat.m[1][2] * mat.m[2][3] * mat.m[3][0] - mat.m[0][2] * mat.m[1][3] * mat.m[2][1] * mat.m[3][0] - mat.m[0][3] * mat.m[1][1] * mat.m[2][2] * mat.m[3][0]
		+ mat.m[0][3] * mat.m[1][2] * mat.m[2][1] * mat.m[3][0] + mat.m[0][2] * mat.m[1][1] * mat.m[2][3] * mat.m[3][0] + mat.m[0][1] * mat.m[1][3] * mat.m[2][2] * mat.m[3][0];

	result.m[0][0] = (mat.m[1][1] * mat.m[2][2] * mat.m[3][3] + mat.m[1][2] * mat.m[2][3] * mat.m[3][1] + mat.m[1][3] * mat.m[2][1] * mat.m[3][2] - mat.m[1][3] * mat.m[2][2] * mat.m[3][1] - mat.m[1][2] * mat.m[2][1] * mat.m[3][3] - mat.m[1][1] * mat.m[2][3] * mat.m[3][2]) / det;
	result.m[0][1] = (-mat.m[0][1] * mat.m[2][2] * mat.m[3][3] - mat.m[0][2] * mat.m[2][3] * mat.m[3][1] - mat.m[0][3] * mat.m[2][1] * mat.m[3][2] + mat.m[0][3] * mat.m[2][2] * mat.m[3][1] + mat.m[0][2] * mat.m[2][1] * mat.m[3][3] + mat.m[0][1] * mat.m[2][3] * mat.m[3][2]) / det;
	result.m[0][2] = (mat.m[0][1] * mat.m[1][2] * mat.m[3][3] + mat.m[0][2] * mat.m[1][3] * mat.m[3][1] + mat.m[0][3] * mat.m[1][1] * mat.m[3][2] - mat.m[0][3] * mat.m[1][2] * mat.m[3][1] - mat.m[0][2] * mat.m[1][1] * mat.m[3][3] - mat.m[0][1] * mat.m[1][3] * mat.m[3][2]) / det;
	result.m[0][3] = (-mat.m[0][1] * mat.m[1][2] * mat.m[2][3] - mat.m[0][2] * mat.m[1][3] * mat.m[2][1] - mat.m[0][3] * mat.m[1][1] * mat.m[2][2] + mat.m[0][3] * mat.m[1][2] * mat.m[2][1] + mat.m[0][2] * mat.m[1][1] * mat.m[2][3] + mat.m[0][1] * mat.m[1][3] * mat.m[2][2]) / det;
	result.m[1][0] = (-mat.m[1][0] * mat.m[2][2] * mat.m[3][3] - mat.m[1][2] * mat.m[2][3] * mat.m[3][0] - mat.m[1][3] * mat.m[2][0] * mat.m[3][2] + mat.m[1][3] * mat.m[2][2] * mat.m[3][0] + mat.m[1][2] * mat.m[2][0] * mat.m[3][3] + mat.m[1][0] * mat.m[2][3] * mat.m[3][2]) / det;
	result.m[1][1] = (mat.m[0][0] * mat.m[2][2] * mat.m[3][3] + mat.m[0][2] * mat.m[2][3] * mat.m[3][0] + mat.m[0][3] * mat.m[2][0] * mat.m[3][2] - mat.m[0][3] * mat.m[2][2] * mat.m[3][0] - mat.m[0][2] * mat.m[2][0] * mat.m[3][3] - mat.m[0][0] * mat.m[2][3] * mat.m[3][2]) / det;
	result.m[1][2] = (-mat.m[0][0] * mat.m[1][2] * mat.m[3][3] - mat.m[0][2] * mat.m[1][3] * mat.m[3][0] - mat.m[0][3] * mat.m[1][0] * mat.m[3][2] + mat.m[0][3] * mat.m[1][2] * mat.m[3][0] + mat.m[0][2] * mat.m[1][0] * mat.m[3][3] + mat.m[0][0] * mat.m[1][3] * mat.m[3][2]) / det;
	result.m[1][3] = (mat.m[0][0] * mat.m[1][2] * mat.m[2][3] + mat.m[0][2] * mat.m[1][3] * mat.m[2][0] + mat.m[0][3] * mat.m[1][0] * mat.m[2][2] - mat.m[0][3] * mat.m[1][2] * mat.m[2][0] - mat.m[0][2] * mat.m[1][0] * mat.m[2][3] - mat.m[0][0] * mat.m[1][3] * mat.m[2][2]) / det;
	result.m[2][0] = (mat.m[1][0] * mat.m[2][1] * mat.m[3][3] + mat.m[1][1] * mat.m[2][3] * mat.m[3][0] + mat.m[1][3] * mat.m[2][0] * mat.m[3][1] - mat.m[1][3] * mat.m[2][1] * mat.m[3][0] - mat.m[1][1] * mat.m[2][0] * mat.m[3][3] - mat.m[1][0] * mat.m[2][3] * mat.m[3][1]) / det;
	result.m[2][1] = (-mat.m[0][0] * mat.m[2][1] * mat.m[3][3] - mat.m[0][1] * mat.m[2][3] * mat.m[3][0] - mat.m[0][3] * mat.m[2][0] * mat.m[3][1] + mat.m[0][3] * mat.m[2][1] * mat.m[3][0] + mat.m[0][1] * mat.m[2][0] * mat.m[3][3] + mat.m[0][0] * mat.m[2][3] * mat.m[3][1]) / det;
	result.m[2][2] = (mat.m[0][0] * mat.m[1][1] * mat.m[3][3] + mat.m[0][1] * mat.m[1][3] * mat.m[3][0] + mat.m[0][3] * mat.m[1][0] * mat.m[3][1] - mat.m[0][3] * mat.m[1][1] * mat.m[3][0] - mat.m[0][1] * mat.m[1][0] * mat.m[3][3] - mat.m[0][0] * mat.m[1][3] * mat.m[3][1]) / det;
	result.m[2][3] = (-mat.m[0][0] * mat.m[1][1] * mat.m[2][3] - mat.m[0][1] * mat.m[1][3] * mat.m[2][0] - mat.m[0][3] * mat.m[1][0] * mat.m[2][1] + mat.m[0][3] * mat.m[1][1] * mat.m[2][0] + mat.m[0][1] * mat.m[1][0] * mat.m[2][3] + mat.m[0][0] * mat.m[1][3] * mat.m[2][1]) / det;
	result.m[3][0] = (-mat.m[1][0] * mat.m[2][1] * mat.m[3][2] - mat.m[1][1] * mat.m[2][2] * mat.m[3][0] - mat.m[1][2] * mat.m[2][0] * mat.m[3][1] + mat.m[1][2] * mat.m[2][1] * mat.m[3][0] + mat.m[1][1] * mat.m[2][0] * mat.m[3][2] + mat.m[1][0] * mat.m[2][2] * mat.m[3][1]) / det;
	result.m[3][1] = (mat.m[0][0] * mat.m[2][1] * mat.m[3][2] + mat.m[0][1] * mat.m[2][2] * mat.m[3][0] + mat.m[0][2] * mat.m[2][0] * mat.m[3][1] - mat.m[0][2] * mat.m[2][1] * mat.m[3][0] - mat.m[0][1] * mat.m[2][0] * mat.m[3][2] - mat.m[0][0] * mat.m[2][2] * mat.m[3][1]) / det;
	result.m[3][2] = (-mat.m[0][0] * mat.m[1][1] * mat.m[3][2] - mat.m[0][1] * mat.m[1][2] * mat.m[3][0] - mat.m[0][2] * mat.m[1][0] * mat.m[3][1] + mat.m[0][2] * mat.m[1][1] * mat.m[3][0] + mat.m[0][1] * mat.m[1][0] * mat.m[3][2] + mat.m[0][0] * mat.m[1][2] * mat.m[3][1]) / det;
	result.m[3][3] = (mat.m[0][0] * mat.m[1][1] * mat.m[2][2] + mat.m[0][1] * mat.m[1][2] * mat.m[2][0] + mat.m[0][2] * mat.m[1][0] * mat.m[2][1] - mat.m[0][2] * mat.m[1][1] * mat.m[2][0] - mat.m[0][1] * mat.m[1][0] * mat.m[2][2] - mat.m[0][0] * mat.m[1][2] * mat.m[2][1]) / det;

	return result;
}

Matrix4x4 Transpose(const Matrix4x4& mat) {
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			result.m[i][j] = mat.m[j][i];
	return result;
}

Vector3 Transform(const Vector3& vec, const Matrix4x4& mat) {
	Vector3 result;

	result.x = vec.x * mat.m[0][0] + vec.y * mat.m[1][0] + vec.z * mat.m[2][0] + 1.0f * mat.m[3][0];
	result.y = vec.x * mat.m[0][1] + vec.y * mat.m[1][1] + vec.z * mat.m[2][1] + 1.0f * mat.m[3][1];
	result.z = vec.x * mat.m[0][2] + vec.y * mat.m[1][2] + vec.z * mat.m[2][2] + 1.0f * mat.m[3][2];
	float w = vec.x * mat.m[0][3] + vec.y * mat.m[1][3] + vec.z * mat.m[2][3] + 1.0f * mat.m[3][3];

	// 0除算を防ぐためのチェック
	if (w == 0.0f) {
		w = 1.0f; // デフォルト値を設定
	}

	result.x /= w;
	result.y /= w;
	result.z /= w;

	return result;
}

Matrix4x4 MakeIdentityMatrix() {
	Matrix4x4 identityMatrix = { 0.0f };
	for (int i = 0; i < 4; ++i)
		identityMatrix.m[i][i] = 1.0f;
	return identityMatrix;
}

Matrix4x4 MakeScaleMatrix(const Vector3 scale) {
	Matrix4x4 scaleMatrix = MakeIdentityMatrix();
	scaleMatrix.m[0][0] = scale.x;
	scaleMatrix.m[1][1] = scale.y;
	scaleMatrix.m[2][2] = scale.z;
	return scaleMatrix;
}

Matrix4x4 MakeRotateXMatrix(const float rotateX) {
	Matrix4x4 rotateXMatrix = MakeIdentityMatrix();
	float c = std::cos(rotateX);
	float s = std::sin(rotateX);
	rotateXMatrix.m[1][1] = c;
	rotateXMatrix.m[1][2] = s;
	rotateXMatrix.m[2][1] = -s;
	rotateXMatrix.m[2][2] = c;
	return rotateXMatrix;
}

Matrix4x4 MakeRotateYMatrix(const float rotateY) {
	Matrix4x4 rotateYMatrix = MakeIdentityMatrix();
	float c = std::cos(rotateY);
	float s = std::sin(rotateY);
	rotateYMatrix.m[0][0] = c;
	rotateYMatrix.m[0][2] = -s;
	rotateYMatrix.m[2][0] = s;
	rotateYMatrix.m[2][2] = c;
	return rotateYMatrix;
}

Matrix4x4 MakeRotateZMatrix(const float rotateZ) {
	Matrix4x4 rotateZMatrix = MakeIdentityMatrix();
	float c = std::cos(rotateZ);
	float s = std::sin(rotateZ);
	rotateZMatrix.m[0][0] = c;
	rotateZMatrix.m[0][1] = s;
	rotateZMatrix.m[1][0] = -s;
	rotateZMatrix.m[1][1] = c;
	return rotateZMatrix;
}

Matrix4x4 MakeRotateXYZMatrix(const Vector3 rotate) {
	Matrix4x4 rotateMatrix;
	rotateMatrix = Multiply(Multiply(MakeRotateXMatrix(rotate.x), MakeRotateYMatrix(rotate.y)), MakeRotateZMatrix(rotate.z));
	return rotateMatrix;
}

Matrix4x4 MakeTranslateMatrix(const Vector3 translate) {
	Matrix4x4 translateMatrix = MakeIdentityMatrix();
	translateMatrix.m[3][0] = translate.x;
	translateMatrix.m[3][1] = translate.y;
	translateMatrix.m[3][2] = translate.z;
	return translateMatrix;
}

Matrix4x4 MakeAffineMatrix(Vector3 scale, Vector3 rotate, Vector3 translate) {
	Matrix4x4 affineMatrix;
	affineMatrix = Multiply(Multiply(MakeScaleMatrix(scale), MakeRotateXYZMatrix(rotate)), MakeTranslateMatrix(translate));
	return affineMatrix;
}

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + row * kRowHeight, "%.02f", matrix.m[row][column]
			);
		}
	}
}

