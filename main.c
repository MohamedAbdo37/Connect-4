#include <stdio.h>
#include <time.h>
#include <string.h>

#include "lib/menu.h"
#include "lib/display.h"
#include "lib/additional.h"

void main(void){

    clock_t time = clock();
    
    int width = 9 , hight = 7 , highScore =10;
    char path[262] ;
    int selectoin;
    

    setIntialTime(time/CLOCKS_PER_SEC);
    setSelection(&selectoin);
    

    xmlPath_display(path);
    setArgs(&width,&hight,&highScore);

    int stack_undo[width*hight];
    int stack_redo[width * hight];
    char board[hight][width];

    setEmptyBoard(&board[0][0],&stack_undo[0],&stack_redo[0]);
    mainMenu_display(&selectoin);

}



