#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

static unsigned int Stub_getColourPairNumber(int l_majorColorNum, int l_minorColorNum);
static char* Stub_GetPrintString(unsigned int PairNumber, const char* l_majorColor, const char* l_minorColor);
/*********************************** core function ****************************************/
static unsigned int getColourPairNumber(int l_majorColorNum, int l_minorColorNum)
{
    unsigned int PairNumber = 0xFF;
    if((l_majorColorNum < 5) && ((l_minorColorNum < 5)))
    {
        PairNumber = (l_majorColorNum*5) + l_minorColorNum + 1;
    }
    return PairNumber;
}

static char* GetPrintString(unsigned int PairNumber, const char* l_majorColor, const char* l_minorColor)
{
    static char PrintString[100] = "\0";

    sprintf(PrintString, "%d\t%s\t%s\t\n", PairNumber, l_majorColor, l_minorColor);

    return PrintString;
}

void printColorMap(unsigned int (*fnPtr_getColourPairNumber)(int,int), char* (*fnPtr_GetPrintString)(unsigned int,const char*,const char*)) {
    unsigned int PairNumber;
    char PrintString[100];
    int i = 0, j = 0;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            PairNumber = fnPtr_getColourPairNumber(i, j);
            strcpy(PrintString, fnPtr_GetPrintString(PairNumber, majorColor[i],minorColor[j]));
            printf(PrintString);
        }
    }
}
/*********************************** Test code *****************************************/
static unsigned int Stub_getColourPairNumber(int l_majorColorNum, int l_minorColorNum)
{
    assert((l_majorColorNum >= 0) && (l_majorColorNum < 5));
    assert((l_minorColorNum >= 0) && (l_minorColorNum < 5));
    return 0;
}

static char* Stub_GetPrintString(unsigned int PairNumber, const char* l_majorColor, const char* l_minorColor)
{
    assert((PairNumber != 0) && (PairNumber <= 25));
    assert((strcmp(l_majorColor, "White")==0)||
           (strcmp(l_majorColor, "Red")==0)||
           (strcmp(l_majorColor, "Black")==0)||
           (strcmp(l_majorColor, "Yellow")==0)||
           (strcmp(l_majorColor, "Violet")==0));
    assert((strcmp(l_minorColor, "Blue")==0)||
           (strcmp(l_minorColor, "Orange")==0)||
           (strcmp(l_minorColor, "Green")==0)||
           (strcmp(l_minorColor, "Brown")==0)||
           (strcmp(l_minorColor, "Slate")==0));
    return "\0";
}

/************************************ main **************************************************/

int main() {
    /* valid pair number checks*/
    assert(getColourPairNumber(0, 0) == 1);
    assert(getColourPairNumber(0, 1) == 2);
    assert(getColourPairNumber(0, 2) == 3);
    assert(getColourPairNumber(0, 3) == 4);
    assert(getColourPairNumber(0, 4) == 5);

    assert(getColourPairNumber(1, 0) == 6);
    assert(getColourPairNumber(1, 1) == 7);
    assert(getColourPairNumber(1, 2) == 8);
    assert(getColourPairNumber(1, 3) == 9);
    assert(getColourPairNumber(1, 4) == 10);

    assert(getColourPairNumber(2, 0) == 11);
    assert(getColourPairNumber(2, 1) == 12);
    assert(getColourPairNumber(2, 2) == 13);
    assert(getColourPairNumber(2, 3) == 14);
    assert(getColourPairNumber(2, 4) == 15);

    assert(getColourPairNumber(3, 0) == 16);
    assert(getColourPairNumber(3, 1) == 17);
    assert(getColourPairNumber(3, 2) == 18);
    assert(getColourPairNumber(3, 3) == 19);
    assert(getColourPairNumber(3, 4) == 20);

    assert(getColourPairNumber(4, 0) == 21);
    assert(getColourPairNumber(4, 1) == 22);
    assert(getColourPairNumber(4, 2) == 23);
    assert(getColourPairNumber(4, 3) == 24);
    assert(getColourPairNumber(4, 4) == 25);

    /* Invalid Pair number checks*/
    assert(getColourPairNumber(5, 0) == 255);
    assert(getColourPairNumber(5, 1) == 255);
    assert(getColourPairNumber(5, 2) == 255);
    assert(getColourPairNumber(5, 3) == 255);
    assert(getColourPairNumber(5, 4) == 255);

    assert(getColourPairNumber(0, 5) == 255);
    assert(getColourPairNumber(1, 5) == 255);
    assert(getColourPairNumber(2, 5) == 255);
    assert(getColourPairNumber(3, 5) == 255);
    assert(getColourPairNumber(4, 5) == 255);

    /************************* String alignment test ************************/
    assert(strcmp(GetPrintString(0, "White", "Blue"), "0\tWhite\tBlue\t\n") == 0);

    assert(strcmp(GetPrintString(27, "Orange", "Brown"), "27\tOrange\tBrown\t\n") == 0);
    assert(strcmp(GetPrintString(42, "Magenta", "Purple"), "42\tMagenta\tPurple\t\n") == 0);

    /************************* printColorMap ****************************/
    printColorMap(Stub_getColourPairNumber,GetPrintString);
    printColorMap(getColourPairNumber,Stub_GetPrintString);

    printf("All is well (for sure)\n");
    return 0;
}
