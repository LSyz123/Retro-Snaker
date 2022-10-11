#include <time.h>
#include <Windows.h>
#include "auxiliary.h"
#include "Snaker.h"
#include "Random_Obstacles.h"

//随机障碍物
int Random_Obstacles(int g_nHard)
{
	srand((unsigned)time(NULL));   //利用系统时间作为随机数的种子
	for (int i = 0; i < g_nHard * 3; i++)
	{
		int FoodX = rand() % 38 + 1;
		int FoodY = rand() % 38 + 1;
		if (g_Map[FoodX][FoodY] == Open_space && (FoodX != 15))
		{
			if (g_Map[FoodX][FoodY] == Open_space)
			{
				g_Map[FoodX][FoodY] = Obstacle;
				WriteChar(FoodX, FoodY, 0xF, "■");
			}
		}
	}
	return 0;
}