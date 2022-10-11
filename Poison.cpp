#include <Windows.h>
#include "auxiliary.h"
#include "Snaker.h"
#include "Poison.h"


//¶¾Îï
void CreatePoison()
{
	int FoodX = 0;
	int FoodY = 0;
	while (true)
	{
		FoodX = rand() % 38 + 1;
		FoodY = rand() % 38 + 1;

		if (g_Map[FoodX][FoodY] == Open_space)
		{
			g_Map[FoodX][FoodY] = Poison;
			WriteChar(FoodX, FoodY, FOREGROUND_RED, "¡ï");
			g_Poison = 1;
			break;
		}
	}
}