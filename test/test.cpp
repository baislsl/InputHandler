//
// Created by baislsl on 17-8-20.
//

#include <iostream>
#include <termios.h>
#include <zconf.h>
#include <stdio.h>
#include <curses.h>
#include <cstring>
#include <signal.h>
#include "../src/ttymodes.h"
#include <stdlib.h>

static void err_sys(char *msg){
    write(STDERR_FILENO, msg, strlen(msg));
}

static void
sig_catch(int signo)
{
    printf("signal caught\n");
    tty_reset(STDIN_FILENO);
    exit(0);
}

void test_tty(){
    int		i;
    char	c;

    if (signal(SIGINT, sig_catch) == SIG_ERR)	/* catch signals */
        err_sys("signal(SIGINT) error");
    if (signal(SIGQUIT, sig_catch) == SIG_ERR)
        err_sys("signal(SIGQUIT) error");
    if (signal(SIGTERM, sig_catch) == SIG_ERR)
        err_sys("signal(SIGTERM) error");

    if (tty_raw(STDIN_FILENO) < 0)
        err_sys("tty_raw error");
    printf("Enter raw mode characters, terminate with DELETE\n");
    while ((i = read(STDIN_FILENO, &c, 1)) == 1) {
        if ((c &= 255) == 0177)		/* 0177 = ASCII DELETE */
            break;
        printf("%o\n", c);
    }
    if (tty_reset(STDIN_FILENO) < 0)
        err_sys("tty_reset error");
    if (i <= 0)
        err_sys("read error");
    if (tty_cbreak(STDIN_FILENO) < 0)
        err_sys("tty_cbreak error");
    printf("\nEnter cbreak mode characters, terminate with SIGINT\n");
    while ((i = read(STDIN_FILENO, &c, 1)) == 1) {
        c &= 255;
        printf("%o\n", c);
    }
    if (tty_reset(STDIN_FILENO) < 0)
        err_sys("tty_reset error");
    if (i <= 0)
        err_sys("read error");

    exit(0);
}

int main(){
    test_tty();
    char c;


    std::cout << "\033[2J" << std::flush;
    struct termios attr;
    tcgetattr(STDIN_FILENO, &attr);

    printf("cf : %x\n", attr.c_lflag);
    printf("min=%d, time=%d\n", attr.c_cc[VMIN], attr.c_cc[VTIME]);
    attr.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSADRAIN, &attr);

    while((c = getchar())){
        printf("Input : 0x%x : %c\n", c, c);
    }
    int k = KEY_EXIT;

    while(read(STDIN_FILENO, &c, 1) == 1){
        printf("Input : 0x%x : %c\n", c, c);
    }
//

}
