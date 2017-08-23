#pragma once

#include<string>
#include <termios.h>
#include "KeyCode.h"

class InputEngine {
public:
    InputEngine();

    InputEngine(InputEngine& inputEngine) = delete;

    InputEngine operator=(const InputEngine&) = delete;

    virtual ~InputEngine();

    int open();

    int close();

    bool isRunning();

    KeyCode next();

private:
    struct termios		save_termios;
    int					ttysavefd = -1;
    enum { RESET, RAW, CBREAK }	ttystate = RESET;
    void flush();

    int ttyRaw(int fd);
    int ttyReset(int fd);

    int setNoBlock();

    int resetNoBlock();

};