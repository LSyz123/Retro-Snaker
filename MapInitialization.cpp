#include <stdio.h>
#include <windows.h>
#include "MapInitialization.h"
#include "Snaker.h"

//µÿÕº≥ı ºªØ
void MapInitialization()
{
	for (int i = 0; i < Map_X; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (i == 0 || j == 0 || i == Map_X - 1 || j == Map_Y - 1)
			{
				g_Map[i][j] = Obstacle;
			}
			else
			{
				g_Map[i][j] = Open_space;
			}
		}
	}
}