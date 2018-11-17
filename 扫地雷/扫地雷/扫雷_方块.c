#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10
#define DEFAULT_MINE_COUNT 10//定义地雷个数为10
//三个常量暂时都不能修改

void  menu()
{
	printf("\t\t\t=============================\n");
	printf("\t\t\t          1.开始游戏           \n");
	printf("\t\t\t          2.退出游戏           \n");
	printf("\t\t\t=============================\n");
	printf("\t\t\t\t请选择    ");
}
void init(char show_map[MAX_ROW + 2][MAX_COL + 2], char mine_map[MAX_ROW + 2][MAX_COL + 2])
{
	//对用户界面初始化，还都没有掀开的格子，全部都为空格
	for (int row = 0; row < MAX_ROW + 2; row++)
	{
		for (int col = 0; col < MAX_COL + 2; col++)
		{
			show_map[row][col] = ' ';
		}
	}
	//对含有地雷的地图初始化，全部初始化为‘ ’，暂时没有地雷的地图
	for (int row = 0; row < MAX_ROW + 2; row++)
	{
		for (int col = 0; col < MAX_COL + 2; col++)
		{
			mine_map[row][col] = ' ';
		}
	}
	int mine_count = DEFAULT_MINE_COUNT;
	while (mine_count>0)//随机布置地雷，布置10（从DEFAULT_MINE_COUNT减到0）个
	{
		int row = rand() % MAX_ROW + 1;
		int col = rand() % MAX_COL + 1;
		if (mine_map[row][col] == '1')//当前位置已经有雷，重新产生随机坐标
		{
			continue;
		}
		mine_map[row][col] = '1';//将含有地雷的位置表示为‘1’
		mine_count--;
	}
}
void DisplayMap(char map[MAX_ROW + 2][MAX_COL + 2])
{
	//打印第一行“     1   2   3   4   5   6   7   8   9   10  ”   列标签 
	printf("    |");
	for (int col = 1; col <= MAX_COL; col++)
		printf(" %2d ", col);
	printf("\n");
	//打印上边框
	for (int col = 1; col < MAX_COL; col++)
		printf("_____");
	printf("\n");
	//按行打印具体的地图
	for (int row = 1; row <= MAX_ROW; row++)
	{
		//printf(" %2d |   |   |   |   |   |   |   |   |   |", row);
		printf(" %2d | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", row,
			map[row][1], map[row][2], map[row][3], map[row][4], map[row][5], map[row][6],
			map[row][7], map[row][8], map[row][9], map[row][10]);//行坐标标签
		printf("    |___|___|___|___|___|___|___|___|___|___|\n");
	}

}

void updateshowmap(char showmap[MAX_ROW + 2][MAX_COL + 2], char minemap[MAX_ROW + 2][MAX_COL + 2], int row, int col)
//根据minemap函数计算(row，col)点周围地雷的数量
//结果写到对应的showmap上
{
	int mine_count = 0;
	//计算(row，col)点周围地雷的数量
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
		//由于加了边框，所以以下的坐标不会越界
		
		showmap[row - 1][col - 1] = '*';
		showmap[row - 1][col] = '*';
		showmap[row - 1][col + 1] = '*';
		showmap[row][col - 1] = '*';
		showmap[row][col + 1] = '*';
		showmap[row + 1][col - 1] = '*';
		showmap[row + 1][col] = '*';
		showmap[row + 1][col + 1] = '*';
	}

	showmap[row][col] = '0' + mine_count;//mine_count 是一个int型数值，不是字符，加上一个字符0
}
void game()
{
	//1.定义两个数组
	//2.对两个数组初始化
	//3.让玩家输入坐标，判断坐标是否合法
	//4.判定玩家是否踩雷，若踩雷，游戏结束，打印mine_map
	//5.如果没有踩雷，就判定是否掀开了所有的格子 （判定玩家是否胜利）   
	//6.如果没有全部掀开就统计该位置周围雷的数量并更新到地图上

	char show_map[MAX_ROW + 2][MAX_COL + 2];//表示给玩家展示的地图，加了边框，所以加了2，边框用于打印地图的行列号
	char mine_map[MAX_ROW + 2][MAX_COL + 2];//表示还有地雷的地图
	int black_count = 0;//掀开格子的数量
	init(show_map, mine_map);
	DisplayMap(show_map);
	while (1)
	{
		int row; int col;
		printf("请玩家输入坐标：");
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > MAX_ROW || col <= 0 || col > MAX_COL)
		{
			printf("输入坐标不合法，请重新输入:");
			continue;
		}
		if (mine_map[row][col] == '1')//判断是否踩雷：踩雷游戏结束，打印
		{
			printf("游戏结束\n");
			DisplayMap(mine_map);
			break;
		}
		++black_count;//每输入一次坐标就计算掀开格子的数量
		if (black_count == MAX_ROW*MAX_COL - DEFAULT_MINE_COUNT)//所有格子都被掀开,玩家胜利,打印，结束游戏
		{
			printf("恭喜您扫完了所有的雷！！!\n");
			DisplayMap(show_map);
			break;
		}
		updateshowmap(show_map, mine_map, row, col);
		DisplayMap(show_map);
	}
}
void started()//游戏入口
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
			printf("输入非法，请重新输入");
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
