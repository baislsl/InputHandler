//
// Created by baislsl on 17-8-20.
//

#include <iostream>
#include "Terminal.h"
#include "KeyCode.h"

Terminal::Terminal()
        : inputEngine() {

}

Terminal::~Terminal() {

}

std::string Terminal::readline() {
    inputEngine.open();
    int flag = 0;
    while (true) {
        KeyCode key = inputEngine.next();
        std::string code = key.code;
        flag = (key.conductFunc)(buffer, key.code, key.id);
        if (code == "q") exit(0);
        if (flag == 1)
            break;
    }
    inputEngine.close();
    return buffer.flush();
}


