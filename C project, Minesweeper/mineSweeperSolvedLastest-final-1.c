#include <stdio.h>
#include <stdlib.h>
#define BOARDSIZE 9
#define TRUE 1
#define FALSE 0
#define boardc 2
#define tempboardc 3
char board[BOARDSIZE][BOARDSIZE];
char dboard[BOARDSIZE][BOARDSIZE];
char tempboard[BOARDSIZE][BOARDSIZE];
void build_rboard();
void build_dboard();
void build_cboard();
void print_board();
void print_dboard();
int count_mine(int, int);
void print_mines(int, int);
int checkforwin();
void start_game();
int count_board(int);

int main()
{
    start_game();
 return 0;
}
void print_board()
{
    int i, j;
    printf("  ");
    for(i = 0; i < BOARDSIZE ; i++)
        printf("%d ", i);
    printf("\n");
    for(i = 0; i < BOARDSIZE; i++)
    {
         printf("%d ", i);
        for(j = 0; j < BOARDSIZE; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int count_board(int type){
    int i,j,cnt=0;
    if(type==tempboardc){
        for(i=0;i<BOARDSIZE;i++){
            for(j=0;j<BOARDSIZE;j++){
                if(tempboard[i][j]=='*'){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    else if(type==boardc){
        for(i=0;i<BOARDSIZE;i++){
            for(j=0;j<BOARDSIZE;j++){
                if(board[i][j]=='*'){
                    cnt++;
                }
            }
        }
        return cnt;
    }

}

void print_dboard()
{
    int i, j;
    printf("  ");
    for(i = 0; i < BOARDSIZE; i++)
        printf("%d ", i);
    printf("\n");

    for(i = 0; i < BOARDSIZE; i++)
    {
        printf("%d ", i);
        for(j = 0; j < BOARDSIZE; j++)
        {
            printf("%c ", dboard[i][j]);
        }

        printf("\n");
    }
}
void build_rboard()
{
    int i, j;
    for(i = 0; i < BOARDSIZE; i++){
        for(j = 0; j < BOARDSIZE; j++){
            board[i][j] = '.';
        }
    }
   for(j = 0; j < BOARDSIZE; j++)
    {
        int random = rand() % BOARDSIZE;

        board[random][j] = '*';
    }
}
void build_cboard()
{
    int i, j;
    for(i = 0; i < BOARDSIZE; i++){
        for(j = 0; j < BOARDSIZE; j++){
            board[i][j] = '.';
            tempboard[i][j] = '.';
        }
    }
    board[0][5]='*';
    board[2][7]='*';
    board[3][6]='*';
    board[3][8]='*';
    board[4][0]='*';
    board[4][7]='*';
    board[5][4]='*';
    board[6][8]='*';
    board[7][8]='*';
    board[8][2]='*';

}
void build_dboard()
{
    int i, j;
    for(i = 0; i < BOARDSIZE; i++)
        for(j = 0; j < BOARDSIZE; j++)
            dboard[i][j] = '.';
}
int count_mine(int row, int col)
{
    int mines = 0;
    if(row!=0){
        if(board[row - 1][col] == '*'){
            mines++;
        }
        if(col!=BOARDSIZE-1){
            if(board[row - 1][col + 1] == '*'){
                mines++;
            }
        }
        if(col!=0){
            if(board[row - 1][col - 1] == '*'){
                mines++;
            }
        }
    }


    if(row!=BOARDSIZE-1){
        if(board[row + 1][col] == '*'){
            mines++;
        }
        if(col!=BOARDSIZE-1){
            if(board[row + 1][col + 1] == '*'){
                mines++;
            }
        }
        if(col!=0){
            if(board[row + 1][col - 1] == '*'){
                mines++;
            }
        }
    }
    if(col!=0){
        if(board[row][col - 1] == '*'){
            mines++;
        }
    }
    if(col!=BOARDSIZE-1){
        if(board[row][col + 1] == '*'){
            mines++;
        }
    }


    return mines;
}
void print_mines(int row, int col)
{
    int nearbymines = 0, i;
        nearbymines = count_mine(row, col);
        dboard[row][col] = nearbymines+48;
        for(nearbymines = 0, i=0;nearbymines == 0 && i <= row;i++)
        {
            nearbymines = count_mine(row - i, col);
            dboard[row - i][col] = nearbymines+48;
        }
        for(nearbymines = 0, i=0;nearbymines == 0 && row + i < BOARDSIZE;i++)
        {
            nearbymines = count_mine(row + i, col);
            dboard[row + i][col] = nearbymines+48;
        }
        for(nearbymines = 0, i=0;nearbymines == 0 && i <= col;i++)
        {
            nearbymines = count_mine(row, col - i);
            dboard[row][col - i] = nearbymines+48;
        }
        for(nearbymines = 0, i=0;nearbymines == 0 && col + i < BOARDSIZE;i++)
        {
            nearbymines = count_mine(row, col + i);
            dboard[row][col + i] = nearbymines+48;
        }
        for(nearbymines = 0, i=0;nearbymines == 0 && col + i < BOARDSIZE && i <= row;i++)
        {
            nearbymines = count_mine(row - i, col + i);
            dboard[row - i][col + i] = nearbymines+48;
        }
        for(nearbymines = 0, i=0;nearbymines == 0 && i <= row && i<=col;i++)
        {
            nearbymines = count_mine(row - i, col - i);
            dboard[row - i][col - i] = nearbymines+48;
        }
        for(nearbymines = 0, i=0;nearbymines == 0 && row + i < BOARDSIZE && col + i < BOARDSIZE;i++)
        {
            nearbymines = count_mine(row + i, col + i);
            dboard[row + i][col + i] = nearbymines+48;
        }
        for(nearbymines = 0, i=0;nearbymines == 0 && row + i < BOARDSIZE && i <= col;i++)
        {
            nearbymines = count_mine(row + i, col - i);
            dboard[row + i][col - i] = nearbymines+48;
        }
}
int checkforwin()
{
    int i, j;
    for(i = 0; i < BOARDSIZE; i++)
        for(j = 0; j < BOARDSIZE; j++) {
            if(dboard[i][j] == '.'){
                return FALSE;
            }
        }
    return TRUE;
}

void start_game()
{
    int row, col;
    int countboard,choice;
    char yesno;
    printf("Choose Game Type:\n(1)Random Generated\n(2)Menually Set Mine\n");
    C:
    scanf("%d",&choice);
    switch(choice)
{
case 1:
build_rboard();
countboard=count_board(boardc);
break;
case 2:
build_cboard();
countboard=count_board(boardc);
break;
default:
printf(" Invalid...Choose Again\n ");
goto C;
}

   // build_cboard();
   // build_rboard();
    build_dboard();
    print_dboard();
    //print_board();
    for(;;)
    {
        //print_board();
        printf("\n\nEnter X (0 to 8): ");
        scanf("%d", &col);
        printf("Enter Y (0 to 8): ");
        scanf("%d", &row);
        printf("Do you think there is a mine here? (Y or N): ");
        scanf(" %c",&yesno);
        if(row>=BOARDSIZE||col>=BOARDSIZE){
            printf("Invalid Input!\n");
            continue;
        }
        if(yesno=='N' || yesno =='n'){
            if(board[row][col] == '*')
            {
                printf("Oops!!..You hit a MINE!\n");
                print_board();
                printf("Game Over !!");
                exit(0);
            }
            else{
                print_mines(row, col);
                printf("\n\nMineField\n*********\n\n");
                print_dboard();

            }
        }
        else if(yesno=='Y' || yesno == 'y'){
            if(board[row][col] == '.')
            {
                printf("Oops!!..There was no MINE!\n");
                print_board();
                printf("Game Over !!");
                exit(0);
            }
            else{
                print_mines(row, col);
                tempboard[row][col]='*';
                //printf("\ntemp board count: %d\nboard count %d\n",count_board(tempboardc),countboard);
                if(countboard == count_board(tempboardc)){
                    printf("Congratz..You Win !!");
                    exit(0);
                }
                dboard[row][col]='*';
                printf("\n\nMineField\n*********\n\n");
                print_dboard();
            }
        }
        else{
            printf("Invalid Yes/No Input!\n");
        }
        if(checkforwin() == TRUE){
            printf("Congratz..You Win !!");
            exit(0);
        }
    }
}
