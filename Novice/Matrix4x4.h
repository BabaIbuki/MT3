#pragma once
#include "Vector3.h"

struct Matrix4x4 {
    float m[4][4] = { 0.0f };

    //// 演算子オーバーロード
    Matrix4x4 operator+(const Matrix4x4& other) const;
    Matrix4x4 operator-(const Matrix4x4& other) const;
    Matrix4x4 operator*(const Matrix4x4& other) const;
    Matrix4x4 operator*(float scalar) const;
    Vector3 operator*(const Vector3& vec) const;

    //// 転置行列
    Matrix4x4 Transpose() const;

    //// 逆行列
    Matrix4x4 Inverse() const;

    //// 単位行列
    static Matrix4x4 Identity();

    //// 移動行列
    static Matrix4x4 MakeTranslate(const Vector3& translate);

    //// スケール行列
    static Matrix4x4 MakeScale(const Vector3& scale);

    //// 回転行列
    static Matrix4x4 MakeRotateX(float angle);
    static Matrix4x4 MakeRotateY(float angle);
    static Matrix4x4 MakeRotateZ(float angle);

    //// アフィン行列
    static Matrix4x4 MakeAffine(Vector3 scale, float rotateX, float rotateY, float rotateZ, Vector3 translate);

    //// アフィン行列
    static Matrix4x4 MakeAffine(Vector3 scale, Vector3 translate, float rotateX, float rotateY, float rotateZ);
};