#include "EstimateTShirtSize.h"

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
