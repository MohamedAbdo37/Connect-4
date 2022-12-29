#include <stdio.h>
#include <time.h>
#include <string.h>

#include "lib/menu.h"
#include "lib/display.h"
#include "lib/additional.h"

void readXml(int * width , int * hight , int * highScore);

void main(void){

    clock_t time = clock();
    
    int width = 9 , hight = 7 , highScore =10;
    char path[262] ;
    int selectoin;
    char board[hight][width];
    setPath(path);

    readXml(&width,&hight,&highScore);

    
    setIntialTime(time/CLOCKS_PER_SEC);
    setDimension(width,hight,highScore);
    setSelection(&selectoin);
    setEmptyBoard(&board[0][0]);

    mainMenu_display(&selectoin);

}

void readXml(int * width , int * hight , int * highScore){
    FILE * fx = fopen("H.xml","r");
    char s1[500] = "";
    char s2[100] = "";
    char num[5] = {0} ;
    
    while (!feof(fx)){
        fgets(s2,99,fx);
        strcat(s1,s2);
    }
    fclose(fx);

    char * ptr = strstr(s1,"Height");

    int i = 0 ;
    int j = 0;
    
    while (*(ptr+i) != '<'){
        if(j==3)
            break;

        if(*(ptr+i) > 47 && *(ptr+i)<59)
            num[j++] = *(ptr+i) ;
        i++;
    }
    num[j] ='\0';
    *hight = atoi(num);

    ptr = strstr(s1,"Width");
    i = 0;
    j = 0;
    while (*(ptr+i) != '<'){
        if(j==3)
            break;

        if(*(ptr+i) > 47 && *(ptr+i)<59)
            num[j++] = *(ptr+i) ;
        i++;
    }
    num[j] ='\0';
    *width = atoi(num);

    ptr = strstr(s1,"Highscores");
    i = 0;
    j = 0;
    while (*(ptr+i) != '<'){
        if(j==3)
            break;

        if(*(ptr+i) > 47 && *(ptr+i)<59)
            num[j++] = *(ptr+i) ;
        i++;
    }
    num[j] ='\0';
    *highScore = atoi(num);

}