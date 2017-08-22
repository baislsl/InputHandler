//
// Created by baislsl on 17-8-20.
//

#include <iostream>
#include "Terminal.h"

Terminal::Terminal() {

}

Terminal::~Terminal() {

}


std::string getline(){
    std::string ret;
    getline(std::cin, ret);
    return ret;
}

void Terminal::close() {

}

void Terminal::open() {

}
