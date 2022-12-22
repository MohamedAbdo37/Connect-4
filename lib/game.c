#include <stdio.h>
#include <stdlib.h>
#include "display.h"

char * cell;
int hight , width ,move_1 ,move_2 ;
int p1_score , p2_score ;


void setRowsAndColumns(int x , int y){
    hight = y;
    width = x;
}

void setCellPointer(char * i){
    cell = i ;
}

int checkcol (int col){
   int place = col-1;

   while (place < (hight*width))
   {
        if (*(cell+place)!=32)
            break;
        place += width;
   }

   return place - width;
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

    if (*col > 0 && *col <= width){
        system("cls");
        addX(*col);
        move_1++;
    }
    else{
        system("cls");
        printf("\n\"Invalid number ,Please try again!\"\n");
        void player_1(col);
    }
}

void player_2(int * col){
    
    printf("Player 2 choose a column");
    scanf("%d",col);

    if (*col > 0 && *col <= width){
        system("cls");
        addO(*col);
        move_2++;
    }
    else{
        system("cls");
        printf("\n\"Invalid number ,Please try again!\"\n");
        void player_2(col);
    }
}

void game(int * selection){

    system("cls");

    move_1 = 0 ;
    move_2 = 0 ;

    while( (move_1 + move_2) < (hight*width)){

        game_display(p1_score,p2_score,move_1,move_2);

        if((move_1 + move_2)%2 == 0)
            player_1(selection);

        else
            player_2(selection);

    }
}