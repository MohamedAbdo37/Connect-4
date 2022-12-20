#include <stdio.h>
#include <time.h>

#include "lib/menu.h"
#include "lib/display.h"
#include "lib/additional.h"

void main(void){

    clock_t time = clock();

    int width = 5 , hight = 6;
    char board[hight][width];

    setIntialTime(time) ;
    setDimension(width,hight);
    setEmptyBoard(&board[0][0]);

    int selectoin;
    mainMenu_display(&selectoin);

}
