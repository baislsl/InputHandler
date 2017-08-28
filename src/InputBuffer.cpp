//
// Created by baislsl on 17-8-23.
//

#include <iostream>
#include "InputBuffer.h"

int InputBuffer::defaultKeyConductFunc(InputBuffer &inputBuffer, std::string name, code_t id) {

    inputBuffer.readin(name);

    std::cout << name << std::flush;
    return 0;
}

int InputBuffer::KeyUp(InputBuffer &inputBuffer, std::string name, code_t id){
    std::cout << "call up" << std::flush;
}