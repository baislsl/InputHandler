//
// Created by baislsl on 17-8-23.
//

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;


int main(){

    puts("");

    char cc = 'a', cb = 'A';
    for(int i=0;i<26;i++){
        printf("{\"%c\", \'%c\'},\n", cc, cc);
        printf("{\"%c\", \'%c\'},\n", cb, cb);
        ++cc; ++cb;

    }
}