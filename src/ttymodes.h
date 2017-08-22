//
// Created by baislsl on 17-8-22.
//

#ifndef INPUTHANDLER_TTYMODES_C_H
#define INPUTHANDLER_TTYMODES_C_H

int
tty_cbreak(int fd);


int
tty_raw(int fd);

int
tty_reset(int fd);


void
tty_atexit(void);

struct termios *
tty_termios(void);

#endif //INPUTHANDLER_TTYMODES_C_H
