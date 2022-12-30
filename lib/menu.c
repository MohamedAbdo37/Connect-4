#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "display.h"
#include "game.h"

int x,y,z;

void setArgsXml(int width,int higth,int highScore){
    x = width;
    y = higth;
    z = highScore;
}

void setArgs(int * width,int * higth,int *highScore){
    *width = x;
    *higth = y;
    *highScore = z;
}

void checkpath(char *path){
    
    if(!strcmp(path,"1")){
        system("cls");
        xmlPath_display(path);
    }
    if(!strcmp(path,"2"))
        exit(0);

    FILE *  fx = fopen(path, "r");

    if(fx == NULL){
        printf("File error , program can't read it!\n");
        Sleep(3000);
        fclose(fx);
        system("cls");
        xmlPath_display(path);
    }
    else    printf("T");
    fclose(fx);
}

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
        break;
    case 3:
        system("cls");
        top_players(selection);
        top_players_display(selection);
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
        game(selection);
        getchar();
        break;
    case 2 :
        game_computer(selection);
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
        load_display(selection);
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
        Sleep(10000);
        break;
    default:
        printf("invalid number ,please try again!!\n");
        top_players_display(selection);
        break;
    }
  }

void xmlPath(int * selection ,char *path){
    scanf("%d",selection);
    switch (*selection){
    case 1:
        system("cls");
        enterPath(path);
        gets(path);
        checkpath(path);
        readXml(path);
        system("cls");

        return;
        break;
    case 2:
        strcpy(path,"data\\Configurations.xml");
        checkpath(path);
        readXml(path);
        system("cls");
        return;
        break ;
    case 3 :
        x = 9;
        y = 7;
        z = 10;
        system("cls");
        break;
    case 4:
        exit(0);
        break;
    default:
        system("cls");
        printf("invalid number ,please try again!!\n");
        xmlPath_display(path);
        break;
    }

}
