#ifndef __SEVEN_SEGMENT_H__
#define __SEVEN_SEGMENT_H__

#define SEG_VCC 1U<<0
#define SEG_A   1U<<1
#define SEG_B   1U<<2
#define SEG_C   1U<<3
#define SEG_D   1U<<4
#define SEG_E   1U<<5
#define SEG_F   1U<<6
#define SEG_G   1U<<7


#define ZERO  (SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F)
#define ONE   (SEG_B | SEG_C)
#define TWO   (SEG_A | SEG_B | SEG_D | SEG_E | SEG_G)
#define THREE (SEG_A | SEG_B | SEG_C | SEG_D | SEG_G)
#define FOUR  (SEG_B | SEG_C | SEG_F | SEG_G)
#define FIVE  (SEG_A | SEG_C | SEG_D | SEG_F | SEG_G)
#define SIX   (SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G)
#define SEVEN (SEG_A | SEG_B | SEG_C)
#define EIGHT (SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G)
#define NINE  (SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G)
#define A     (SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G)
#define B     (SEG_C | SEG_D | SEG_E | SEG_F | SEG_G)
#define C     (SEG_A | SEG_D | SEG_E | SEG_F)
#define D     (SEG_B | SEG_C | SEG_D | SEG_E | SEG_G)
#define E     (SEG_A | SEG_D | SEG_E | SEG_F | SEG_G)
#define F     (SEG_A | SEG_E | SEG_F | SEG_G)


extern const char numbers[] =
    {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
        A, B, C, D, E, F
                        };

#endif
