//
// Created by 倉澤　一詩
//


#ifndef DEF_TYPE_H
#define DEF_TYPE_H

#include <inttypes.h>

#define PI 3.14159265


//Public Function Relation
#define INT_MODE		0   /* Return mode select */
#define BOOL_MODE		1

//Map Relation
#define FRONT_MACHINE	0
#define NORTH			0x08
#define EAST			0x04
#define SOUTH           0x02
#define WEST			0x01

//#define SEARCH_MASK 0b00010000
//#define NORTH_MASK 0b00001000
//#define EAST_MASK 0b00000100
//#define SOUTH_MASK 0b00000010
//#define WEST_MASK 0b00000001
const uint8_t SEARCH_MASK = 0b00010000;
const uint8_t NORTH_MASK = 0b00001000;
const uint8_t EAST_MASK = 0b00000100;
const uint8_t SOUTH_MASK = 0b00000010;
const uint8_t WEST_MASK = 0b00000001;

//Base Define
#define HIGH            true
#define LOW             false
#define STOP            0
#define BOOL_ERROR      false
#define BOOL_SUCCESS    true




#endif
