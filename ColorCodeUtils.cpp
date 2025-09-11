#include <iostream>
#include <iomanip>
#include "ColorCodeUtils.h"

namespace TelCoColorCoder
{
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBased = pairNumber - 1;
        MajorColor major = (MajorColor)(zeroBased / numberOfMinorColors);
        MinorColor minor = (MinorColor)(zeroBased % numberOfMinorColors);
        return ColorPair(major, minor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    void PrintColorCodeManual() {
        std::cout << "Color Code Reference Manual\n";
        std::cout << "----------------------------\n";
        for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; ++i) {
            ColorPair cp = GetColorFromPairNumber(i);
            std::cout << std::setw(2) << i << " : "
                      << std::setw(6) << MajorColorNames[cp.getMajor()] << " - "
                      << MinorColorNames[cp.getMinor()] << std::endl;
        }
    }
}
