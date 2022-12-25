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

void addX(int p){
    *(cell+p) = 88;
}

void addO(int p){
    *(cell+p) = 79;
}


int verticalCheck(int i){

    int s;
    for (int j = 2; i < (hight * width) && (*(cell + i) == *(cell + i + width));j++){
        i+= width ;
        if(j == 4){
            s++;
            break;
        }
    }
    return s;
}

int horizontalCheck(int i){
    int p = i , n = 0 ,s = 0;

    for(int j = 1 ; i - 1 >= (p/width)*width && *(cell + i-1) == *(cell + i);j++){
        i-- ;
        n++ ;
        if(j == 3){
            break;
        }

    }

    i = p ;
    n++;

    for(int j = 1 ; i+1<(1+p/width)*width  && *(cell + i+1) == *(cell + i);j++){
        i++ ;
        n++ ;
        if(j == 3){
            break;
        }
    }

    if(n/4)
        s += (n-3);

    return s;
}

int rightDiognalCheck(int i){

    int p = i ,n = 0 , s = 0;

    for(int j = 1 ; i >= (i/width)*width && *(cell + i - (width+1)) == *(cell + i);j++){
        i-= (width + 1) ;
        n++;
        if(j == 3){
            break;
        }
    }

    i = p ;
    n++ ;
    for(int j = 1 ; i<(1+i/width)*width  && *(cell + i+(width + 1)) == *(cell + i);j++){
        i+= (width + 1) ;
        n++ ;
        if(j == 3){ 
            break;
        }
    }

    if(n/4)
        s += (n-3);
    
    return s ;
}


int leftDiognalCheck(int i){

    int p = i ,n = 0 ,s = 0;

    for(int j = 1; i >= (i/width)*width && *(cell + i + (width - 1)) == *(cell + i);j++){
        i+= (width - 1) ;
        if(j == 3){
            break;
        }
        n++ ;
    }

    i = p ;
    n++ ;

    for(int j = 1 ; i <(1+i/width)*width  && *(cell + i- (width - 1)) == *(cell + i);j++){
        i-= (width - 1) ;
        if(j == 3){ 
            break;
        }
        n++ ;
    }

    if(n/4)
        s += (n-3);
    
    return s;
}


int Score(int i){
    int s = 0 ;
    s += verticalCheck(i);
    s += horizontalCheck(i);
    s += rightDiognalCheck(i);
    s += leftDiognalCheck(i);
    return s ;
}

void player_1(int * col){
   int p;
    printf("Player 1 choose a column");
    scanf("%d",col);
    if (*col==0){
         undo(p);
         move_2--;
        system("cls");
        game_display(p1_score,p2_score,move_1,move_2);
         player_2(col);
    }
        else{
            if (*col > 0 && *col <= width){
            int i = checkcol(*col);
            system("cls");
            addX(i);
            p1_score += Score(i);
            move_1++;
        }
        else{
            system("cls");
            game_display(p1_score,p2_score,move_1,move_2);
            printf("\n\"Invalid number ,Please try again!\"\n");
            player_1(col);
        }
    }
}

void player_2(int * col){
    int p;
    printf("Player 2 choose a column");
    scanf("%d",col);
    if (*col==0){
         undo(p);
         move_1--;
         system("cls");
         game_display(p1_score,p2_score,move_1,move_2);
         player_1(col);
    }
    else{
        if (*col > 0 && *col <= width){
        int i = checkcol(*col);
        system("cls");
        addO(i);
        p2_score += Score(i);
        move_2++;
    }
    else{
        system("cls");
        game_display(p1_score,p2_score,move_1,move_2);
        printf("\n\"Invalid number ,Please try again!\"\n");
        player_2(col);
    }
    }
}

void game(int * selection){

    system("cls");

    move_1 = 0 ;
    move_2 = 0 ;

    while( (move_1 + move_2) < (hight*width)){

        game_display(p1_score,p2_score,move_1,move_2);

        if((move_1 + move_2)%2 == 0){
            player_1(selection);
        }
        else{
            player_2(selection);
        }
    }
}
void undo (int p)
{
    *(cell+p)=32;
}
