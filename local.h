
#ifndef __LOCAL_H_
#define __LOCAL_H_


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <math.h>
#include <sys/ipc.h>
#include <time.h>
#include <sys/msg.h>
#include <sys/shm.h>         
#include <errno.h>
#include <signal.h>
#include <semaphore.h>  
#include <stdint.h>
#include <sys/mman.h>

#define B_SIZ (PIPE_BUF / 2)

//#define waiting_room_capacity 20


#define number_of_people 100
#define number_of_tellers  4
#define waiting_room_capacity 20
#define inner_grouping_area_capacity 10
#define teller_period_of_time 10



struct person{
    int ID;
    char gander;
    int request;
    int has_metal;
    int incomplete;
    int patiant;
}p;


struct message {
char   fifo_name[B_SIZ];
};

void tc_clear_screen()
{
    printf("\e[1;1H\e[2J");
}
void red ()
{
    printf("\033[1;31m");
}
void green ()
{
    printf("\033[1;32m");
}
void yellow()
{
    printf("\033[1;33m");
}

void blue()
{
    printf("\033[0;34m");
}
void normals()
{
    printf("\033[0;37m");
}

void cyan()
{
    printf("\033[1;36m");
    fflush(stdout);

}

#endif