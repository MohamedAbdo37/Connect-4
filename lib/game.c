#include <stdio.h>
#include <stdlib.h>
#include "display.h"

char * cell;
int hight , width ,move ;
int p1_score , p2_score ;


void setRowsAndColumns(int x , int y){
    hight = y;
    width = x;
}

void setCellPointer(char * i){
    cell = i ;
}

int checkcol (int col){
   int place=col-1;

   while (place < (hight*width))
   {
        if (*(cell+place)!=32)
            break;
        place += width;
   }
   return place-1;
}

void addX(int col){
    int p = checkcol(col);

    *(cell+p) = 88;
}

void addO(int col){
    int p = checkcol(col);
    
    *(cell+p) = 79;
}

void player_1(int * col){
    printf("Player 1 choose a column");
    scanf("%d",col);

    if (*col > 0 && *col < width){
        system("cls");
        addX(*col);
    }
    else{
        printf("Invalid number ,Please try again");
        void player_1(col);
    }
}

void player_2(int * col){
    
    printf("Player 2 choose a column");
    scanf("%d",col);

    if (*col > 0 && *col <= width){
        system("cls");
        addO(*col);
    }
    else{
        printf("Invalid number ,Please try again");
        void player_2(col);
    }
}

void game(int * selection){

    system("cls");
    move = 1 ;
    while(move < (hight*width)+1){

        game_display(p1_score,p2_score,move/2);

        if(move%2){
            player_2(selection);
            move++;
        }
        else{
            player_1(selection);
            move++;
        }

    }
}