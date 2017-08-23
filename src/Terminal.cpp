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
        (key.conductFunc)(this, key.code, key.id);
        if(flag || code == "q")
            break;
    }
    inputEngine.close();
}

int Terminal::defaultKeyConductFunc(Terminal *terminal, std::string name, code_t id) {
//    auto& inputEngine = terminal->inputEngine;
//    inputEngine.isRunning();
    std::cout << name << std::flush;
    return 0;
}

int Terminal::KeyUp(Terminal *terminal, std::string name, code_t id) {
    std::cout << "call up" << std::flush;
}
