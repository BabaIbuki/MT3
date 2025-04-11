#pragma once
#include "Vector3.h"
#include "Matrix4x4.h"

// ベクトルの加算
Vector3 Add(const Vector3& a, const Vector3& b);

// ベクトルの減算
Vector3 Subtract(const Vector3& a, const Vector3& b);

// ベクトルのスカラー乗算
Vector3 Multiply(const Vector3& a, float scalar);

// ベクトルの乗算
Vector3 Multiply(const Vector3& a, const Vector3& b);

// ベクトルの内積
float Dot(const Vector3& a, const Vector3& b);

// ベクトルの外積
Vector3 Cross(const Vector3& a, const Vector3& b);

// ベクトルのノルム（ベクトルの長さ）
float Norm(const Vector3& a);

// ベクトルの正規化
Vector3 Normalize(const Vector3& a);

// ベクトルを表示する関数
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);

// 行列の加算
Matrix4x4 Add(const Matrix4x4& a, const Matrix4x4& b);

// 行列の減算
Matrix4x4 Subtract(const Matrix4x4& a, const Matrix4x4& b);

// 行列の積
Matrix4x4 Multiply(const Matrix4x4& a, const Matrix4x4& b);

// 逆行列
Matrix4x4 Inverse(const Matrix4x4& mat);

// 転置行列
Matrix4x4 Transpose(const Matrix4x4& mat);

// ベクトルを行列で変換する関数
Vector3 Transform(const Vector3& vec, const Matrix4x4& mat);

// 単位行列
Matrix4x4 MakeIdentityMatrix();

// 行列のスケール
Matrix4x4 MakeScaleMatrix(const Vector3 scale);

// 行列の回転
Matrix4x4 MakeRotateXMatrix(const float rotateX);
Matrix4x4 MakeRotateYMatrix(const float rotateY);
Matrix4x4 MakeRotateZMatrix(const float rotateZ);

// 行列の合成
Matrix4x4 MakeRotateXYZMatrix(const Vector3 rotate);

// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3 translate);

// 行列のアフィン変換
Matrix4x4 MakeAffineMatrix(Vector3 scale, Vector3 rotate, Vector3 translate);

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix);