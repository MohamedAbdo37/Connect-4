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
        playMode_display(selection);
        break;
    case 2:
        system("cls");
        load_display(selection);
        getchar();
        break;
    case 3:
        system("cls");
        top_players_display(selection);
        getchar();
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
        mainMenu_display(selection);
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

void load_menu (int * selection){
  scanf("%d",selection);
  switch (*selection){
    case 1:
        system ("cls");
        mainMenu_display(selection);
        break;
    case 2:
        system("cls");
        printf("See you soon!!!");
        break;
    default:
        printf("invalid number ,please try again!!\n");
        load_menu(selection);
        break;
    }
  }
  
  void top_players_menu(int * selection){
       scanf("%d",selection);
    switch (*selection){
    case 1:
        system ("cls");
        mainMenu_display(selection);
        break;
    case 2:
        system("cls");
        printf("See you soon!!!");
        break;
    default:
        printf("invalid number ,please try again!!\n");
        top_players_menu(selection);
        break;    
    }
  }

