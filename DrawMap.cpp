#include <Windows.h>
#include <stdio.h>
#include "Snaker.h"
#include "auxiliary.h"
#include "DrawMap.h"




//将地图绘制出来
void DrawMap()
{
	//画出地图边框
	for (int i = 0; i < Map_X; i++)
	{
		for (int j = 0; j < Map_Y; j++)
		{
			if (g_Map[i][j] == Obstacle)
			{
				WriteChar(i, j, 0xF, "■");
			}
		}
	}
	char* score_buff = (char*)malloc(30);
	char* speed_buff = (char*)malloc(30);

	if (score_buff == NULL || speed_buff == NULL)
	{
		return;
	}

	memset(score_buff, 0, 30);
	memset(speed_buff, 0, 30);

	sprintf_s(score_buff, 30, "Score: %d    ", score);
	sprintf_s(speed_buff, 30, "Speed: %d    ", 500 - speed);

	//画出成绩板, 速度表， 作者
	WriteChar(4, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, "Powered by: Reol");
	WriteChar(5, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, score_buff);
	WriteChar(6, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, speed_buff);
	WriteChar(7, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, "         ");
	WriteChar(8, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, "Red stars are poisons: ★ ");
	WriteChar(9, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, "White squares are obstacles:  ■");
	WriteChar(10, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, "Green squares are food:  ■");
	WriteChar(11, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, "Rule:  Up->W  Down->S  Left->A Right->D");
	WriteChar(12, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, "Warm Tip: Press Space to pause and continue!");

	free(score_buff);
	free(speed_buff);
}
