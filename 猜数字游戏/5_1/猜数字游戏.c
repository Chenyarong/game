#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu()
{
	printf("\n\n\n\n");
	printf("                              1.play  ��ʼ��Ϸ\n\n");
	printf("                              2.exit   �˳���Ϸ \n\n");
}

void game()
{
	int input = 0;//�û��²����������
	int random_num = rand() % 100 + 1;
	while (1)
	{
		printf("��������Ĳ²⣺");
		scanf_s("%d", &input);
		if (input <random_num)
		{
			printf("���ź�����С��\n\n");
		}
		else	if (input > random_num)
		{
			printf("���ź����´���\n\n");
		}
		else	
		{
			printf("��ϲ��¶��ˣ�����\n\n");
			break;
		}
	}
}

int main( )
{
	srand(time(NULL));
	int choice;//�û���ѡ��
	do
	{
		menu();
		printf("\n\n\n���������ѡ��:");
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
		{printf("ѡ�����������ѡ��:\n");
			break;
		}
	}while (choice);
	system("pause");
	return 0;
}