#pragma once
#include "Vector3.h"

// 加算
Vector3 Add(const Vector3& a, const Vector3& b);

// 減算
Vector3 Subtract(const Vector3& a, const Vector3& b);

// スカラー乗算
Vector3 Multiply(const Vector3& a, float scalar);

// 乗算
Vector3 Multiply(const Vector3& a, const Vector3& b);

// 内積
float Dot(const Vector3& a, const Vector3& b);

// 外積
Vector3 Cross(const Vector3& a, const Vector3& b);

// ノルム（ベクトルの長さ）
float Norm(const Vector3& a);

// 正規化
Vector3 Normalize(const Vector3& a);

// ベクトルを表示する関数
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);