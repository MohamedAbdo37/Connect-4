#include <stdio.h>
#include <time.h>
#include <string.h>

#include "lib/menu.h"
#include "lib/display.h"
#include "lib/additional.h"

void main(void){

    clock_t time = clock();

    int selectoin;
    int width = 5 , hight = 6;
    char board[hight][width];
    char path[262] ;

    FILE * ptr;

    printf("Enter Xml Path :\n");
    fgets(path,261,stdin);
    

    setIntialTime(time/CLOCKS_PER_SEC);
    setDimension(width,hight);
    setSelection(&selectoin);
    setEmptyBoard(&board[0][0]);

    
    mainMenu_display(&selectoin);

}