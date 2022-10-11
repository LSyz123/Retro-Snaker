#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "Snaker.h"
#include "auxiliary.h"
#include "Food.h"


//Ê³Îï
void CreateFood()
{
	int FoodX = 0;
	int FoodY = 0;
	while (true)
	{
		FoodX = rand() % 38 + 1;
		FoodY = rand() % 38 + 1;
		if (g_Map[FoodX][FoodY] == Open_space)
		{
			g_Map[FoodX][FoodY] = Food;
			WriteChar(FoodX, FoodY, FOREGROUND_GREEN, "¡ö");
			g_FoodExist = 1;
			break;
		}
	}
}