#include <Windows.h>
#include <stdio.h>
#include "auxiliary.h"
#include "DrawMap.h"
#include "Snaker.h"
#include "Food.h"
#include "Poison.h"
#include "User operation.h"
#include "Archive Save.h"
#include "Archive Game option.h"
#include "StartGame.h"
#include "Menu.h"
#include "MapInitialization.h"

//开始游戏
void StartGame() //这个是没有进行初始化地图就可以直接开始游戏的
{
	system("cls");
	Dir = Right;
	score = 0;
	nLength = 4;
	HindCursor();       //隐藏光标
	StartPoint();       //初始化蛇的位置
	DrawMap();          //画地图
	CreateFood();       //食物
	CreatePoison();     //毒物
	int retCode = 0;
	int nLive = 1;        //蛇的状态
	int saveflag = 1;
	while (nLive)
	{
		retCode = GetDir(); //获取输入
		if (retCode == 100)
		{
			save(); //读档
			saveflag = 0;
			break;
		}

		nLive = MoveSnake(); //行走的逻辑是计算行走后的蛇头位置，判断蛇头位置状态（撞墙，吃食物，吃自己,空地）然后在地图上画出新的蛇位置。
		if (g_FoodExist == 0)//检测地图上是否有食物，如果没有则创建新的食物
		{
			CreateFood();
		}
		if (g_Poison == 0)   //检测地图上是否有毒物，如果没有则创建新的毒物
		{
			CreatePoison();
		}
		
		Sleep(speed);
	}
	
	//死亡后在记录地图状态的数组中清除蛇的位置
	for (int i = 0; i < nLength; i++)
	{
		g_Map[Snake[i].X][Snake[i].Y] = Open_space;
	}

	// 清除地图中的障碍物
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

//开始游戏
void Start() //这个是需要初始化地图才可以开始游戏，因为两个界面直接来回切换的时候就是会突然就不是原本想的那样了，就是会特别的容易错乱，就分开了
{
	Dir = Right;
	speed = 500;
	nLength = 4;
	HindCursor();       //隐藏光标
	StartPoint();       //初始化蛇的位置
	MapInitialization();//地图的初始化
	DrawMap();          //画地图边框
	CreateFood();       //食物
	CreatePoison();     //毒物
	int retCode = 0;
	int nLive = 1;        //蛇的状态
	int saveflag = 1;
	while (nLive)
	{
		retCode = GetDir(); //获取输入
		if (retCode == 100)
		{
			save(); //读档
			saveflag = 0;
			break;
		}

		nLive = MoveSnake(); //行走的逻辑是计算行走后的蛇头位置，判断蛇头位置状态（撞墙，吃食物，吃自己,空地）然后在地图上画出新的蛇位置。
		if (g_FoodExist == 0)//检测地图上是否有食物，如果没有则创建新的食物
		{
			CreateFood();
		}
		if (g_Poison == 0)   //检测地图上是否有毒物，如果没有则创建新的毒物
		{
			CreatePoison();
		}

		Sleep(speed);
	}

	//死亡后在记录地图状态的数组中清除蛇的位置
	for (int i = 0; i < nLength; i++)  
	{
		g_Map[Snake[i].X][Snake[i].Y] = Open_space;
	}

	// 清除地图中的障碍物
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
