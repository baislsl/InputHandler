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

void Terminal::start() {
    inputEngine.open();
    bool flag = false;
    while(true){
        KeyCode key = inputEngine.next();
        std::string code = key.code;
        (key.conductFunc)(buffer, key.code, key.id);
        if(flag || code == "q")
            break;
    }
    inputEngine.close();
}


