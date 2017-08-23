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
#include <stdlib.h>
#include "InputEngine.h"

static void err_sys(std::string msg){
    write(STDERR_FILENO, msg.c_str(), strlen(msg.c_str()));
}

static void err_sys(char *msg){
    write(STDERR_FILENO, msg, strlen(msg));
}

//static void
//sig_catch(int signo)
//{
//    printf("signal caught\n");
//    tty_reset(STDIN_FILENO);
//    exit(0);
//}

void test1(){
    InputEngine ie;
    ie.open();
    while(true){
        KeyCode keyCode = ie.next();
        puts("\033[2J\033[;H\033[0m");
        std::string p = keyCode.getName();
        for(char cc : p){
            printf("_%o_", cc);
        }
        printf("\n%lx",keyCode.get());

        // printf("%s:end\n", keyCode.get());
        fflush(stdout);

        if(p == "q") break;
    }
    ie.close();
}


int main(){
    test1();

}


//void test_tty(){
//    int		i;
//    char	c;
//
//
//    if (signal(SIGINT, sig_catch) == SIG_ERR)	/* catch signals */
//        err_sys("signal(SIGINT) error");
//    if (signal(SIGQUIT, sig_catch) == SIG_ERR)
//        err_sys("signal(SIGQUIT) error");
//    if (signal(SIGTERM, sig_catch) == SIG_ERR)
//        err_sys("signal(SIGTERM) error");
//
//    if (tty_raw(STDIN_FILENO) < 0)
//        err_sys("tty_raw error");
//    printf("Enter raw mode characters, terminate with DELETE\n");
//    while ((i = read(STDIN_FILENO, &c, 1)) == 1) {
//        if ((c &= 255) == 0177)		/* 0177 = ASCII DELETE */
//            break;
//        printf("%o\n", c);
//    }
//    if (tty_reset(STDIN_FILENO) < 0)
//        err_sys("tty_reset error");
//    if (i <= 0)
//        err_sys("read error");
//    if (tty_cbreak(STDIN_FILENO) < 0)
//        err_sys("tty_cbreak error");
//    printf("\nEnter cbreak mode characters, terminate with SIGINT\n");
//    while ((i = read(STDIN_FILENO, &c, 1)) == 1) {
//        c &= 255;
//        printf("%o\n", c);
//    }
//    if (tty_reset(STDIN_FILENO) < 0)
//        err_sys("tty_reset error");
//    if (i <= 0)
//        err_sys("read error");
//
//    exit(0);
//}

