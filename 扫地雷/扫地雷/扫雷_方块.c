#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10
#define DEFAULT_MINE_COUNT 10//������׸���Ϊ10
//����������ʱ�������޸�

void  menu()
{
	printf("\t\t\t=============================\n");
	printf("\t\t\t          1.��ʼ��Ϸ           \n");
	printf("\t\t\t          2.�˳���Ϸ           \n");
	printf("\t\t\t=============================\n");
	printf("\t\t\t\t��ѡ��    ");
}
void init(char show_map[MAX_ROW + 2][MAX_COL + 2], char mine_map[MAX_ROW + 2][MAX_COL + 2])
{
	//���û������ʼ��������û���ƿ��ĸ��ӣ�ȫ����Ϊ�ո�
	for (int row = 0; row < MAX_ROW + 2; row++)
	{
		for (int col = 0; col < MAX_COL + 2; col++)
		{
			show_map[row][col] = ' ';
		}
	}
	//�Ժ��е��׵ĵ�ͼ��ʼ����ȫ����ʼ��Ϊ�� ������ʱû�е��׵ĵ�ͼ
	for (int row = 0; row < MAX_ROW + 2; row++)
	{
		for (int col = 0; col < MAX_COL + 2; col++)
		{
			mine_map[row][col] = ' ';
		}
	}
	int mine_count = DEFAULT_MINE_COUNT;
	while (mine_count>0)//������õ��ף�����10����DEFAULT_MINE_COUNT����0����
	{
		int row = rand() % MAX_ROW + 1;
		int col = rand() % MAX_COL + 1;
		if (mine_map[row][col] == '1')//��ǰλ���Ѿ����ף����²����������
		{
			continue;
		}
		mine_map[row][col] = '1';//�����е��׵�λ�ñ�ʾΪ��1��
		mine_count--;
	}
}
void DisplayMap(char map[MAX_ROW + 2][MAX_COL + 2])
{
	//��ӡ��һ�С�     1   2   3   4   5   6   7   8   9   10  ��   �б�ǩ 
	printf("    |");
	for (int col = 1; col <= MAX_COL; col++)
		printf(" %2d ", col);
	printf("\n");
	//��ӡ�ϱ߿�
	for (int col = 1; col < MAX_COL; col++)
		printf("_____");
	printf("\n");
	//���д�ӡ����ĵ�ͼ
	for (int row = 1; row <= MAX_ROW; row++)
	{
		//printf(" %2d |   |   |   |   |   |   |   |   |   |", row);
		printf(" %2d | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", row,
			map[row][1], map[row][2], map[row][3], map[row][4], map[row][5], map[row][6],
			map[row][7], map[row][8], map[row][9], map[row][10]);//�������ǩ
		printf("    |___|___|___|___|___|___|___|___|___|___|\n");
	}

}

void updateshowmap(char showmap[MAX_ROW + 2][MAX_COL + 2], char minemap[MAX_ROW + 2][MAX_COL + 2], int row, int col)
//����minemap��������(row��col)����Χ���׵�����
//���д����Ӧ��showmap��
{
	int mine_count = 0;
	//����(row��col)����Χ���׵�����
	for (int i = row - 1; i <= row + 1; i++)
	{
		for (int j = col - 1; j <= col + 1; j++)
		{
			if (minemap[i][j] == '1')
				mine_count++;
		}
	}
	if (mine_count == 0)
	{
		//���ڼ��˱߿��������µ����겻��Խ��
		showmap[row - 1][col - 1] = '0';
		showmap[row - 1][col] = '0';
		showmap[row - 1][col + 1] = '0';
		showmap[row][col - 1] = '0';
		showmap[row][col + 1] = '0';
		showmap[row + 1][col - 1] = '0';
		showmap[row + 1][col] = '0';
		showmap[row + 1][col + 1] = '0';
	}

	showmap[row][col] = '0' + mine_count;//mine_count ��һ��int����ֵ�������ַ�������һ���ַ�0
}
void game()
{
	//1.������������
	//2.�����������ʼ��
	//3.������������꣬�ж������Ƿ�Ϸ�
	//4.�ж�����Ƿ���ף������ף���Ϸ��������ӡmine_map
	//5.���û�в��ף����ж��Ƿ��ƿ������еĸ��� ���ж�����Ƿ�ʤ����   
	//6.���û��ȫ���ƿ���ͳ�Ƹ�λ����Χ�׵����������µ���ͼ��

	char show_map[MAX_ROW + 2][MAX_COL + 2];//��ʾ�����չʾ�ĵ�ͼ�����˱߿����Լ���2���߿����ڴ�ӡ��ͼ�����к�
	char mine_map[MAX_ROW + 2][MAX_COL + 2];//��ʾ���е��׵ĵ�ͼ
	int black_count = 0;//�ƿ����ӵ�����
	init(show_map, mine_map);
	DisplayMap(show_map);
	while (1)
	{
		int row; int col;
		printf("������������꣺");
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > MAX_ROW || col <= 0 || col > MAX_COL)
		{
			printf("�������겻�Ϸ�������������:");
			continue;
		}
		if (mine_map[row][col] == '1')//�ж��Ƿ���ף�������Ϸ��������ӡ
		{
			printf("��Ϸ����\n");
			DisplayMap(mine_map);
			break;
		}
		++black_count;//ÿ����һ������ͼ����ƿ����ӵ�����
		if (black_count == MAX_ROW*MAX_COL - DEFAULT_MINE_COUNT)//���и��Ӷ����ƿ�,���ʤ��,��ӡ��������Ϸ
		{
			printf("��ϲ��ɨ�������е��ף���!\n");
			DisplayMap(show_map);
			break;
		}
		updateshowmap(show_map, mine_map, row, col);
		DisplayMap(show_map);
	}
}
void started()//��Ϸ���
{
	menu();
	int choice;
	while (1)
	{
		scanf("%d", &choice);
		if (choice == 2)
			break;
		else if (choice == 1)
		{
			game();
		}
		else
		{
			printf("����Ƿ�������������");
			continue;
		}
	}
}

int main()
{
	started();
	system("pause");
	return 0;
}
