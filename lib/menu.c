#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "display.h"

void mainMenu(int * selection)
{   
    scanf("%d",selection);
    switch (*selection){
    case 1:
        system("cls");
        playMode_display();
        playMode();
        break;
    case 2:
         system("cls");
        break;
    case 3:
        system("cls");
        break;
    case 4:
        system("cls");
        printf("See you soon!!!");
        Sleep(1000);
        exit(0);
        break;
    default:
        system("cls");
        printf("invalid number ,please try again!!\n");
        mainMenu_display();
        break;
    }

}

void playMode(int * selection){
    scanf("%d",selection) ;
    switch (*selection)
    {
    case 1 :
        game_display();
        getchar();
        break;
    case 2 :
        game_display();
        getchar();
        break;
    case 3 :
        system("cls");
        mainMenu_display(selection);
        break;
    default:
        system("cls");
        printf("invalid number ,please try again!!\n");
        playMode_display(selection);
        break;
    }
}



