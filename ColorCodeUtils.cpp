#include <iostream>
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
        for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; ++i) {
            ColorPair cp = GetColorFromPairNumber(i);
            std::cout << i << " : " << cp.ToString() << std::endl;
        }
    }
}
