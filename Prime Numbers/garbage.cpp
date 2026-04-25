#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <unordered_set>
#include "Vector2.h"
#include <regex>

class garbage {
public:
    void attemptA(std::vector<int> primes, std::vector<Vector2> primeVectors)
    {
        for (int i = primes.size() - 1; i >= 1; i--)
        {
            Vector2 a = primeVectors[i];
            Vector2 b = primeVectors[i - 1];
            Vector2 result = a - b;
            double magnitude = result.Magnitude();
            int commonNum = std::floor(magnitude / 1.41421f);

            std::ostringstream mi;
            mi << i;
            //if(commonNum == 2)
            std::cout << std::setw(3) << mi.str() << ". " << a << " - " << b << " = " << commonNum << std::endl;
        }
    }
    void attemptB(std::vector<int> primes, std::vector<Vector2> primeVectors)
    {
        for (int i = primes.size() - 1; i >= 1; i--)
        {
            Vector2 a = primeVectors[i];
            Vector2 b = primeVectors[i - 1];
            a.y = b.y;
            double aTan = std::atan2(a.x, a.y);

            std::ostringstream mi;
            mi << i;
            //if(commonNum == 2)
            std::cout << std::setw(3) << mi.str() << ". " << a << " - " << b << " = ATan: " << aTan << std::endl;
        }
    }

    void attemptC(std::vector<int> primes, std::vector<Vector2> primeVectors, std::unordered_set<int>& checkPrime)
    {
        for (int a = 2; a < 1000; a++)
        {
            for (int b = 1; b < 1000; b++)
            {
                int counter = 0;
                for (int c = 1; c < primes.size(); c++)
                {
                    double result = a * primes[c] + b;
                    if (checkPrime.find(result) != checkPrime.end())
                    {
                        std::cout << a << b << "+" << c << "=" << result << "  ";
                        counter++;
                    }
                }
                if (counter >= 50)
                    std::cout << "found that " << a << "n" << " + " << b << " == " << counter << std::endl;
            }
        }
    }
};