/*================================================================
*   Copyright (C) 2023 Goodfanqie. All rights reserved.
*   
*   File   name：main.cpp
*   Created  by：Goodfanqie
*   Create Date：2023.03.09.
*   Description：
*
================================================================*/

#include <signal.h>
#include "src/ping.h"

Ping * p;

void SingnalHandler(int signo) {

    p->statistic();

    exit(0);
}

int main(int argc, char * argv[]) {
    struct sigaction action;

    action.sa_handler = SingnalHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGINT,&action,NULL);

    Ping ping(argv[1], 1);
    p = &ping;
    ping.CreateSocket();
    while(1)
    {
        ping.SendPacket();
        ping.RecvPacket();
        sleep(1);
    }
}
