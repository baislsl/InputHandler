//
// Created by baislsl on 17-8-23.
//

#ifndef INPUTHANDLER_KEYCODE_H
#define INPUTHANDLER_KEYCODE_H


#include <cstdio>
#include <iosfwd>
#include <cstring>
#include <vector>



typedef unsigned long code_t;

struct Key {
    std::string code;
    code_t id;
};

class KeyCode {
public:

    KeyCode(const char cc);

    KeyCode(const char *cc);

    virtual ~KeyCode();

    code_t get() const;

    std::string getName() const;

    const char *getcStr() const;

    friend std::ostream &operator<<(std::ostream &out, const KeyCode &keyCode);

private:
    std::string code;
    code_t id;

    void setId();


};

inline
std::ostream &operator<<(std::ostream &out, const KeyCode &keyCode) {
    out << keyCode.getName();
    return out;
}

enum KeyType{
    CTRL = ~((-1) >> 1),
    ALT = (~((-1) >> 2)) ^CTRL,
    SHIFT = (~((-1) >> 3)) ^ ALT & CTRL,
    LEFT = 10000,
    RIGHT = 10001,
    UP = 10002,
    DOWN = 10003
};

static const Key keyList[] = {
        {"\01",          CTRL | 'a'},
        {"\033\141",     ALT | 'a'},
        {"\033\133\104", LEFT},
        {"\033\133\103", RIGHT},
        {"\033\133\101", UP},
        {"\033\133\102", DOWN},
        {"\033\133\061\073\062\104", SHIFT | LEFT},
        {"\033\133\061\073\062\103", SHIFT | RIGHT},
        {"\033\133\061\073\063\104", ALT | LEFT},
        {"\033\133\061\073\063\103", ALT | RIGHT},
        {"\033\133\061\073\064\104", SHIFT | ALT | LEFT},
        {"\033\133\061\073\064\103", SHIFT | ALT | RIGHT},
        {"a",            'a'},
        {"A",            'A'},
        {"\033",         033}
};



#endif //INPUTHANDLER_KEYCODE_H
