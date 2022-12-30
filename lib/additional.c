#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "game.h"
#include "menu.h"
#include "display.h"

int intial ;

void setIntialTime(int time){
    intial = time ;
}

void timePassed(){
    clock_t time = clock() ;
    int sec = (time/CLOCKS_PER_SEC) - intial ;
    timeFormat(sec);
}

void timeFormat(int sec){
    printf("%d : %d",sec/60,sec%60);
}

void sort_file (void){
	struct player{
		char name[50];
		int score;
	}

	pla[200];
	struct player temp;
	FILE *fptr;
	int i=0,size,j;
	fptr=fopen("high score.txt","r");

	if(fptr==NULL){
		printf("\n Cannot open the file \n");
		exit(0);
	}
		while(!feof(fptr))
		{
		fscanf(fptr,"%s%d",pla[i].name,&pla[i].score);
		i++;
		}
		size=i;
		for(i=0;i<size;i++)
		for(j=i+1;j<size+1;j++)
		if(pla[i].score <pla[j].score)
		{
		temp=pla[i];
		pla[i]=pla[j];
		pla[j]=temp;
		}
		fclose(fptr);
		fptr = fopen("high score.txt","w");
		for (i=0;i<size-1;i++){
		fprintf(fptr,"%s %d",pla[i].name,pla[i].score);
		if (i!=size-2)
            fprintf(fptr,"\n");
		}
		fclose(fptr);
}

void readXml(char * path){
    FILE * fx = fopen(path,"r");
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
    int hight = atoi(num);

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
    int width = atoi(num);

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
    int highScore = atoi(num);

	setDimension(width,hight,highScore);
	setArgsXml(width,hight,highScore);

}
void check_existence(char name[50],int score)
{
    struct player{
		char name[50];
		int score;
	}
	pla[200];
	FILE *fptr;
	int i=0,size,truth=0;
	fptr=fopen("high score.txt","r");
	if(fptr==NULL){
		printf("\n Cannot open the file \n");
		exit(0);
	}
		while(!feof(fptr))
		{
		fscanf(fptr,"%s%d",pla[i].name,&pla[i].score);
		i++;
		}
		size=i;
        for(i=0;i<size;i++)
        {
            if (strcmp(pla[i].name,name)==0)
            {
                truth=1;
                if (score > pla[i].score){
                pla[i].score=score;
                break;}
            }
        }
        fclose(fptr);
        if (truth==1){
        fptr = fopen("high score.txt","w");
		for (i=0;i<size+1;i++){
		fprintf(fptr,"%s %d",pla[i].name,pla[i].score);
		if (i!=size)
            fprintf(fptr,"\n");
		}
            fclose(fptr);
		}
        else
        {
            fptr=fopen("high score.txt","a");
            fprintf(fptr,"%s %d\n",name,score);
            fclose(fptr);
        }

}

int scan(char * p){

    scanf("%s",p);
    if(p[0]=='u' || p[0]== 'U'){
        return 0;
    }

    if(p[0]=='r' || p[0]== 'R'){
        return -1;
    }

    if(p[0]=='S' || p[0]== 's'){
        return -2;
    }

    if(p[0]=='q' || p[0]== 'Q'){
        return -3 ;
    }

    if(p[0]>47 && p[0]<59){
        return atoi(p) ;
    }
    else{
        return -4 ;
    }

}







