//
// Created by baislsl on 17-8-28.
//

#ifndef INPUTHANDLER_CURSOR_H
#define INPUTHANDLER_CURSOR_H


class Cursor {
public:
    Cursor(){}

    void shiftLeft(int count = 1);

    void shiftRight(int count = 1);

    void setPos(int position, bool update = true);

    int getPos();

private:
    int pos;
};


#endif //INPUTHANDLER_CURSOR_H
