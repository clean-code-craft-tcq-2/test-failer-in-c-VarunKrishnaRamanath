#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "misaligned_PrintColourPair.h"

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
