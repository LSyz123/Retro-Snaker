#include <time.h>
#include <Windows.h>
#include "auxiliary.h"
#include "Snaker.h"
#include "Random_Obstacles.h"

//����ϰ���
int Random_Obstacles(int g_nHard)
{
	srand((unsigned)time(NULL));   //����ϵͳʱ����Ϊ�����������
	for (int i = 0; i < g_nHard * 3; i++)
	{
		int FoodX = rand() % 38 + 1;
		int FoodY = rand() % 38 + 1;
		if (g_Map[FoodX][FoodY] == Open_space && (FoodX != 15))
		{
			if (g_Map[FoodX][FoodY] == Open_space)
			{
				g_Map[FoodX][FoodY] = Obstacle;
				WriteChar(FoodX, FoodY, 0xF, "��");
			}
		}
	}
	return 0;
}