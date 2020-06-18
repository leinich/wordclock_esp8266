#ifndef LEDS_LEINICH_H_
#define LEDS_LEINICH_H_

#include "leds.h"

//###############
//##
//## ES_IST_FÜNF
//## ZEHNZWANZIG
//## DREIVIERTEL
//## __NACHVOR__  
//## HALB_ZWÖLF_
//## ZWEINSIEBEN
//## _DREI__FÜNF
//## ELFNEUNVIER
//## _ACHTZEHN__
//## _SECHS__UHR
//###############

#define LED_MATRIX_ROWS 10
#define LED_MATRIX_COLS 11
#define LED_DOTS 4
#define LED_COUNT (LED_MATRIX_ROWS * LED_MATRIX_COLS) + LED_DOTS

const uint8 matrixIndex[LED_MATRIX_ROWS][LED_MATRIX_COLS] =         {
                                                                        {0, 19, 20, 39, 40, 59, 60, 79, 80, 99, 100},
                                                                        {1, 18, 21, 38, 41, 58, 61, 78, 81, 98, 101},
                                                                        {2, 17, 22, 37, 42, 57, 62, 77, 82, 97, 102},
                                                                        {3, 16, 23, 36, 43, 56, 63, 76, 83, 96, 103},
                                                                        {4, 15, 24, 35, 44, 55, 64, 75, 84, 95, 104},
                                                                        {5, 14, 25, 34, 45, 54, 65, 74, 85, 94, 105},
                                                                        {6, 13, 26, 33, 46, 53, 66, 73, 86, 93, 106},
                                                                        {7, 12, 27, 32, 47, 52, 67, 72, 87, 92, 107},
                                                                        {8, 11, 28, 31, 48, 51, 68, 71, 88, 91, 108},
                                                                        {9, 10, 29, 30, 49, 50, 69, 70, 89, 90, 109}
                                                                    };

const uint8 dotsIndex[LED_DOTS] =           {
                                                110, 111, 112, 113
                                            };

//##############################
//## Define Methods
//##############################

//#### Fill Words
static inline void LedSetEsIst(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    //Es
    LedSetStatusMatrix(0, 0, mode);
    LedSetStatusMatrix(0, 1, mode);

    //Ist
    LedSetStatusMatrix(0, 3, mode);
    LedSetStatusMatrix(0, 4, mode);
    LedSetStatusMatrix(0, 5, mode);
}

static inline void LedSetUhr(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(9, 8, mode);
    LedSetStatusMatrix(9, 9, mode);
    LedSetStatusMatrix(9, 10, mode);
}

static inline void LedSetVor(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(3, 6, mode);
    LedSetStatusMatrix(3, 7, mode);
    LedSetStatusMatrix(3, 8, mode);
}

static inline void LedSetNach(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(3, 2, mode);
    LedSetStatusMatrix(3, 3, mode);
    LedSetStatusMatrix(3, 4, mode);
    LedSetStatusMatrix(3, 5, mode);
}

static inline void LedSetFunk(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(3, 0, mode);
    LedSetStatusMatrix(3, 1, mode);
    LedSetStatusMatrix(3, 9, mode);
    LedSetStatusMatrix(3, 10, mode);
}

//#### Minutes Words
static inline void LedSetFuenfMin(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(0, 7, mode);
    LedSetStatusMatrix(0, 8, mode);
    LedSetStatusMatrix(0, 9, mode);
    LedSetStatusMatrix(0, 10, mode);
}

static inline void LedSetZehnMin(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(1, 0, mode);
    LedSetStatusMatrix(1, 1, mode);
    LedSetStatusMatrix(1, 2, mode);
    LedSetStatusMatrix(1, 3, mode);
}

static inline void LedSetZwanzigMin(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(1, 4, mode);
    LedSetStatusMatrix(1, 5, mode);
    LedSetStatusMatrix(1, 6, mode);
    LedSetStatusMatrix(1, 7, mode);
    LedSetStatusMatrix(1, 8, mode);
    LedSetStatusMatrix(1, 9, mode);
    LedSetStatusMatrix(1, 10, mode);
}

static inline void LedSetViertelMin(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(2, 4, mode);
    LedSetStatusMatrix(2, 5, mode);
    LedSetStatusMatrix(2, 6, mode);
    LedSetStatusMatrix(2, 7, mode);
    LedSetStatusMatrix(2, 8, mode);
    LedSetStatusMatrix(2, 9, mode);
    LedSetStatusMatrix(2, 10, mode);
}

static inline void LedSetDreiviertelMin(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(2, 0, mode);
    LedSetStatusMatrix(2, 1, mode);
    LedSetStatusMatrix(2, 2, mode);
    LedSetStatusMatrix(2, 3, mode);
    LedSetViertelMin(hard);
}

static inline void LedSetHalbMin(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(4, 0, mode);
    LedSetStatusMatrix(4, 1, mode);
    LedSetStatusMatrix(4, 2, mode);
    LedSetStatusMatrix(4, 3, mode);
}

static inline void LedSetMinDot(uint8 dot, uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMinute(dot, mode);
}

//#### Hours Words
static inline void LedSetEinHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(5, 2, mode);
    LedSetStatusMatrix(5, 3, mode);
    LedSetStatusMatrix(5, 4, mode);
}

static inline void LedSetEinsHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetEinHour(mode);
    //s
    LedSetStatusMatrix(5, 5, mode);
}

static inline void LedSetZweiHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(5, 0, mode);
    LedSetStatusMatrix(5, 1, mode);
    LedSetStatusMatrix(5, 2, mode);
    LedSetStatusMatrix(5, 3, mode);
}

static inline void LedSetDreiHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(6, 1, mode);
    LedSetStatusMatrix(6, 2, mode);
    LedSetStatusMatrix(6, 3, mode);
    LedSetStatusMatrix(6, 4, mode);
}

static inline void LedSetVierHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(7, 7, mode);
    LedSetStatusMatrix(7, 8, mode);
    LedSetStatusMatrix(7, 9, mode);
    LedSetStatusMatrix(7, 10, mode);
}

static inline void LedSetFuenfHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(6, 7, mode);
    LedSetStatusMatrix(6, 8, mode);
    LedSetStatusMatrix(6, 9, mode);
    LedSetStatusMatrix(6, 10, mode);
}

static inline void LedSetSechsHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(9, 1, mode);
    LedSetStatusMatrix(9, 2, mode);
    LedSetStatusMatrix(9, 3, mode);
    LedSetStatusMatrix(9, 4, mode);
    LedSetStatusMatrix(9, 5, mode);
}

static inline void LedSetSiebenHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(5, 5, mode);
    LedSetStatusMatrix(5, 6, mode);
    LedSetStatusMatrix(5, 7, mode);
    LedSetStatusMatrix(5, 8, mode);
    LedSetStatusMatrix(5, 9, mode);
    LedSetStatusMatrix(5, 10, mode);
}

static inline void LedSetAchtHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(8, 1, mode);
    LedSetStatusMatrix(8, 2, mode);
    LedSetStatusMatrix(8, 3, mode);
    LedSetStatusMatrix(8, 4, mode);
}

static inline void LedSetNeunHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(7, 3, mode);
    LedSetStatusMatrix(7, 4, mode);
    LedSetStatusMatrix(7, 5, mode);
    LedSetStatusMatrix(7, 6, mode);
}

static inline void LedSetZehnHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(8, 5, mode);
    LedSetStatusMatrix(8, 6, mode);
    LedSetStatusMatrix(8, 7, mode);
    LedSetStatusMatrix(8, 8, mode);
}

static inline void LedSetElfHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(7, 0, mode);
    LedSetStatusMatrix(7, 1, mode);
    LedSetStatusMatrix(7, 2, mode);
}

static inline void LedSetZwoelfHour(uint8 hard){
    uint8 mode = hard ? LED_STATIS_ON : LED_STATIS_FADEIN;
    LedSetStatusMatrix(4, 5, mode);
    LedSetStatusMatrix(4, 6, mode);
    LedSetStatusMatrix(4, 7, mode);
    LedSetStatusMatrix(4, 8, mode);
    LedSetStatusMatrix(4, 9, mode);
}
#endif