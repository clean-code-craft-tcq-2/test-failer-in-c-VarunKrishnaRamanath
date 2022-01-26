#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "misaligned_PrintColourPair.h"

#define MISALIGNED_TEST_MODE          1
#define MISALIGNED_PRODUCTION_MODE    0

/*********************************** core function ****************************************/

#include <stdio.h>
#include "misaligned_PrintColourPair.h"

#if (MISALIGNED_TEST_MODE)
#include "StubPrintToConsole.h"

#define PRINT   printToConsole

#elif (MISALIGNED_PRODUCTION_MODE)
#define PRINT   printf
#endif

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            PRINT("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

/*********************************** Test code *****************************************/

const char* MajorColorNames[] = {
    "White", "Red", "Black", "Yellow", "Violet"
};

const char* MinorColorNames[] = {
    "Blue", "Orange", "Green", "Brown", "Slate"
};

const int numberOfMajorColors = (sizeof(MajorColorNames) / sizeof(MajorColorNames[0]));

const int numberOfMinorColors = (sizeof(MinorColorNames) / sizeof(MinorColorNames[0]));

/*Functions*/

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

void printToConsole(const char* string, int ColourPairNum, const char* majorColor, const char* minorColor)
{
    ColorPair colorPair = GetColorFromPairNumber(ColourPairNum);

    printf(string, ColourPairNum, majorColor, minorColor);
    if((MajorColorNames[colorPair.majorColor] != majorColor)||(MinorColorNames[colorPair.minorColor] == minorColor))
    {
        printf("Incorrect Colour pair %s and %s for given PairNumber %d\n", majorColor, minorColor, ColourPairNum);
        assert((MajorColorNames[colorPair.majorColor] == majorColor)&&(MinorColorNames[colorPair.minorColor] == minorColor));
    }

}

/************************************ main **************************************************/

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
