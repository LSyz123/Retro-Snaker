#include <stdio.h>
#include <Windows.h>
#include "Snaker.h"
#include "Archive Save.h"

//游戏存档函数
void save()
{
	FILE* fp = NULL;
	fopen_s(&fp, "Snake.txt", "wb");

	if (fp == NULL) 
	{
		fprintf(stderr, "Can't open Snake.txt!\n");
		exit(1);
	}

	//保存蛇长度 
	fwrite(&nLength, sizeof(int), 1, fp);
	//保存方向 
	fwrite(&Dir, sizeof(int), 1, fp);

	int invalid = -1;

	//保存食物坐标
	if (g_FoodExist != 0)
	{
		for (int x = 0; x < Map_X; x++)
		{
			for (int y = 0; y < Map_Y; y++)
			{
				if (g_Map[x][y] == Food)
				{
					fwrite(&x, sizeof(int), 1, fp);
					fwrite(&y, sizeof(int), 1, fp);
					goto saved_food;
				}
			}
		}
	}
	else
	{
		fwrite(&invalid, sizeof(int), 1, fp);
		fwrite(&invalid, sizeof(int), 1, fp);
	}

saved_food:
	printf(""); // 占位置，没意义

	//保存毒物坐标
	if (g_Poison != 0)
	{
		for (int x = 0; x < Map_X; x++)
		{
			for (int y = 0; y < Map_Y; y++)
			{
				if (g_Map[x][y] == Poison)
				{
					fwrite(&x, sizeof(int), 1, fp);
					fwrite(&y, sizeof(int), 1, fp);
					goto saved_poison;
				}
			}
		}
	}
	else
	{
		fwrite(&invalid, sizeof(int), 1, fp);
		fwrite(&invalid, sizeof(int), 1, fp);
	}

saved_poison:
	printf(""); // 占位置，没意义

	//保存分数
	fwrite(&score, sizeof(int), 1, fp);
	//保存速度
	fwrite(&speed, sizeof(int), 1, fp);

	//保存蛇坐标
	for (int i = 0; i < nLength; i++)
	{
		fwrite(&Snake[i].X, sizeof(int), 1, fp);
		fwrite(&Snake[i].Y, sizeof(int), 1, fp);
	}

	// 保存障碍物
	struct point
	{
		int x;
		int y;
	};
	point* items = (point*)malloc(sizeof(point) * (Map_X - 2) * (Map_Y - 2));
	int len = 0;
	if (items != 0)
	{
		memset(items, 0, sizeof(point) * (Map_X - 2)* (Map_Y - 2));
		int len = 0;

		// 把所有的障碍物的坐标取出来
		for (int i = 1; i < Map_X - 1; i++)
		{
			for (int j = 1; j < Map_Y - 1; j++)
			{
				if (g_Map[i][j] == Obstacle)
				{
					items[len].x = i;
					items[len].y = j;
					len++;
				}
			}
		}

		fwrite(&len, sizeof(int), 1, fp);

		for (int i = 0; i < len; i++)
		{
			fwrite(&items[i].x, sizeof(int), 1, fp);
			fwrite(&items[i].y, sizeof(int), 1, fp);
		}

		free(items);
	}
	else
	{
		fwrite(&len, sizeof(int), 1, fp);
	}
	
	fclose(fp);
}