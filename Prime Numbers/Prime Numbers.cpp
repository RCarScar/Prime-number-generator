#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <unordered_set>
#include "txtToBinary.h"
#include "Vector2.h"
#include "info.h"
#include "setCompare.h"
#include <regex>

int main()
{
    ConvertBintoSet conv = ConvertBintoSet();
    MagicValues m = MagicValues();
    SetCompare s = SetCompare();

    if (m.update != 0)
        conv.begin(m.inputPath, m.outputPath);

    std::unordered_set<int>* primes = conv.readBinaryFile(m.outputPath);

    s.compare({2, 3, 5, 7, 1}, primes);
    std::cout << s.accuracy << std::endl;
}

