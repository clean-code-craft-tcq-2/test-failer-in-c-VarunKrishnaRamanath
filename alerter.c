#include <stdio.h>
#include <assert.h>

#define ALERTER_TEST_MODE          1
#define ALERTER_PRODUCTION_MODE    0
/***************************************************core*************************************/

#if ALERTER_PRODUCTION_MODE
#define NETWORKALERT    networkAlert
#elif ALERTER_TEST_MODE
#define NETWORKALERT    networkAlertStub
#endif // ALERTER_TEST_MODE

int alertFailureCount = 0;

int networkAlert(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = NETWORKALERT(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}



/************************************TEST*************************************************/

#define MINIMUM_TEMPERATURE_ACCEPTABLE  0.0f
#define MAXIMUM_TEMPERATURE_ACCEPTABLE  200.0f

int networkAlertStub(float celcius)
{
    int AlertValue = 0xFFu;

    if((celcius >= MINIMUM_TEMPERATURE_ACCEPTABLE) && (celcius <= MAXIMUM_TEMPERATURE_ACCEPTABLE))
    {
        AlertValue = 200;
    }
    else
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        AlertValue = 500 ;
    }
    return AlertValue;
}

int main() {
    alertInCelcius(103.6);
    assert(alertFailureCount == 0);
    alertInCelcius(203.6);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6);
    assert(alertFailureCount == 0);
    alertInCelcius(400.5);
    assert(alertFailureCount != 0);

    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
