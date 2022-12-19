#include <stdio.h>
#include <stdlib.h>
#include "display.h"

void mainMenu(void)
{
    int selection;
    scanf("%d",&selection);
    switch (selection){
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
        exit(0);
        break;
    default:
        system("cls");
        printf("invalid number ,please try again!!\n");
        mainMenu_display();
        break;
    }

}

void playMode(void){
     int selection;
    scanf("%d",&selection);
    switch (selection)
    {
    case 1 :
        printf("Player 1 VS Playr 2\n");
        getchar();
        break;
    case 2 :
        printf(" VS Computer\n");
        getchar();
        break;
    case 3 :
        system("cls");
        mainMenu_display();
        break;
    default:
        system("cls");
        printf("invalid number ,please try again!!\n");
        playMode_display();
        break;
    }
}




