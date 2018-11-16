#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 3
char g_board[ROW][COL];//����ȫ�ֱ���
void init()//���̳�ʼ��
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL;col++)
			g_board[row][col]=' ';
	}
}
void print()//��ӡ����
{
	printf("\t\t\t ___ ___ ___ \n");
	for (int row= 0; row< ROW; row++)
	{
		printf("\t\t\t| %c | %c | %c |\n", g_board[row][0],g_board[row][1],g_board[row][2]);
		printf("\t\t\t|___|___|___|\n");
	}
}

void playmove()//�������
{
	printf("��������ӣ�\n");
	printf("������������ӵ�λ�����꣺(row col)");
	while (1)
	{
		int row; int col;
		scanf_s("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("����λ���������������룺");
			continue;
		}
		if (g_board[row][col] !=' ')
		{
			printf("��λ�������ӣ����������룺");
			continue;
		}
		g_board[row][col] = 'X';
		break;
	}
}

void computermove( )//��������
{
	printf("�������������У�\n");
	while (1)
	{
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_board[row][col] != ' ')
		{
			continue;
		}
		g_board[row][col] = 'C';
		printf("�������ӵ�λ��Ϊ(%d %d)\n", row, col);
		break;
	}
}
char checkwinner()//�ж���Ӯ��������е��С��С�б�߷���
{
	for (int row = 0; row < ROW; row++)//������е���
	{
		if (g_board[row][0] == g_board[row][1] &&
			g_board[row][1] == g_board[row][2] &&
			g_board[row][0] != ' ')
		{
			return g_board[row][1];
		}
	}
	for (int col = 0; col < COL; col++)//������е���
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
		g_board[0][0] !=0)//��������Խ���
		return g_board[1][1];
	if (g_board[0][2] == g_board[1][1] &&
		g_board[2][0] == g_board[1][1] &&
		g_board[1][1] != 0)//��������Խ���
		return g_board[1][1];
	//�жϺ���
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
		printf("                 \t��ϲ��Ӯ�ˣ�����\n");
	}
	else if (winner == 'C')
	{
		print();
		printf("          \t  ���ź������ˣ�����\n");
	}
	else if (winner==0)
	{
		print(); 
		printf("                 \t����\n");
	}
	printf("\n\n");
	system("pause");
	return 0;
}