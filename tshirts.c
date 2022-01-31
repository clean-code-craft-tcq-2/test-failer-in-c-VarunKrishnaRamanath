#include <stdio.h>

#define MINIMUM_SIZE_IN_INCH_FOR_S    32
#define MAXIMUM_SIZE_IN_INCH_FOR_S    38
#define MINIMUM_SIZE_IN_INCH_FOR_M    38
#define MAXIMUM_SIZE_IN_INCH_FOR_M    42
#define MINIMUM_SIZE_IN_INCH_FOR_L    43
#define MAXIMUM_SIZE_IN_INCH_FOR_L    45

/********************* Core function *****************/

char GetTShirtSizeFromSizeInInch(int SizeInInch) {
    char sizeName = '\0';
    
    if(SizeInInch < MINIMUM_SIZE_IN_INCH_FOR_S) 
    {
        sizeName = 'S';
    } 
    else if(SizeInInch >= MINIMUM_SIZE_IN_INCH_FOR_M && SizeInInch < MAXIMUM_SIZE_IN_INCH_FOR_M) 
    {
        sizeName = 'M';
    } 
    else if(SizeInInch > MAXIMUM_SIZE_IN_INCH_FOR_M) 
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

static bool TShirtSizeIsCorrect(int MinSize, int MaxSize, char SizeStr)
{
    boolean TshirtSizeCorrect = TRUE;

    for(tShirtSize = MinSize;tShirtSize <= MaxSize;tShirtSize++)
    {
        if(size(tShirtSize) != SizeStr)
        {
            TshirtSizeCorrect = FALSE;
        }
    }
}

static void verifyTShirtSize(int MinSize, int MaxSize, char SizeStr)
{
    if(TShirtSizeIsCorrect(MinSize, MaxSize, SizeStr))
    {
        printf("Correct size '%c' for %d inch Tshirt\n", SizeStr, tShirtSize);
    }
    else
    {
        printf("Incorrect size '%c' for %d inch Tshirt\n", SizeStr, tShirtSize);
        assert(0);
    }
       
}

void testTShirtSize(void)
{

    verifyTShirtSize(0x80000000, MAXIMUM_SIZE_IN_INCH_FOR_S-1, '\0');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_S, MAXIMUM_SIZE_IN_INCH_FOR_S, 'S');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_M, MAXIMUM_SIZE_IN_INCH_FOR_M, 'M');
    verifyTShirtSize(MINIMUM_SIZE_IN_INCH_FOR_L, MAXIMUM_SIZE_IN_INCH_FOR_L, 'L');
    verifyTShirtSize(MAXIMUM_SIZE_IN_INCH_FOR_L, 0x7FFFFFFF, '\0');

}

/**************** main *******************************/

int main() {

    testTShirtSize();

    printf("All is well (maybe!)\n");
    return 0;
}
