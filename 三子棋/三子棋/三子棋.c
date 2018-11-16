#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 3
char g_board[ROW][COL];//定义全局变量
void init()//棋盘初始化
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL;col++)
			g_board[row][col]=' ';
	}
}
void print()//打印棋盘
{
	printf("\t\t\t ___ ___ ___ \n");
	for (int row= 0; row< ROW; row++)
	{
		printf("\t\t\t| %c | %c | %c |\n", g_board[row][0],g_board[row][1],g_board[row][2]);
		printf("\t\t\t|___|___|___|\n");
	}
}

void playmove()//玩家落子
{
	printf("请玩家落子！\n");
	printf("请玩家输入落子的位置坐标：(row col)");
	while (1)
	{
		int row; int col;
		scanf_s("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("坐标位置有误，请重新输入：");
			continue;
		}
		if (g_board[row][col] !=' ')
		{
			printf("该位置已落子，请重新输入：");
			continue;
		}
		g_board[row][col] = 'X';
		break;
	}
}

void computermove( )//电脑落子
{
	printf("电脑正在落子中！\n");
	while (1)
	{
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_board[row][col] != ' ')
		{
			continue;
		}
		g_board[row][col] = 'C';
		printf("电脑落子的位置为(%d %d)\n", row, col);
		break;
	}
}
char checkwinner()//判断输赢，检查所有的行、列、斜线方向
{
	for (int row = 0; row < ROW; row++)//检查所有的行
	{
		if (g_board[row][0] == g_board[row][1] &&
			g_board[row][1] == g_board[row][2] &&
			g_board[row][0] != ' ')
		{
			return g_board[row][1];
		}
	}
	for (int col = 0; col < COL; col++)//检查所有的列
	{
		if (g_board[0][col] == g_board[1][col] &&
			g_board[1][col] == g_board[2][col] &&
			g_board[1][col] != ' ')
		{
			return g_board[1][col];
		}
	}
	if (g_board[0][0] == g_board[1][1] &&
		g_board[2][2] == g_board[1][1]&&
		g_board[0][0] !=0)//检查两条对角线
		return g_board[1][1];
	if (g_board[0][2] == g_board[1][1] &&
		g_board[2][0] == g_board[1][1] &&
		g_board[1][1] != 0)//检查两条对角线
		return g_board[1][1];
	//判断和棋
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (g_board[row][col] != ' ')
				return 0;
			if (g_board[row][col]==' ')
			{
				return ' ';
			}
		}
	}
}
int main()
{
	srand((unsigned int)time(0));
	printf("\n\n");
	init();
	char winner;
	while (1)
	{ 
		print();
		playmove();
		print();
		winner=checkwinner();
		if (winner != ' ')
			break;
		computermove();
		winner=checkwinner();
		if (winner != ' ')
			break;
	}	
	if (winner == 'X')
	{
		print();
		printf("                 \t恭喜您赢了！！！\n");
	}
	else if (winner == 'C')
	{
		print();
		printf("          \t  很遗憾您输了！！！\n");
	}
	else if (winner==0)
	{
		print(); 
		printf("                 \t和棋\n");
	}
	printf("\n\n");
	system("pause");
	return 0;
}