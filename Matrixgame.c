#include <stdio.h>
#include <conio.h>

int arr[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

void rule()
{
    textcolor(RED);
    printf("                          RULE OF THIS GAME                         \n\n");

    printf("1.You can move only 1 step at a time by arrow key.\n");
    printf("->Move Up    : by Up arrow key\n");
    printf("->Move Down  : by Down arrow key\n");
    printf("->Move Left  : by Left arrow key\n");
    printf("->Move Right : by Right arrow key\n");
    printf("2.You can move number at empty position only.\n");
    printf("3.For each valid move : your total number of move will be decreasedn by 1.\n");
    printf("4.Winning condion :Number in a 4*4 matrix should be in order from 1 to 15.\n\n");
    printf("               Winning situation:\n");
    printf("            -------------------------\n");
    printf("            |  1  |  2  |  3  |  4  |\n");
    printf("            |  5  |  6  |  7  |  8  |\n");
    printf("            |  9  |  10 |  11 |  12 |\n");
    printf("            |  13 |  14 |  15 |     |\n");
    printf("            -------------------------\n");
    sleep(1);
    printf("5.You can exit the game at any time by pressing 'E'or'e'.\n");
    printf("So,Try to win in minimum number of move...\n\n");
    printf("Click enter to start....\n");
    getch();
    printf("                                            LOADING.");
    printf(".");
     sleep(2);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".\n\n\n");
}
// matrix representation
void printmatri(int arr[4][4])
{
    printf("\n\t\t\t\t\t-------------------------\n");
    printf("\t\t\t\t\t");
    for (int o = 0; o < 4; o++)
    {
        for (int p = 0; p < 4; p++)
        {
            if (arr[o][p] >= 10)
                printf("| %d  ", arr[o][p]);
            else
                printf("|  %d  ", arr[o][p]);
        }
        printf("|\n");
        printf("\t\t\t\t\t");
    }
    printf("-------------------------\n");
}
// game movement
void up(int (*ar)[4], int i, int j)
{
    int tem = ar[i][j];
    ar[i][j] = ar[i - 1][j];
    // printf("\n%d ",tem);
    ar[i - 1][j] = tem;
}
void down(int (*ar)[4], int i, int j)
{
    int tem = ar[i][j];
    ar[i][j] = ar[i + 1][j];
    ar[i + 1][j] = tem;
}
void left(int (*ar)[4], int i, int j)
{
    int tem = ar[i][j];
    ar[i][j] = ar[i][j - 1];
    ar[i][j - 1] = tem;
}
void right(int ar[4][4], int i, int j)
{
    int tem = ar[i][j];
    ar[i][j] = ar[i][j + 1];
    ar[i][j + 1] = tem;
}
//game main function
void matrixgame(int (*ar)[4], int c, char *ch)
{
    int i = 3, j = 3,cout = 0, k;
    char cha;
    for (k = 0; k < c; k++)
    {
    
        printf("Player name: %s  Moves Left: %d\n", ch, c - k);
        printmatri(ar);

        cha=getch();
        switch (cha)
        {
        case 72:
            up(ar, i, j);
            i = i - 1;
            break;
        case 80:
            down(ar, i, j);
            i = i + 1;
            break;
        case 75:
            left(ar, i, j);
            j = j - 1;
            break;
        case 77:
            right(ar, i, j);
            j = j + 1;
            break;
        default:
            printf("\nEntered wrong key!!\n");
        }

        for (int p = 0, o = 0; o < 4; o++, p++)
        {

            if (arr[o][p] == ar[o][p])
            {
                cout += 1;
            }
        }
        if (cout == 16)
        {
            printf("Congratulation you win!!!\n");
            return;
        }
        if (k + 1 == c)
        {
            printf("\nGAME OVER!!,YOU LOSE!!\n");
            return;
        }
        clrscr();
    }
}

void main()
{
    printf("                                     ------------------------\n");
    printf("                                     |    MATRIX PUZZLE     |\n");
    printf("                                     ------------------------\n\n\n");
    rule();
    char ch, chr, name[20];
    printf("Enter the player name: ");
    fgets(name, sizeof(name), stdin);
    printf("*******************************************Welcome to the game************************************************ ");
    printf("\n\n");
    printf("All the best!!!\n");
    int c;
    char cha;

start:
    printf("Enter the minimum number of moves required to solve puzzle: ");
    scanf("%d", &c);
    int arra[4][4] = {{7, 2, 5, 4}, {3, 6, 1, 8}, {13, 10, 15, 12}, {9, 14, 11}};
    matrixgame(arra, c, name);

    do
    {
        printf("Enter 'E'or'e' to exit and 'Y'or 'y' to continue: ");
        scanf(" %c", &cha);
        if (cha == 'y'|| cha == 'Y')
        {
            goto start;
        }
    } while (cha != 'e'||cha!= 'E');

}
