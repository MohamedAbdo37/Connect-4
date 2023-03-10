#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "additional.h"

char * cell;
int hight , width ,move_1=0 ,move_2=0 ;
int p1_score , p2_score ;
int * stack_undo;
int * stack_redo;
int top_undo = -1;
int top_redo = 63;
char isComp = 0;


void setRowsAndColumns(int x , int y){
    hight = y;
    width = x;
}

void setCellPointer(char * i,int * u, int *r){
    stack_redo = r;
    stack_undo = u;
    cell = i ;
    top_redo = (width*hight);

}

int checkcol (int col){

    if(*(cell+col-1) != 32){
        system("cls");
        printf("The column is full !!");
        game_display(p1_score,p2_score,move_1,move_2);
        return -5 ;
    }
    else{

        int place = col-1;

        while (place < (hight*width))
        {
                if (*(cell+place)!=32)
                    break;
                place += width;
        }

        return place - width;
    }


}

void addX(int p){
    *(cell+p) = 88;
}

void addO(int p){
    *(cell+p) = 79;
}

int checkPosition(int x , int y){
    if(x>-1 && x < width)
        if(y>-1 && y < hight)
            return 1;
    return 0 ;
}

int verticalCheck(int i){
    int s = 0;
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

    int s = 0 ,n = 1 ;
    int x = i%width ,y = i/width;

   for(int j = 2; checkPosition(x-1,y+1) && *(cell +i) == *(cell + x-1 +(y+1)*width);j++){
        n++;
        x--;
        y++;
        if(j == 4){
            break;
        }
    }

    x = i % width ;
    y = i / width ;

    for(int j = 2; checkPosition(x+1,y-1) && *(cell +i) == *(cell + x+1 +(y-1)*width);j++){
        n++;
        x++;
        y--;
        if(j == 4){
            break;
        }
    }

    if(n/4)
        s += (n-3);

    return s;
}


int leftDiognalCheck(int i){
    int s = 0 ,n = 1 ;
    int x = i%width ,y = i/width;

   for(int j = 2; checkPosition(x+1,y+1) && *(cell +i) == *(cell + x+1 +(y+1)*width);j++){
        n++;
        x++;
        y++;
        if(j == 4){
            break;
        }
    }

    x = i % width ;
    y = i / width ;

    for(int j = 2; checkPosition(x-1,y-1) && *(cell +i) == *(cell + x-1 +(y-1)*width);j++){
        n++;
        x--;
        y--;
        if(j == 4){
            break;
        }
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


void push_undo (int place)
{
    top_undo++;
    stack_undo[top_undo]=place;
}
void undo (void)
{
    if (top_undo!=-1){
        *(cell+stack_undo[top_undo])=32;
        push_redo(stack_undo[top_undo]);
        top_undo--;
    }

    if (isComp){
        isComp = 0;
        undo();
    }

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

     if (isComp){
        isComp = 0;
        redo(79);
    }

}

void player_1(int * col ){

    int i = -5 ;
    char in[5]= "";
pl1:
    color(0x04);
    printf("Player 1 choose a column\n%c",16);
    *col = scan(&in[0]);
    if (*col==0 ){
         if (top_undo == -1)
         {
             system("cls");
             printf("No thing to undo!!");
            game_display(p1_score,p2_score,move_1,move_2);
            player_1(col);
         }
         else{

            p2_score -=Score(stack_undo[top_undo]);

                if(isComp){
                    undo();
                    isComp = 1 ;
                    move_1--;
                    move_2--;

                }else{
                    undo();
                    move_2--;
                }
                if(!move_1)
                        move_2 = 0 ;
                system("cls");
                game_display(p1_score,p2_score,move_1,move_2);
                if(isComp)
                    player_1(col);
                else
                    player_2(col);
        }
    }
    else if (*col==-1)
    {
        if (top_redo != (hight * width))
        {
            if(isComp){
                redo(88);
                move_1++;
                move_2++;
                isComp = 1 ;
            }else{
                redo(88);
                move_1++;
            }

            p1_score +=Score(stack_redo[top_redo-1]);

            system("cls");
            game_display(p1_score,p2_score,move_1,move_2);

            if(isComp)
                player_1(col);
            else
                player_2(col);
         }
         else{
            system("cls");
            printf("No thing to Redo");
            game_display(p1_score,p2_score,move_1,move_2);

            player_1(col);
        }
         }
     else if (*col==-2){
            printf("\n1-save game 1\n2-save game 2\n3-save game 3\n");
            int choose;
            save_game(choose);
            printf("Game Saved .... ");
            Sleep(100);
            system("cls");
            mainMenu_display(col);
     }
      else if (*col==-3){
       system("cls");
       mainMenu_display(col);
     }
        else{
            if (*col > 0 && *col <= width){
            i = checkcol(*col);
            if(i == -5)
                goto pl1;
            push_undo(i);
            top_redo=width * hight;
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
    }}


void player_2(int * col){

    char  in[5] = "";

pl2:
    color(0x06);
    printf("Player 2 choose a column\n%c",16);
    *col = scan(&in[0]);
    if (*col==0  ){
         if (top_undo ==  -1 )
         {
            system("cls");
            move_1++;
            printf("No thing to undo!!");
            game_display(p1_score,p2_score,move_1,move_2);
            player_2(col);
         }
         else{

            p1_score -=Score(stack_undo[top_undo]);
            undo();
            move_1--;
            system("cls");
            game_display(p1_score,p2_score,move_1,move_2);
            player_1(col);
         }
    }
     else if (*col==-1)
    {
         if (top_redo!=(hight * width))
         {

            redo(79);
            move_2++;
            p2_score +=Score(stack_redo[top_redo-1]);

             system("cls");
            game_display(p1_score,p2_score,move_1,move_2);
            player_1(col);}
         else
         {
            system("cls");
            printf("No thing to Redo");
            game_display(p1_score,p2_score,move_1,move_2);
            player_2(col);}

    }
      else if (*col==-2){
             printf("\n1-save game 1\n2-save game 2\n3-save game 3\n");
             int choose;
            save_game(choose);
            printf("Game Saved .... ");
            Sleep(100);
            system("cls");
            mainMenu_display(col);
     }
     else if (*col==-3){
       system("cls");
       mainMenu_display(col);
     }
    else{
        int i = -5 ;
        if (*col > 0 && *col <= width){
        i = checkcol(*col);
        if(i == -5){
            goto pl2;
        }
         push_undo(i);
         top_redo=width * hight;
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
    while( (move_1 + move_2) < (hight*width)){

        game_display(p1_score,p2_score,move_1,move_2);

        if((move_1 + move_2)%2 == 0){
            player_1(selection);
        }
        else{
            player_2(selection);
        }
    }

    if ((move_1 + move_2) ==(hight*width))
    {
        if (p1_score > p2_score)
        {
            game_display(p1_score,p2_score,move_1,move_2);
            color(0x07);
            printf("Player 1 please enter your name...\n");
            char name[50];
            fflush(stdin);
            gets(name);
            color(0x04);
            printf("%s is the winner %c",name,2);
            check_existence(name,p1_score);
            sort_file();
        }
        else if (p1_score < p2_score)
        {
            game_display(p1_score,p2_score,move_1,move_2);
            color(0x07);
            printf("Player 2 please enter your name...\n");
            char name[50];
            fflush(stdin);
            gets(name);
            color(0x06);
            printf("%s is the winner %c",name,2);
            check_existence(name,p2_score);
            sort_file();

        }
        else
        {
            game_display(p1_score,p2_score,move_1,move_2);
            color(0x08);
            printf("The Game is DRAW!!!!");
            sleep(1000);
        }
    }
}


void game_computer (int * selection){

    system("cls");

    while( (move_1 + move_2) < (hight*width)){

        game_display(p1_score,p2_score,move_1,move_2);

        if((move_1 + move_2)%2 == 0){
            player_1(selection);
        }
        else{
            computer(selection);
        }
    }
     if ((move_1 + move_2) ==(hight*width))
    {
        if (p1_score > p2_score)
        {
            game_display(p1_score,p2_score,move_1,move_2);
            color(0x07);
            printf("Player 1 please enter your name...\n");
            char name[50];
            fflush(stdin);
            gets(name);
            color(0x04);
            printf("%s is the winner %c",name,2);
            check_existence(name,p1_score);
            sort_file();
        }
           else if (p1_score < p2_score)
        {
            game_display(p1_score,p2_score,move_1,move_2);
            color(0x07);
            printf("GAME OVER...!!\n");
            getchar();

        }
        else
        {
            game_display(p1_score,p2_score,move_1,move_2);
            color(0x08);
            printf("The Game is DRAW!!!!");
            getchar();
        }
    }


}

void computer (int * col)
{
    isComp = 1;
    int i = -5;
    *col = 0;
    srand(time(NULL));
    while(i == -5){
        while (*col==0){
            *col = (rand() % (width)) + 1;
        }
        i = checkcol(*col);
    }
    push_undo(i);
    system("cls");
    addO(i);
    p2_score += Score(i);
    move_2++;

}




void save_game(int choose)
{
    FILE * fptr;
    scanf("%d",&choose);
    switch (choose)
    {
        case 1:
            fptr = fopen("C:\\Users\\Ali Hassan\\Desktop\\Connect-4\\save_1.bin","wb");
            break;
        case 2:
            fptr = fopen("C:\\Users\\Ali Hassan\\Desktop\\Connect-4\\save_2.bin","wb");
            break;
        case 3:
            fptr = fopen("C:\\Users\\Ali Hassan\\Desktop\\Connect-4\\save_3.bin","wb");
            break;
    }
    fwrite(&isComp,sizeof(char),1,fptr);
    fwrite(&move_1,sizeof(int),1,fptr);
    fwrite(&move_2,sizeof(int),1,fptr);
    fwrite(&p1_score,sizeof(int),1,fptr);
    fwrite(&p2_score,sizeof(int),1,fptr);
    fwrite(&top_undo,sizeof(int),1,fptr);
    fwrite(stack_undo,sizeof(int),top_undo+1,fptr);
    fclose(fptr);
}

void load_game(int * selection)
{
    FILE * fptr;
    switch (*selection)
    {
        case 1:
            fptr = fopen("C:\\Users\\Ali Hassan\\Desktop\\Connect-4\\save_1.bin","rb");
            if(fptr==NULL){
	       	printf("\n Cannot open the file \n");
		    exit(0);}
            break;
        case 2:
            fptr = fopen("C:\\Users\\Ali Hassan\\Desktop\\Connect-4\\save_2.bin","rb");
            if(fptr==NULL){
            printf("\n Cannot open the file \n");
		    exit(0);}
            break;
        case 3:
            fptr = fopen("C:\\Users\\Ali Hassan\\Desktop\\Connect-4\\save_3.bin","rb");
            if(fptr==NULL){
		    printf("\n Cannot open the file \n");
		    exit(0);}
            break;
    }

	while (!feof(fptr))
    {
    fread(&isComp,sizeof(char),1,fptr);
    fread(&move_1,sizeof(int),1,fptr);
    fread(&move_2,sizeof(int),1,fptr);
    fread(&p1_score,sizeof(int),1,fptr);
    fread(&p2_score,sizeof(int),1,fptr);
    fread(&top_undo,sizeof(int),1,fptr);
    fread(stack_undo,sizeof(int),top_undo+1,fptr);
    }
    for (int j=0;j<=top_undo;j++)
    {
        if (j%2==0)
            *(cell+stack_undo[j])=88;
        else
            *(cell+stack_undo[j])=79;

    }
    fclose(fptr);
    top_undo = -1;
}


void load_menu (int * selection){
  scanf("%d",selection);
  switch (*selection){
    case 1:
        system ("cls");
        load_game(selection);
        if (isComp==0)
        game(selection);
        else
        game_computer(selection);
        break;
    case 2:
        system ("cls");
        load_game(selection);
        if (isComp==0)
        game(selection);
        else
        game_computer(selection);
        break;
    case 3:
        system ("cls");
        load_game(selection);
        if (isComp==0)
        game(selection);
        else
        game_computer(selection);
        break;
    case 4:
        system("cls");
        mainMenu_display(selection);
        break;
    case 5:
        system("cls");
        printf("See you soon...");
        Sleep(1000);
        exit(0);
        break;
    default:
        printf("invalid number please try again...\n");
        load_display(selection);
    }
  }



