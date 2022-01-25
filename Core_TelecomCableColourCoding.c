#include <stdio.h>
#include "Core_TelecomCableColourCoding.h"

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

const int numberOfMajorColors = (sizeof(MajorColorNames) / sizeof(MajorColorNames[0]));

const int numberOfMinorColors = (sizeof(MinorColorNames) / sizeof(MinorColorNames[0]));

/*Functions*/

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    int pairNumber;

    pairNumber = ((colorPair->majorColor * numberOfMinorColors) + (colorPair->minorColor + 1));
    return pairNumber;
}
