//
// Created by baislsl on 17-8-20.
//

#ifndef INPUTHANDLER_TERMINAL_H
#define INPUTHANDLER_TERMINAL_H

#include <string>
#include <functional>
#include "InputEngine.h"
#include "Util.h"
#include "InputBuffer.h"

class Terminal {
public:
    Terminal();

    void start();

    virtual ~Terminal();





private:
    InputEngine inputEngine;
    InputBuffer buffer;
};





#endif //INPUTHANDLER_TERMINAL_H
