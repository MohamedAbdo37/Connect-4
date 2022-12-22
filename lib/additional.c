#include <stdio.h>
#include <time.h>
#include <math.h>

int intial ;

void setIntialTime(int time){
    intial = time ;
}

void timePassed(){
    clock_t time = clock() ;
    int sec = (time/CLOCKS_PER_SEC) - intial ;
    timeFormat(sec);
}

void timeFormat(int sec){
    printf("%d : %d",sec/60,sec%60);  
}
