#ifndef DEF_TYPE_H
#define DEF_TYPE_H

#define pi 3.14159265
#define CIRCLE_R 28.0 //タイヤの半径
#define WIDTH 77.7 //マシンの車幅


//Public Function Relation
#define INT_MODE		0   /* Return mode select */
#define BOOL_MODE		1

//Map Relation
#define FRONT_MACHINE	0
#define NORTH			0x08
#define EAST			0x04
#define SOUTH           0x02
#define WEST			0x01

#define NORTH_MASK 0b00001000
#define EAST_MASK 0b00000100
#define SOUTH_MASK 0b00000010
#define WEST_MASK 0b00000001

//Base Define
#define HIGH            true
#define LOW             false
#define STOP            0
#define BOOL_ERROR      false
#define BOOL_SUCCESS    true


#endif
