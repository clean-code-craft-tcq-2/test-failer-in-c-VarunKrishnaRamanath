#ifndef CORE_TELECOMCABLECOLOURCODING_H_INCLUDED
#define CORE_TELECOMCABLECOLOURCODING_H_INCLUDED

#define MAX_COLORPAIR_NAME_CHARS  16

typedef enum {
    WHITE = 0,
    RED,
    BLACK,
    YELLOW,
    VIOLET
}MajorColor;

typedef enum {
    BLUE = 0,
    ORANGE,
    GREEN,
    BROWN,
    SLATE
}MinorColor;

typedef struct {
    MajorColor majorColor;
    MinorColor minorColor;
} ColorPair;

extern const char* MajorColorNames[];
extern const char* MinorColorNames[];
extern const int numberOfMajorColors;
extern const int numberOfMinorColors;

extern void ColorPairToString(const ColorPair* colorPair, char* buffer);
extern ColorPair GetColorFromPairNumber(int pairNumber);
extern int GetPairNumberFromColor(const ColorPair* colorPair);

#endif // CORE_TELECOMCABLECOLOURCODING_H_INCLUDED
