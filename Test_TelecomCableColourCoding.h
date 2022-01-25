#ifndef TEST_TELECOMCABLECOLOURCODING_H_INCLUDED
#define TEST_TELECOMCABLECOLOURCODING_H_INCLUDED

#include "Core_TelecomCableColourCoding.h"

extern void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor);
extern void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber);

#endif // TEST_TELECOMCABLECOLOURCODING_H_INCLUDED
