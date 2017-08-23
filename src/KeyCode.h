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
    CTRL = 0x800000,
    ALT = 0x400000,
    SHIFT = 0x200000,
    LEFT = 0x100,
    RIGHT = 0x101,
    UP = 0x102,
    DOWN = 0x103
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
        {"\033\133\061\073\065\104", CTRL | ALT | LEFT},
        {"\033\133\061\073\065\103", CTRL | ALT | RIGHT},
        {"a", 'a'},
        {"A", 'A'},
        {"b", 'b'},
        {"B", 'B'},
        {"c", 'c'},
        {"C", 'C'},
        {"d", 'd'},
        {"D", 'D'},
        {"e", 'e'},
        {"E", 'E'},
        {"f", 'f'},
        {"F", 'F'},
        {"g", 'g'},
        {"G", 'G'},
        {"h", 'h'},
        {"H", 'H'},
        {"i", 'i'},
        {"I", 'I'},
        {"j", 'j'},
        {"J", 'J'},
        {"k", 'k'},
        {"K", 'K'},
        {"l", 'l'},
        {"L", 'L'},
        {"m", 'm'},
        {"M", 'M'},
        {"n", 'n'},
        {"N", 'N'},
        {"o", 'o'},
        {"O", 'O'},
        {"p", 'p'},
        {"P", 'P'},
        {"q", 'q'},
        {"Q", 'Q'},
        {"r", 'r'},
        {"R", 'R'},
        {"s", 's'},
        {"S", 'S'},
        {"t", 't'},
        {"T", 'T'},
        {"u", 'u'},
        {"U", 'U'},
        {"v", 'v'},
        {"V", 'V'},
        {"w", 'w'},
        {"W", 'W'},
        {"x", 'x'},
        {"X", 'X'},
        {"y", 'y'},
        {"Y", 'Y'},
        {"z", 'z'},
        {"Z", 'Z'},
        {"\033",         033}
};



#endif //INPUTHANDLER_KEYCODE_H
