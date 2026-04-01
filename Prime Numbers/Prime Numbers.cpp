#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>

class Vector2
{
public:
    Vector2()
    {
        x = 0;
        y = 0;
    }
    Vector2(int mX)
    {
        x = mX;
        y = mX;
    }
    Vector2(int mX, int mY)
    {
        x = mX;
        y = mY;
    }
    Vector2(float mX)
    {
        x = mX;
        y = mX;
    }
    Vector2(float mX, float mY)
    {
        x = mX;
        y = mY;
    }
    Vector2(double mX)
    {
        x = mX;
        y = mX;
    }
    Vector2(double mX, double mY)
    {
        x = mX;
        y = mY;
    }
    double Magnitude()
    {
        return std::sqrt((x * x) + (y * y));
    }
    void fill(int mX)
    {
        x = mX;
        y = mX;
    }
    Vector2 operator+(const Vector2& rhs)
    {
        return Vector2(this->x + rhs.x, this->y + rhs.y);
    }
    Vector2 operator-(const Vector2& rhs)
    {
        return Vector2(this->x - rhs.x, this->y - rhs.y);
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector2& rhs)
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

    float x = 0;
    float y = 0;
};

int main()
{
    std::vector<int> primes
    {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
		83, 89, 97, 101, 103, 107, 109,
		113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
		211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,	307,
		311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
		419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509,
		521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619,
		631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739,
		743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857,
		859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977,
		983, 991, 997
    };

    std::vector<Vector2> primeVectors(0);

    for (int i = 0; i < primes.size(); i++)
        primeVectors.push_back(Vector2(primes[i]));

    for (int i = primes.size() - 1; i >= 1; i--)
    {
        Vector2 a = primeVectors[i];
        Vector2 b = primeVectors[i - 1];
        Vector2 result = a - b;
        double magnitude = result.Magnitude();
        int commonNum = std::floor(magnitude / 1.41421f);

        std::ostringstream mi;
        mi << i;
        std::cout << std::setw(3) << mi.str() << ". " << a << " - " << b << " " << magnitude << " = " << commonNum << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
