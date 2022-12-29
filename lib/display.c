#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "additional.h"
#include "game.h"

int width = 9;
int hight = 7;
char * cell ;
int * selection ;

void setSelection(int *s){
    selection = s ;
}


void color(int value)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,value);
}

void setDimension(int x, int y){
    width = x;
    hight = y;

    setRowsAndColumns(x,y);
}

void setEmptyBoard(char * array){
    cell = array ;
    setCellPointer(array);

    for(int i = 0 ; i < width * hight ; i++)
       *(cell+i)= 32;

}

void mainMenu_display(){

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
    color(0x01);
    printf("\n\t\t|");
    for(int i = 0 ; i< width * hight ; i++){
        if(i%width == 0 && i!= 0){
            printf("\n\t\t");
            for (int i=0;i<=4*width ;i++)
                printf("%c",205);

            printf("\n\t\t|");
        }
        if (*(cell+i)==88){
        color(0x04);
        printf(" %c",*(cell+i));}
        else if (*(cell+i)==79){
        color(0x06);
        printf(" %c",*(cell+i));}
        else {
            printf(" %c",*(cell+i));
        }

        color(0x01);
        printf(" |");
    }
    printf("\n\t\t");

    for (int i=0 ;i <= 4 * width ;i++)
                printf("%c",205);

    printf("\n\t\t ");
    color(0x07);

    for (int i=0;i<width ;i++)
        printf(" %d  ",i+1);
    printf("\n");

}

void game_display(int player_1 ,int player_2,int move_1 ,int move_2){
    color(0x07);

    printf("\ntime\t");
    timePassed();

    printf("\nMoves :");

    printf("\nPlayer 1 : %4d \t",move_1);
    printf("Player 2 : %4d \n",move_2);

    printf("\nScore :");

    printf("\nPlayer 1 : %4d point\t",player_1);
    printf("Player 2 : %4d point\n",player_2);

    board_display();

}


void top_players_display(){
   for (int i=0;i<10;i++){
    printf("%c %d:\n-------------------------------\n",16,i+1);
   }
printf ("\n%c 1-Back\n",16);
printf ("\n%c 2-Quit\n",16);
top_players_menu(selection);
}


void load_display(){
    printf("%c Saved Game 1\n",16);
    printf("%c Saved Game 2\n",16);
    printf("%c Saved Game 3\n",16);
    printf ("\n%c 1-Back\n",16);
    printf ("%c 2-Quit\n",16);
    load_menu(selection);

}
int stack_undo[9*7];
int stack_redo[9*7];
int top_undo=-1;
int top_redo=63;
void push_undo (int place)
{
    top_undo++;
    stack_undo[top_undo]=place;
}
void undo (void)
{
    *(cell+stack_undo[top_undo])=32;
    push_redo(stack_undo[top_undo]);
    top_undo--;

}
void push_redo (int place)
{
    top_redo--;
    stack_redo[top_redo]=place;
}
void redo (char ch)
{
    *(cell+stack_redo[top_redo])=ch;
    push_undo(stack_redo[top_redo]);
     top_redo++;

}

void xmlPath_display(){

    printf("%c",201);

    for (int i=0;i<35+9;i++)
        printf("%c",205);

    printf("%c\n",187);

    printf("%c         %c 1-Enter Path                     %c\n",186,16,186);
    printf("%c         %c 2-Use difulte path               %c\n",186,16,186);
    printf("%c         %c 3-Use difulte configurations     %c\n",186,16,186);
    printf("%c         %c 4-Quit                           %c\n",186,16,186);


    for (int i=0;i<1;i++){
        printf("%c                                   ",186);
        printf("%c\n",186);
    }
    printf("%c",200);

    for (int i=0;i<35+9;i++)
        printf("%c",205);

    printf("%c\n",188);
    printf("%c ",16);
    xmlPath(selection);
}





