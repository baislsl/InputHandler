////
//// Created by baislsl on 17-8-23.
////
//

#include "KeyCode.h"
#include "Terminal.h"

static const KeyCode keyList[] = {
//        {"\177",                     0177}, // break
//        {"\01",                      CTRL | 'a'},
        {"\033\141",                 ALT | 'a'},
        {"\033\133\104",             LEFT, InputBuffer::KeyLeft},
        {"\033\133\103",             RIGHT, InputBuffer::KeyRight},
        {"\033\133\101",             UP},
        {"\033\133\102",             DOWN},
        {"\033\133\061\073\062\104", SHIFT | LEFT},
        {"\033\133\061\073\062\103", SHIFT | RIGHT},
        {"\033\133\061\073\063\104", ALT | LEFT},
        {"\033\133\061\073\063\103", ALT | RIGHT},
        {"\033\133\061\073\064\104", SHIFT | ALT | LEFT},
        {"\033\133\061\073\064\103", SHIFT | ALT | RIGHT},
        {"\033\133\061\073\065\104", CTRL | LEFT, InputBuffer::KeyCtrlLeft},
        {"\033\133\061\073\065\103", CTRL | RIGHT, InputBuffer::KeyCtrlRight},
};


KeyCode::KeyCode(std::string _code, code_t _id)
        : code(_code), id(_id), conductFunc(InputBuffer::defaultKeyConductFunc) {}

KeyCode::KeyCode(std::string _code, code_t _id, KeyConductFunc func)
        : code(_code), id(_id), conductFunc(func) {}


KeyCode KeyCode::getKeyCode(std::string code) {
    for (const KeyCode &key : keyList) {
        if (key.code == code) {
            return key;
        }
    }
    return KeyCode(code, (code_t) code[0]);
}
