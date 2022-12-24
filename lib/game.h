
void setRowsAndColumns(int width , int hight);

void setCellPointer(char * i);

int checkcol (int column_number);

void addX (int i);

void addO (int i);

void player_1(int * selection);

void player_2(int * selection);

void game(int * selection);

void verticalCheck(int i, int * score);

void horizontalCheck(int i, int * score);

void rightDiognalCheck(int i, int * score);

void leftDiognalCheck(int i, int * score);

void Score(int i , int * score);
void undo (int);