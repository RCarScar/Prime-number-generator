#include "Vector2.h"
#include <iomanip>
#include <cmath>
#include <sstream>

Vector2::Vector2()
{
    x = 0;
    y = 0;
}
Vector2::Vector2(int mX)
{
    x = mX;
    y = mX;
}
Vector2::Vector2(int mX, int mY)
{
    x = mX;
    y = mY;
}
Vector2::Vector2(float mX)
{
    x = mX;
    y = mX;
}
Vector2::Vector2(float mX, float mY)
{
    x = mX;
    y = mY;
}
Vector2::Vector2(double mX)
{
    x = mX;
    y = mX;
}
Vector2::Vector2(double mX, double mY)
{
    x = mX;
    y = mY;
}
double Vector2::Magnitude()
{
    return std::sqrt((x * x) + (y * y));
}
void Vector2::fill(int mX)
{
    x = mX;
    y = mX;
}
Vector2 Vector2::operator+(const Vector2& rhs)
{
    return Vector2(this->x + rhs.x, this->y + rhs.y);
}
Vector2 Vector2::operator-(const Vector2& rhs)
{
    return Vector2(this->x - rhs.x, this->y - rhs.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2& rhs)
{
    // Format each number into a string first, then use setw to align fields.
    // Change width (6) or precision (1) to taste.
    std::ostringstream sx, sy;
    sx << rhs.x; // shows .0 for integers
    sy << rhs.y;

    os << "("
        << std::setw(3) << sx.str()
        << ","
        << std::setw(3) << sy.str()
        << ")";
    return os;
}