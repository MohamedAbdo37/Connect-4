#include <stdio.h>
#include <time.h>


clock_t intial ;

void setIntialTime(clock_t time){
    extern clock_t intial = time ;
}
void timePassed(){
    clock_t time = clock() - intial ;
    int sec = time /CLOCKS_PER_SEC ;
    timeFormat(time);
}

void timeFormat(int sec){
    int min = sec/60 ;

    printf("%d : %d",min,sec%60);  
}
