//
// Created by baislsl on 17-8-20.
//

#ifndef INPUTHANDLER_TERMINAL_H
#define INPUTHANDLER_TERMINAL_H

#include <string>
#include <functional>
#include "InputEngine.h"
#include "Util.h"


class Terminal {
public:
    Terminal();

    void start();

    virtual ~Terminal();

    static int defaultKeyConductFunc(Terminal* terminal, std::string name, code_t id);
    static int KeyUp(Terminal* terminal, std::string name, code_t id);

private:
    InputEngine inputEngine;

};





#endif //INPUTHANDLER_TERMINAL_H
