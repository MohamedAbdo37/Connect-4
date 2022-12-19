#include <stdio.h>
void mode(void)
{
    int selection;
    scanf("%d",&selection);
    switch (selection){
    case 1:
        system("cls");
        printf("%c 1-VS Human\n",16);
        printf("%c 2-VS Computer\n",16);
        break;
    case 2:
         system("cls");
        break;
    case 3:
        system("cls");
        break;
    case 4:
        system("cls");
        printf("See you soon!!!");
        break;
    default:
        system("cls");
        printf("invalid number ,please try again!!\n");
        mainmenu();
        break;
    }

}
