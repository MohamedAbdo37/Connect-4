
void setRowsAndColumns(int width , int hight);

void setCellPointer(char * i,int * u, int *r);

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
void computer (int * col);
void game_computer (int * selection);
void push_undo (int);
void undo (void);
void push_redo (int );
void redo (char);

