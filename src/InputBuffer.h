//
// Created by baislsl on 17-8-23.
//

#ifndef INPUTHANDLER_INPUTBUFFER_H
#define INPUTHANDLER_INPUTBUFFER_H


#include <glob.h>
#include <functional>
#include "KeyCode.h"
#include "Util.h"
#include "Cursor.h"

class InputBuffer {
public:
    InputBuffer() : cursor() {
    }

    static int defaultKeyConductFunc(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyUp(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyDown(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyRight(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyLeft(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyCtrlUp(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyCtrlDown(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyCtrlRight(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyCtrlLeft(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyTab(InputBuffer &inputBuffer, std::string name, code_t id);

    static int KeyEnter(InputBuffer &inputBuffer, std::string name, code_t id);

    std::string flush();


private:
    Cursor cursor;
    std::string buffer;

    // move cursor to the end of the input
    void moveEnd();




    int moveRight();

};

#endif //INPUTHANDLER_INPUTBUFFER_H
