#include <stdio.h>
#include <assert.h>
#include "Core_TelecomCableColourCoding.h"
#include "Test_TelecomCableColourCoding.h"
#include "StubPrintToConsole.h"

void printToConsole(const char* string, int ColourPairNum, const char* majorColor, const char* minorColor)
{
    ColorPair colorPair = GetColorFromPairNumber(ColourPairNum);

    if((MajorColorNames[colorPair.majorColor] != majorColor)||(MinorColorNames[colorPair.minorColor] == minorColor))
    {
        printf("Incorrect Colour pair %s and %s for given PairNumber %d\n", majorColor, minorColor, ColourPairNum);
        assert((MajorColorNames[colorPair.majorColor] == majorColor)&&(MinorColorNames[colorPair.minorColor] == minorColor));
    }

}

void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}
