#include <Windows.h>
#include <stdio.h>
#include "Snaker.h"
#include "auxiliary.h"
#include "Snaketail.h"
#include "Snakehead.h"

COORD Snake[100];       //蛇最长的长度是100个方块
int nLength = 4;        //蛇身最初的原始长度就是4个方块
int Dir = Right;	    //方向默认为右
//int NewDir = Down;      //读档之后蛇的方向
int g_Map[Map_X][Map_Y] = { 0 }; //地图
int g_FoodExist = 0;   //初始化的食物是不存在的
int g_Poison = 0;      //初始化的毒物是不存在的
int score = 0;         //初始化的分数是0       
int speed = 500;       //开始游戏的速度是500

//蛇头开始坐标
void StartPoint()
{
	//蛇最开始出现在地图上的位置
	Snake[3].X = 10;
	Snake[3].Y = 3;
	Snake[2].X = 10;
	Snake[2].Y = 4;
	Snake[1].X = 10;
	Snake[1].Y = 5;
	Snake[0].X = 10;
	Snake[0].Y = 6;
}

//蛇移动
int MoveSnake()
{
	int nTempX = Snake[0].X;     //根据蛇的方向移动点的位置
	int nTempY = Snake[0].Y;
	switch (Dir)
	{
		case Up:nTempX--;break;
		case Down:nTempX++;break;
		case Left:nTempY--;break;
		case Right:nTempY++;break;
	}
	//判断有没有撞到东西
		/*
		 蛇头可能会撞到什么东西
		 1.空地
		 2.自己
		 3.食物（道具）
		 4.障碍物
		*/
	if (g_Map[nTempX][nTempY] == Open_space)
	{	
	}
	else if (g_Map[nTempX][nTempY] == Self)
	{
		return 0;
	}
	else if (g_Map[nTempX][nTempY] == Food)
	{
		nLength++;
		g_Map[nTempX][nTempY] = Self;
		g_FoodExist = 0;
		score++;
		if (speed > 200)
		{
			speed -= 5;
		}
		char buff[20];
		memset(buff, 0, 20);
		sprintf_s(buff, 20, "Score: %d    ", score);
		WriteChar(5, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, buff);
		memset(buff, 0, 20);
		sprintf_s(buff, 20, "Speed: %d    ", 500 - speed);
		WriteChar(6, Map_Y + 10, FOREGROUND_GREEN | FOREGROUND_RED, buff);
	}
	else if (g_Map[nTempX][nTempY] == Obstacle)
	{
		return 0;
	}
	else if (g_Map[nTempX][nTempY] == Poison)
	{
		return 0;
	}

	//清除蛇尾
	Snaketail();

	for (int i = nLength; i >= 0; i--)       //修改蛇每一个节点的坐标为走一步后的状态
	{
		Snake[i + 1].X = Snake[i].X;
		Snake[i + 1].Y = Snake[i].Y;
	}
	Snake[0].X = nTempX;
	Snake[0].Y = nTempY;

	//画出蛇头
	Snakehead();

	return 1;
}










