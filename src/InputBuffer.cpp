//
// Created by baislsl on 17-8-23.
//

#include <iostream>
#include "InputBuffer.h"
#include <error.h>

int InputBuffer::defaultKeyConductFunc(InputBuffer &inputBuffer, std::string name, code_t id) {
    Cursor& cursor = inputBuffer.cursor;
    inputBuffer.buffer.append(name);
    std::cout << name << std::flush;
    inputBuffer.moveEnd();
    return 0;
}


int InputBuffer::KeyRight(InputBuffer &inputBuffer, std::string name, code_t id) {
    Cursor& cursor = inputBuffer.cursor;

    if (cursor.getPos() == inputBuffer.buffer.size()) {
        inputBuffer.buffer.push_back(' ');
        std::cout << ' ' << std::flush;
        inputBuffer.moveEnd();
    } else {
        cursor.shiftRight();
    }
}

int InputBuffer::KeyLeft(InputBuffer &inputBuffer, std::string name, code_t id) {
    Cursor& cursor = inputBuffer.cursor;
    if (cursor.getPos() != 0) {
        cursor.shiftLeft();
    }
}

int InputBuffer::KeyCtrlLeft(InputBuffer &inputBuffer, std::string name, code_t id) {
    Cursor& cursor = inputBuffer.cursor;
    int pos = cursor.getPos();
    while (inputBuffer.buffer[pos] <= ' ' && pos >= 0)
        --pos;
    while (inputBuffer.buffer[pos] > ' ' && pos >= 0)
        --pos;

    cursor.setPos(pos);
}

int InputBuffer::KeyCtrlRight(InputBuffer &inputBuffer, std::string name, code_t id){
    Cursor& cursor = inputBuffer.cursor;
    int pos = cursor.getPos();
    while (inputBuffer.buffer[pos] <= ' ' && pos <= inputBuffer.buffer.size())
        ++pos;
    while (inputBuffer.buffer[pos] > ' ' && pos <= inputBuffer.buffer.size())
        ++pos;

    cursor.setPos(pos);
}

void InputBuffer::moveEnd() {
    cursor.setPos(static_cast<int>(buffer.size()), false);
}

std::string InputBuffer::flush() {
    cursor.setPos(0);
    std::string ret = buffer;
    buffer.clear();
    return ret;
}

int InputBuffer::KeyTab(InputBuffer &inputBuffer, std::string name, code_t id) {
    if(inputBuffer.cursor.getPos() != inputBuffer.buffer.size()) return 0;




    return 0;
}

int InputBuffer::KeyEnter(InputBuffer &inputBuffer, std::string name, code_t id) {

    return 1;
}



