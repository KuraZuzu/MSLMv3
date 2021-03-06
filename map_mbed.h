/*!
* @file map_mbed.h v1.0
* @Copyright © 2018 Aoi Yamanishi
* @date 2018.11.16
*
* Released under the MIT license.
* see https://opensource.org/licenses/MIT
*/

#ifndef MSLMV3_MAP_MBED_H
#define MSLMV3_MAP_MBED_H

#include "map3.h"
#include "fstream"

class Map_Mbed : public Map3 {
public:
    using Map3::Map3;
    void write_map();
};


#endif //MSLMV3_MAP_MBED_H
