#include <stdio.h>
#include "TShirt_Test.h"

/********************* Core function *****************/

char size(int inch) {
    char sizeName = '\0';
    if(inch < 38) {
        sizeName = 'S';
    } else if(inch > 38 && inch < 42) {
        sizeName = 'M';
    } else if(inch > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

/**************** TEST CODE *************************/

#include <stdio.h>
#include <assert.h>
#include "EstimateTShirtSize.h"
#include "TShirt_Test.h"

#define MINIMUM_SIZE_IN_INCH_FOR_S    32
#define MAXIMUM_SIZE_IN_INCH_FOR_S    38
#define MINIMUM_SIZE_IN_INCH_FOR_M    39
#define MAXIMUM_SIZE_IN_INCH_FOR_M    42
#define MINIMUM_SIZE_IN_INCH_FOR_L    43
#define MAXIMUM_SIZE_IN_INCH_FOR_L    45

static void verifyTShirtSize(int MinSize, int MaxSize, char SizeStr)
{
    int tShirtSize = 0;

    for(tShirtSize = MinSize;tShirtSize <= MaxSize;tShirtSize++)
    {
        if(size(tShirtSize) != SizeStr)
        {
            printf("Incorrect size '%c' for %d inch Tshirt\n", SizeStr, tShirtSize);
            assert(size(tShirtSize) == SizeStr);
        }
    }
    printf("T Shirt size is correct from size %d to %d\n", MinSize, MaxSize);
}

void testTShirtSize(void)
{

    //verifyTShirtSize(0x80000000, MAXIMUM_SIZE_IN_INCH_FOR_S-1, '\0');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_S, MAXIMUM_SIZE_IN_INCH_FOR_S, 'S');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_M, MAXIMUM_SIZE_IN_INCH_FOR_M, 'M');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_L, MAXIMUM_SIZE_IN_INCH_FOR_L, 'L');
    //verifyTShirtSize(MAXIMUM_SIZE_IN_INCH_FOR_L, 0x7FFFFFFF, '\0');

}

/**************** main *******************************/

int main() {

    testTShirtSize();

    printf("All is well (maybe!)\n");
    return 0;
}
