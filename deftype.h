/*!
* @file deftype.h v1.0
* @Copyright © 2018 Kazushi Kurasawa
* @date 2018.11.16
*
* Released under the MIT license.
* see https://opensource.org/licenses/MIT
*/

#ifndef DEF_TYPE_H
#define DEF_TYPE_H

#include <mbed.h>

#define PI 3.14159265

const uint8_t SEARCH_MASK = 0b00010000;
const uint8_t NORTH_MASK = 0b00001000;
const uint8_t EAST_MASK = 0b00000100;
const uint8_t SOUTH_MASK = 0b00000010;
const uint8_t WEST_MASK = 0b00000001;

#endif
