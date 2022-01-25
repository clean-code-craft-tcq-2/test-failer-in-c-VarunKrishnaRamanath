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
