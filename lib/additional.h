
void setSelectionA(int * s);

void timePassed();

void setIntialTime(int time);

void timeFormat(int time);

void sort_file (void);

void readXml(char * path);

void check_existence(char name[50],int);


int scan(char * input);
/*
    will return 0 for undo
    , -1 for redo
    , -2 for save
    , -3 for quit
    , the number that user has inputed
    and -4 if nothing above happend
*/


