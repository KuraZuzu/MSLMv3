/*!
* @file switch v1.0
* @Copyright © 2018 Aoi Yamanishi
* @date 2018.11.16
*
* Released under the MIT license.
* see https://opensource.org/licenses/MIT
*/

#ifndef SWITCH_H
#define SWITCH_H
#include "deftype.h"
#include "mbed.h"
class Switch{
private:
    DigitalIn _SWInput;	//SWが付いているmbedのピン番号
    PinMode _iniSet;	//PullUp, PullDown, PullNone
    bool SWcheck;	//SWも連続入力防止用
    bool old_SW;	//１つ前の入力状態を保持
    bool skip_flg;		//スイッチ入力後チャタリング対策に一定時間無視する為のフラグ
    void skip_Func(){
        wait(0.05);
        skip_flg = false;
    }

public:
    Switch(PinName pin, PinMode pull) : _SWInput(pin,pull), _iniSet(pull){
        //_SWInput.mode(pull);
        SWcheck = false;
        old_SW = false;
        skip_flg = false;
    }

    //入力状態の確認
    bool update(void){
        if(_iniSet == PullUp || _iniSet == PullNone){   //勝手に、突貫でPullNoneのモードも追加
            if(!skip_flg){
                if(!_SWInput && !old_SW){
                    old_SW = true;
                    return true;
                }else if(_SWInput && old_SW){
                    old_SW = false;
                    return false;
                }
                skip_flg = true;
                skip_Func();
            }
            return false;
        }else{
            if(!skip_flg){
                if(_SWInput && !old_SW){
                    old_SW = true;
                    return true;
                }else if(!_SWInput && old_SW){
                    old_SW = false;
                    return false;
                }
                skip_flg = true;
                skip_Func();
            }
            return false;
        }
    }

};
#endif
