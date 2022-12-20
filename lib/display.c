#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "additional.h"

int width = 9;
int hight = 7;
char * cell ; 

void setDimension(int x, int y){
    extern int width = x;
    extern int hight = y;
}

void setEmptyBoard(char * array){
    extern char * cell = array ;

    for(int i = 0 ; i < width * hight ; i++)
       *(cell+i)= 32;

}

void mainMenu_display(int * selection){

    printf("%c",201);

    for (int i=0;i<35;i++)
        printf("%c",205);

    printf("%c\n",187);

    printf("%c         %c 1-play newgame          %c\n",186,16,186);
    printf("%c         %c 2-load game             %c\n",186,16,186);
    printf("%c         %c 3-Top players           %c\n",186,16,186);
    printf("%c         %c 4-Quit                  %c\n",186,16,186);
    
    for (int i=0;i<1;i++){
        printf("%c                                   ",186);
        printf("%c\n",186);
    }
    printf("%c",200);

    for (int i=0;i<35;i++)
        printf("%c",205);

    printf("%c\n",188);
    printf("%c ",16);
    mainMenu(selection);
}

void playMode_display(int * s){

     printf("%c",201);

    for (int i=0;i<35;i++)
        printf("%c",205);
    
    printf("%c\n",187);
    
    printf("%c         %c 1-Player 1 VS Playr 2   %c\n",186,16,186);
    printf("%c         %c 2-VS Computer           %c\n",186,16,186);
    printf("%c         %c 3-Main menu             %c\n",186,16,186);

    for (int i=0;i<1;i++){
        printf("%c                                   ",186);
        printf("%c\n",186);
    }

    printf("%c",200);

    for (int i=0;i<35;i++)
        printf("%c",205);

    printf("%c\n",188);

    printf("%c",16);
    playMode(s);
}

void board_display(){

    int x = width;
    int y = hight;

    printf("\n\t\t|");
    for(int i = 0 ; i< x * y ; i++){
        if(i%x == 0 && i!= 0){
            printf("\n\t\t");
            for (int i=0;i<=4*x ;i++)
                printf("%c",205);

            printf("\n\t\t|");
        }
        printf(" %c |",*(cell+i));
    }
    printf("\n\t\t");
    
    for (int i=0;i<=4*x ;i++)
                printf("%c",205);

    printf("\n\t\t ");

    for (int i=0;i<x ;i++)
        printf(" %d  ",i+1);
    printf("\n"); 

}

void game_display(int player_1 ,int player_2){
    printf("time\t");
    timePassed();
    printf("\nPlayer 1 : %d point\n",player_1);
    printf("\nPlayer 2 : %d point\n",player_2);

    board_display();
}