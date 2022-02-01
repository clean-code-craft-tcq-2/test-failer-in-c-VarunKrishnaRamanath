#include <stdio.h>

#define MINIMUM_SIZE_IN_INCH_FOR_S    32
#define MAXIMUM_SIZE_IN_INCH_FOR_S    38
#define MINIMUM_SIZE_IN_INCH_FOR_M    38
#define MAXIMUM_SIZE_IN_INCH_FOR_M    42
#define MINIMUM_SIZE_IN_INCH_FOR_L    43
#define MAXIMUM_SIZE_IN_INCH_FOR_L    45

/********************* Core function *****************/

char TShirtSizeFromSizeInInch(unsigned char SizeInInch) {
    char sizeName = '\0';
    
    if(SizeInInch >= MINIMUM_SIZE_IN_INCH_FOR_S && SizeInInch < MAXIMUM_SIZE_IN_INCH_FOR_S) 
    {
        sizeName = 'S';
    } 
    else if(SizeInInch >= MINIMUM_SIZE_IN_INCH_FOR_M && SizeInInch < MAXIMUM_SIZE_IN_INCH_FOR_M) 
    {
        sizeName = 'M';
    } 
    else if(SizeInInch >= MINIMUM_SIZE_IN_INCH_FOR_L && SizeInInch < MAXIMUM_SIZE_IN_INCH_FOR_L) 
    {
        sizeName = 'L';
    }
    else
    {
        sizeName = '\0';
    }
    return sizeName;
}

/**************** TEST CODE *************************/

#include <stdio.h>
#include <assert.h>

static bool TShirtSizeIsCorrect(unsigned char MinSize, unsigned char MaxSize, char expectedSize)
{
    bool TshirtSizeCorrect = true;
    int tShirtSize;

    for(tShirtSize = MinSize;tShirtSize <= MaxSize;tShirtSize++)
    {
        if(TShirtSizeFromSizeInInch(tShirtSize) != expectedSize)
        {
            TshirtSizeCorrect = false;
        }
    }
    
    return TshirtSizeCorrect;
}

static void verifyTShirtSize(unsigned char MinSize, unsigned char MaxSize, char SizeStr)
{
    if(TShirtSizeIsCorrect(MinSize, MaxSize, SizeStr))
    {
        printf("Correct size %c sent for TShirt range %d to %d \n", SizeStr, MinSize, MaxSize);
    }
    else
    {
        printf("Incorrect size %c sent for TShirt range %d to %d \n", SizeStr, MinSize, MaxSize);
        assert(0);   
    }
}

void testTShirtSize(void)
{
    verifyTShirtSize(0, (MINIMUM_SIZE_IN_INCH_FOR_S-1), '\0');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_S, MAXIMUM_SIZE_IN_INCH_FOR_S, 'S');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_M, MAXIMUM_SIZE_IN_INCH_FOR_M, 'M');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_L, MAXIMUM_SIZE_IN_INCH_FOR_L, 'L');
    verifyTShirtSize(MAXIMUM_SIZE_IN_INCH_FOR_L, 255, '\0');
}

/**************** main *******************************/

int main() {

    testTShirtSize();

    printf("All is well (maybe!)\n");
    return 0;
}
