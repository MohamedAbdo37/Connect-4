#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "menu.h"
#include "additional.h"
#include "game.h"

int width = 9, hight = 7 , highScore = 10;
char * cell ;
int * selection ;

void setSelection(int *s){
    selection = s ;
    setSelectionA(s);
}


void color(int value)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,value);
}

void setDimension(int x, int y,int h){
    width = x;
    hight = y;
    highScore = h;
    setRowsAndColumns(x,y);
}

void setEmptyBoard(char * array,int * u, int * r){
    setCellPointer(array, u, r);
    cell = array ;

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

    printf("%c         %c 1-Player VS Player      %c\n",186,16,186);
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
    printf("\n\t\t |");
    for(int i = 0 ; i< width * hight ; i++){
        if(i%width == 0 && i!= 0){
            printf("\n\t\t ");
            for (int i=0;i<=6*width ;i++)
                printf("%c",205);

            printf("\n\t\t |");
        }
        
        if (*(cell+i)==88){
            color(0x04);
            printf("  %c ",*(cell+i));
        }
        else if (*(cell+i)==79){
            color(0x06);
            printf("  %c ",*(cell+i));
        }
        else {
            printf("  %c ",*(cell+i));
        }

        color(0x01);
        printf(" |");
    }
    printf("\n\t\t ");

    for (int i=0 ;i <= 6 * width ;i++)
                printf("%c",205);

    printf("\n\t\t ");
    color(0x07);

    for (int i=0;i<width ;i++){
        if(i+1 < 10)
            printf(" %3d  ",i+1);
        else
            printf("  %3d ",i+1);
    }
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
    
    printf("  ");
    for (int i=0;i<=1*width ;i++)
        printf("%c",205);

    printf("[{U,u}:undo & {R,r}:Redo & {S,s}:quit and save & {Q,q}:quit without save]");

    for (int i=0;i<=1*width ;i++)
        printf("%c",205);

    printf("\n\n");


}


void top_players(selection){
    struct player{
        char name[50];
        int score;
    }

    pla[200];
    struct player temp;
    FILE *fptr;
    int i=0,size,j;
    fptr=fopen("dat\\high score.txt","r");

    if(fptr==NULL){
        printf("\n Cannot open the file \n");
        exit(0);
    }
    while(!feof(fptr)){
            int m = 0;
            char p [50] = "" , c;
            gets(p);
            c = p[m] ;
            while (c != '\0' && !(c > 47 && c < 59)){
                pla[i].name[m]=c;
                p[m]='0';
                m++;
                c = p[m];
            }
            pla[i].score = atoi(p);
            i++;
    }
    size=i;
    for(i=0;i<size;i++)
    for(j=i+1;j<size+1;j++)
        if(pla[i].score <pla[j].score){
            temp=pla[i];
            pla[i]=pla[j];
            pla[j]=temp;
        }

    fclose(fptr);
    for(i=0;i<highScore;i++)
    printf("%s : %d\n",pla[i].name,pla[i].score);

    top_players_display(selection);
}

void top_players_display (int *selection){
    printf("\n");
    printf("%c1-Back\n",16);
    printf("%c2-Quit\n",16);
    top_players_menu(selection);
}


void load_display(int*selection){
    printf("%c1_Saved Game 1\n",16);
    printf("%c2_Saved Game 2\n",16);
    printf("%c3_Saved Game 3\n",16);
    printf ("%c4-Back\n",16);
    printf ("%c5-Quit\n",16);
    load_menu(selection);

}


void xmlPath_display(char * path){

    printf("%c",201);

    for (int i=0;i<35+9;i++)
        printf("%c",205);

    printf("%c\n",187);

    printf("%c         %c 1-Enter Path                     %c\n",186,16,186);
    printf("%c         %c 2-Use default path               %c\n",186,16,186);
    printf("%c         %c 3-Use default configurations     %c\n",186,16,186);
    printf("%c         %c 4-Quit                           %c\n",186,16,186);


    for (int i=0;i<1;i++){
        printf("%c                                            ",186);
        printf("%c\n",186);
    }
    printf("%c",200);

    for (int i=0;i<35+9;i++)
        printf("%c",205);

    printf("%c\n",188);
    printf("%c ",16);
    xmlPath(selection,path);
}

void enterPath(char * path){
    printf("%c 1-Back\n",16);
     printf("%c 2-Quit\n",16);

    printf("Enter Path:\n");
    fgets(path,250,stdin);

}
