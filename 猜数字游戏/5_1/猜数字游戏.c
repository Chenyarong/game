#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("\n\n\n\n");
	printf("                              1.play  开始游戏\n\n");
	printf("                              2.exit   退出游戏 \n\n");
}

void game()
{
	int input = 0;//用户猜测输入的数字
	int random_num = rand() % 100 + 1;
	while (1)
	{
		printf("请输入你的猜测：");
		scanf_s("%d", &input);
		if (input <random_num)
		{
			printf("很遗憾，猜小了\n\n");
		}
		else	if (input > random_num)
		{
			printf("很遗憾，猜大了\n\n");
		}
		else	
		{
			printf("恭喜你猜对了！！！\n\n");
			break;
		}
	}
}

int main( )
{
	srand(time(NULL));
	int choice;//用户的选择
	do
	{
		menu();
		printf("\n\n\n请输入你的选择:");
		scanf_s("%d", &choice);
		if (choice== 1)
		{
			game();
			break;
		}
		else if (choice == 2)
		{
			printf("goodbye\n");
			break;
		}
		else
		{printf("选择错误，请重新选择:\n");
			break;
		}
	}while (choice);
	system("pause");
	return 0;
}