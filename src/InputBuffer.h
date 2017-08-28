//
// Created by baislsl on 17-8-23.
//

#ifndef INPUTHANDLER_INPUTBUFFER_H
#define INPUTHANDLER_INPUTBUFFER_H


#include <glob.h>
#include <functional>
#include "KeyCode.h"
#include "Util.h"

class InputBuffer {
public:
    InputBuffer():cursor(0){
    }

    static int defaultKeyConductFunc(InputBuffer& inputBuffer, std::string name, code_t id);
    static int KeyUp(InputBuffer& inputBuffer, std::string name, code_t id);

    std::string flush(){
        cursor = 0;
        std::string ret = std::move(buffer);
        buffer.clear();
    }

    int readin(char cc){
        buffer.push_back(cc);
        moveEnd();
    }

    int readin(std::string str){
        buffer.append(str);
        moveEnd();
    }

    int moveRight();


private:
    size_t cursor;
    std::string buffer;

    // move cursor to the end of the input
    void moveEnd(){
        cursor = buffer.size();
    }

};

#endif //INPUTHANDLER_INPUTBUFFER_H
