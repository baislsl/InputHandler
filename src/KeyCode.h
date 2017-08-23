//
// Created by baislsl on 17-8-23.
//

#ifndef INPUTHANDLER_KEYCODE_H
#define INPUTHANDLER_KEYCODE_H


#include <cstdio>
#include <iosfwd>
#include <cstring>

class KeyCode {
public:

    virtual ~KeyCode(){
        delete code;
    }

    KeyCode(const char cc){
        code = new char[2];
        code[0] = cc;
        code[1] = 0;
    }

    KeyCode(const char* cc, size_t size){
        code = new char(size + 1);
        strncpy(code, cc, size);
        code[size] = 0;
    }

    const char* get(){
        return code;
    }

//    std::ostream&operator<<(std::ostream& out, const KeyCode& keyCode){
//
//    }

private:
    char *code;
    size_t codeSize;

};


#endif //INPUTHANDLER_KEYCODE_H
