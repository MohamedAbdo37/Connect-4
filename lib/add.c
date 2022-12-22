#include <stdio.h>
int checkcol (int col)
{
   int place=col-1;
   while (place < (hight*width))
   {
       if (*(cell+i)!=32)break;
       else place+=width;
   }
   return place-1;
}
void addx(int col)
{
    int p=checkcol(col);
    *(cell+p)=88;
}
void addo(int col)
{
    int p=checkcol(col)
    *(cell+p)=79;
}
void player_1(int * col)
{
    printf("Player 1 choose a column");
    scanf("%d",col);
    if (*(col)>0 && *(col)<width){
        system("cls");
        addx(*col);
        board_display();}
    else{
        printf("Invalid number ,Please try again");
        void player_1(*col);
    }
}

void player_2(int * col)
{
    printf("Player 1 choose a column");
    scanf("%d",col);
    if (*(col)>0 && *(col)<=width){
        system("cls");
        addx(*col);
        board_display();}
    else{
        printf("Invalid number ,Please try again");
        void player_1(*col);
    }
}
