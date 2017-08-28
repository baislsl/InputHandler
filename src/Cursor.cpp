//
// Created by baislsl on 17-8-28.
//

#include <iostream>
#include "Cursor.h"

void Cursor::shiftLeft(int count) {
    pos -=count;
    std::cout << "\033[" << count << "D" << std::flush;
}

void Cursor::shiftRight(int count) {
    pos += count;
    std::cout << "\033[" << count << "C" << std::flush;
}

void Cursor::setPos(int position, bool update) {
    if(update){
        if (pos < position) {
            shiftRight(position - pos);
        } else if (pos > position) {
            shiftLeft(pos - position);
        }
    }else{
        pos = position;
    }
}

int Cursor::getPos() {
    return pos;
}
