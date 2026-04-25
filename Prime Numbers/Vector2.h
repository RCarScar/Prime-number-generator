#pragma once
#include <iostream>

class Vector2
{
public:
    Vector2();
    Vector2(int mX);
    Vector2(int mX, int mY);
    Vector2(float mX);
    Vector2(float mX, float mY);
    Vector2(double mX);
    Vector2(double mX, double mY);
    double Magnitude();
    void fill(int mX);
    Vector2 operator+(const Vector2& rhs);
    Vector2 operator-(const Vector2& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Vector2& rhs);

    float x = 0;
    float y = 0;
};
