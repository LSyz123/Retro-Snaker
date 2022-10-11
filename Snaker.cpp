#include <Windows.h>
#include <stdio.h>
#include "Snaker.h"
#include "auxiliary.h"
#include "Snaketail.h"
#include "Snakehead.h"

COORD Snake[100];       //����ĳ�����100������
int nLength = 4;        //���������ԭʼ���Ⱦ���4������
int Dir = Right;	    //����Ĭ��Ϊ��
//int NewDir = Down;      //����֮���ߵķ���
int g_Map[Map_X][Map_Y] = { 0 }; //��ͼ
int g_FoodExist = 0;   //��ʼ����ʳ���ǲ����ڵ�
int g_Poison = 0;      //��ʼ���Ķ����ǲ����ڵ�
int score = 0;         //��ʼ���ķ�����0       
int speed = 500;       //��ʼ��Ϸ���ٶ���500

//��ͷ��ʼ����
void StartPoint()
{
	//���ʼ�����ڵ�ͼ�ϵ�λ��
	Snake[3].X = 10;
	Snake[3].Y = 3;
	Snake[2].X = 10;
	Snake[2].Y = 4;
	Snake[1].X = 10;
	Snake[1].Y = 5;
	Snake[0].X = 10;
	Snake[0].Y = 6;
}

//���ƶ�
int MoveSnake()
{
	int nTempX = Snake[0].X;     //�����ߵķ����ƶ����λ��
	int nTempY = Snake[0].Y;
	switch (Dir)
	{
		case Up:nTempX--;break;
		case Down:nTempX++;break;
		case Left:nTempY--;break;
		case Right:nTempY++;break;
	}
	//�ж���û��ײ������
		/*
		 ��ͷ���ܻ�ײ��ʲô����
		 1.�յ�
		 2.�Լ�
		 3.ʳ����ߣ�
		 4.�ϰ���
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

	//�����β
	Snaketail();

	for (int i = nLength; i >= 0; i--)       //�޸���ÿһ���ڵ������Ϊ��һ�����״̬
	{
		Snake[i + 1].X = Snake[i].X;
		Snake[i + 1].Y = Snake[i].Y;
	}
	Snake[0].X = nTempX;
	Snake[0].Y = nTempY;

	//������ͷ
	Snakehead();

	return 1;
}










