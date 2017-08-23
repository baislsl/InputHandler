//
// Created by baislsl on 17-8-23.
//

#include <string>
#include <iostream>
#include "KeyCode.h"

KeyCode::KeyCode(const char *cc): code(cc){
    setId();
}

KeyCode::KeyCode(const char cc){
    code = " ";
    code[0] = cc;
    setId();
}

KeyCode::~KeyCode() {

}

std::string KeyCode::getName() const  {
    return code;
}

const char *KeyCode::getcStr() const {
    return code.c_str();
}

void KeyCode::setId() {
    for(const Key& key : keyList){
        if(code == key.code){
            id = key.id;
            return;
        }
    }
    id = 0;
}

code_t KeyCode::get() const {
    return id;
}

