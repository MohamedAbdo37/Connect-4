#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
		while(fgetc(fptr)!=EOF)
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
		fprintf(fptr,"\n");
		for (i=0;i<size;i++){
		fprintf(fptr,"%s %d",pla[i].name,pla[i].score);
		fprintf(fptr,"\n");
		}
		fclose(fptr);
}





