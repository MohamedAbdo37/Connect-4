#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "display.h"
#include "game.h"

char * path;

void setPath(char * p){
    path = p ;
}

void checkpath(char * p , int *s){
    FILE *  fx = fopen( p , "r");
    if(fx == NULL){
        fclose(fx);
        printf("File errorm , program can't read it!\n");
        Sleep(1000);
        system("cls");
        xmlPath_display();
    }
    fclose(fx);
}

void mainMenu(int * selection)
{
    scanf("%d",selection);
    switch (*selection){
    case 1:
        system("cls");
        playMode_display();
        break;
    case 2:
        system("cls");
        load_display();
        getchar();
        break;
    case 3:
        system("cls");
        top_players_display();
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
        mainMenu_display();
        break;
    }

}

void playMode(int * selection){
    scanf("%d",selection) ;
    switch (*selection)
    {
    case 1 :
        game();
        getchar();
        break;
    case 2 :
        game_computer();
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

void load_menu (int * selection){
  scanf("%d",selection);
  switch (*selection){
    case 1:
        system ("cls");
        mainMenu_display();
        break;
    case 2:
        system("cls");
        printf("See you soon!!!");
        break;
    default:
        printf("invalid number ,please try again!!\n");
        load_menu();
        break;
    }
  }
  
  void top_players_menu(int * selection){
       scanf("%d",selection);
    switch (*selection){
    case 1:
        system ("cls");
        mainMenu_display();
        break;
    case 2:
        system("cls");
        printf("See you soon!!!");
        break;
    default:
        printf("invalid number ,please try again!!\n");
        top_players_menu();
        break;    
    }
  }

void xmlPath(int * selection ){
    
    switch (*selection){
    case 1:
        fgets(path,261,stdin);
        checkpath(path);
        system("cls");
        break;
    case 2:
        strcpy(path,"data/Configurations.xml");
        checkpath(path);
        system("cls");
        break ;
    case 3 :
        setDimension(7,9);
        // put here function that set the size of highscore list
        system("cls");
        mainMenu_display();
        break;
    case 4:
        Sleep(1000);
        exit(0);
        break;
    default:
        system("cls");
        printf("invalid number ,please try again!!\n");
        xmlPath_display();
        break;
    }

}