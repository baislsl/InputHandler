//
// Created by baislsl on 17-8-20.
//

#include <iostream>
#include <termios.h>
#include <zconf.h>
#include <stdio.h>
#include <cstring>
#include <signal.h>
#include <stdlib.h>
#include "InputEngine.h"
#include "Terminal.h"

static void err_sys(std::string msg){
    write(STDERR_FILENO, msg.c_str(), strlen(msg.c_str()));
}

static void err_sys(char *msg){
    write(STDERR_FILENO, msg, strlen(msg));
}


void test1(){
    InputEngine ie;
    ie.open();
    while(true){
        std::string p = ie.next().code;
        puts("\033[2J\033[;H\033[0m");
        for(char cc : p){
            printf("_%o_", cc);
        }
        fflush(stdout);

        if(p == "q") break;
    }
    ie.close();
}

void terminalTest(){
    Terminal terminal;
    while(true){
        auto s = terminal.readline();
        std::cout << s;
        if(s.size() < 2) break;

    }
}


int main(){
    // test1();
    terminalTest();
}


