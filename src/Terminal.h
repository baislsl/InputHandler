//
// Created by baislsl on 17-8-20.
//

#ifndef INPUTHANDLER_TERMINAL_H
#define INPUTHANDLER_TERMINAL_H

#include <string>

class Terminal {
public:
    Terminal();

    virtual ~Terminal();

private:
    std::string getline();

    void close();

    void open();



};


#endif //INPUTHANDLER_TERMINAL_H
