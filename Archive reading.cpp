#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "Archive reading.h"
#include "auxiliary.h"
#include "User operation.h"
#include "Food.h"
#include "Poison.h"
#include "StartGame.h"
#include "DrawMap.h"
#include "Snaker.h"
#include "Archive Save.h"
#include "Menu.h"


//游戏的读档和存档：思路：首先是读档函数->存档函数->什么时候进行读档(开始一个新游戏的时候)->什么时候进行的读档(游戏在ESC返回的时候)
//游戏状态的标志
//游戏状态的存档，读档

void LoadPoint()
{
	for (int i = 0; i < nLength; i++)
	{
		WriteChar(Snake[i].X, Snake[i].Y, FOREGROUND_RED, "■");
	}
}

//重新载入游戏
void load_game()
{
	HindCursor();     //隐藏光标
	int nLive = 1;
	LoadPoint();     //初始化蛇的位置

	DrawMap();        //初始化地图

	if (g_FoodExist == 0) //检测地图上是否有食物，如果没有则创建新的食物
	{
		CreateFood();
	}
	if (g_Poison == 0)  //检测地图上是否有毒物，如果没有则创建新的毒物
	{
		CreatePoison();
	}

	int saveflag = 1;
	int retCode = 0;
	while (nLive)
	{
		retCode = GetDir();     //获取输入
		if (retCode == 100)
		{
			save();
			saveflag = 0;
			break;
		}

		nLive = MoveSnake();  //行走的逻辑是计算行走后的蛇头位置，判断蛇头位置状态
		                      //（撞墙，吃食物，吃自己，空地）然后再地图上画出新的蛇的位置。
		if (g_FoodExist == 0) //检测地图上是否有食物，如果没有则创建新的食物
		{
			CreateFood();
		}
		if (g_Poison == 0)  //检测地图上是否有毒物，如果没有则创建新的毒物
		{
			CreatePoison();
		}

		Sleep(speed);
	}

	for (int i = 0; i < nLength; i++)  //死亡后在记录地图状态的数组中清除蛇的位置
	{
		g_Map[Snake[i].X][Snake[i].Y] = Open_space;
	}

	for (int i = 1; i < Map_X - 1; i++)
	{
		for (int j = 1; j < Map_Y - 1; j++)
		{
			if (g_Map[i][j] == Obstacle)
			{
				g_Map[i][j] = Open_space;
			}
		}
	}

	if (saveflag == 0)
	{
		PrintSave();
	}
	else
	{
		PrintDie();     //显示死亡提示，可以根据自己的需求，设计出显示的死亡提示
	}
}

//游戏读档函数
void load()
{
	//读取游戏存档
	FILE* fp = NULL;     
	fopen_s(&fp, "Snake.txt", "rb");
	if (fp== NULL) 
	{
		fprintf(stderr, "No Game Cache Here!\n");
		return;
	}

	//读取蛇长度 
	fread(&nLength, sizeof(int), 1, fp);
	//读取方向 
	fread(&Dir, sizeof(int), 1, fp);

	//读取食物坐标
	int TempX = 0;
	int TempY = 0;
	fread(&TempX, sizeof(int), 1, fp);
	fread(&TempY, sizeof(int), 1, fp);

	if (TempX != -1 && TempY != -1)
	{
		g_FoodExist = 1;
		g_Map[TempX][TempY] = Food;
		WriteChar(TempX, TempY, FOREGROUND_GREEN, "■");
	}

	//读取毒物坐标
	fread(&TempX, sizeof(int), 1, fp);
	fread(&TempY, sizeof(int), 1, fp);

	if (TempX != -1 && TempY != -1)
	{
		g_Poison = 1;
		g_Map[TempX][TempY] = Poison;
		WriteChar(TempX, TempY, FOREGROUND_RED, "★");
	}
	//读取分数
	fread(&score, sizeof(int), 1, fp);
	//读取速度
	fread(&speed, sizeof(int), 1, fp);
	//读取蛇头坐标

	for (int i = 0; i < nLength; i++)
	{
		fread(&Snake[i].X, sizeof(int), 1, fp);
		fread(&Snake[i].Y, sizeof(int), 1, fp);
	}

	int len = 0;

	fread(&len, sizeof(int), 1, fp);
	for (int i = 0; i < len; i++)
	{
		fread(&TempX, sizeof(int), 1, fp);
		fread(&TempY, sizeof(int), 1, fp);

		WriteChar(TempX, TempY, 0xF, "■");
	}

	fclose(fp);

	load_game();  //重新再载入游戏
}
