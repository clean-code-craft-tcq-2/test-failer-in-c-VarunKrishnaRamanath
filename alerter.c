#include <stdio.h>
#include <assert.h>

#define MINIMUM_TEMPERATURE_ACCEPTABLE  0.0f
#define MAXIMUM_TEMPERATURE_ACCEPTABLE  200.0f

static int Stub_networkAlertOk(float celcius);
static int Stub_networkAlertNotOk(float celcius);
/***************************************************core*************************************/

unsigned int alertFailureCount = 0;

static int networkAlert(float celcius) {

    int AlertValue;
    if((celcius >= MINIMUM_TEMPERATURE_ACCEPTABLE) && (celcius <= MAXIMUM_TEMPERATURE_ACCEPTABLE))
    {
        AlertValue = 200;
    }
    else
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        AlertValue = 500;
    }
    return AlertValue;
}

static float ConvertFarenheitToCelsius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

static void VerifyAlert(int AlertLevel)
{
    if(AlertLevel == 500)
    {
        if(alertFailureCount == 0xFFFFFFFF)
        {
            alertFailureCount = 0xFFFFFFFF; //capping the value to max possible value
        }
        else
        {
            alertFailureCount += 1;
        }

    }
}

void alertInCelcius(float farenheit, int (*funptr_networkAlert)(float))
{
    float celcius;
    int returnCode;

    celcius = ConvertFarenheitToCelsius(farenheit);
    returnCode = funptr_networkAlert(celcius);
    VerifyAlert(returnCode);
}

/************************************TEST*************************************************/

static int Stub_networkAlertOk(float celcius) {

    return 200;
}

static int Stub_networkAlertNotOk(float celcius) {

    return 500;
}

/**************************** Main ***************************/

int main() {

    assert((int)(ConvertFarenheitToCelsius(103.6)*1000) == 39777); //Scaling the float value to 3 digit precision
    assert((int)(ConvertFarenheitToCelsius(203.6)*1000) == 95333); //Scaling the float value to 3 digit precision
    assert((int)(ConvertFarenheitToCelsius(303.6)*1000) == 150888); //Scaling the float value to 3 digit precision
    assert((int)(ConvertFarenheitToCelsius(400.5)*1000) == 204722); //Scaling the float value to 3 digit precision

    assert(networkAlert(-1) == 500);
    assert(networkAlert(13.6) == 200);
    assert(networkAlert(103.6) == 200);
    assert(networkAlert(203.6) == 500);
    assert(networkAlert(303.6) == 500);
    assert(networkAlert(400.5) == 500);

    alertFailureCount= 0;

    VerifyAlert(100);
    assert(alertFailureCount == 0);
    VerifyAlert(200);
    assert(alertFailureCount == 0);
    VerifyAlert(300);
    assert(alertFailureCount == 0);
    VerifyAlert(500);
    assert(alertFailureCount == 1);
    VerifyAlert(500);
    assert(alertFailureCount == 2);
    alertFailureCount = 50;
    VerifyAlert(500);
    assert(alertFailureCount == 51);
    alertFailureCount = 0xFFFFFFFF;
    VerifyAlert(500);
    assert(alertFailureCount == 0xFFFFFFFF);

    alertFailureCount= 0;

    alertInCelcius(103.6, networkAlert);
    assert(alertFailureCount == 0);
    alertInCelcius(203.6, networkAlert);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6, networkAlert);
    assert(alertFailureCount == 0);
    alertInCelcius(400.5, networkAlert);
    assert(alertFailureCount == 1);

    alertFailureCount= 0;

    alertInCelcius(103.6, Stub_networkAlertOk);
    assert(alertFailureCount == 0);
    alertInCelcius(203.6, Stub_networkAlertOk);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6, Stub_networkAlertNotOk);
    assert(alertFailureCount == 1);
    alertInCelcius(400.5, Stub_networkAlertNotOk);
    assert(alertFailureCount == 2);

    printf("All is well (for sure)\n");
    return 0;
}
