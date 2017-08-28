//
// Created by baislsl on 17-8-23.
//

#ifndef INPUTHANDLER_KEYCODE_H
#define INPUTHANDLER_KEYCODE_H


#include <cstdio>
#include <iosfwd>
#include <cstring>
#include <vector>
#include <functional>
#include "Util.h"


enum KeyType {
    CTRL = 0x800000,
    ALT = 0x400000,
    SHIFT = 0x200000,
    LEFT = 0x100,
    RIGHT = 0x101,
    UP = 0x102,
    DOWN = 0x103
};


class InputBuffer;
using KeyConductFunc =  std::function<int(InputBuffer&, std::string, code_t)>;
// typedef int KeyConductFunc(Terminal*, std::string, code_t);
class KeyCode {
public:
    std::string code;
    code_t id;
    KeyConductFunc conductFunc;

    static KeyCode getKeyCode(std::string);

    KeyCode(std::string& _code, code_t _id);

    KeyCode(std::string& _code, code_t _id, KeyConductFunc func);

private:

};







#endif //INPUTHANDLER_KEYCODE_H
