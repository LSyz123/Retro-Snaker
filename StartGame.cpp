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

//��ʼ��Ϸ
void StartGame() //�����û�н��г�ʼ����ͼ�Ϳ���ֱ�ӿ�ʼ��Ϸ��
{
	system("cls");
	Dir = Right;
	score = 0;
	nLength = 4;
	HindCursor();       //���ع��
	StartPoint();       //��ʼ���ߵ�λ��
	DrawMap();          //����ͼ
	CreateFood();       //ʳ��
	CreatePoison();     //����
	int retCode = 0;
	int nLive = 1;        //�ߵ�״̬
	int saveflag = 1;
	while (nLive)
	{
		retCode = GetDir(); //��ȡ����
		if (retCode == 100)
		{
			save(); //����
			saveflag = 0;
			break;
		}

		nLive = MoveSnake(); //���ߵ��߼��Ǽ������ߺ����ͷλ�ã��ж���ͷλ��״̬��ײǽ����ʳ����Լ�,�յأ�Ȼ���ڵ�ͼ�ϻ����µ���λ�á�
		if (g_FoodExist == 0)//����ͼ���Ƿ���ʳ����û���򴴽��µ�ʳ��
		{
			CreateFood();
		}
		if (g_Poison == 0)   //����ͼ���Ƿ��ж�����û���򴴽��µĶ���
		{
			CreatePoison();
		}
		
		Sleep(speed);
	}
	
	//�������ڼ�¼��ͼ״̬������������ߵ�λ��
	for (int i = 0; i < nLength; i++)
	{
		g_Map[Snake[i].X][Snake[i].Y] = Open_space;
	}

	// �����ͼ�е��ϰ���
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
		PrintDie();     //��ʾ������ʾ�����Ը����Լ���������Ƴ���ʾ��������ʾ
	}
}

//��ʼ��Ϸ
void Start() //�������Ҫ��ʼ����ͼ�ſ��Կ�ʼ��Ϸ����Ϊ��������ֱ�������л���ʱ����ǻ�ͻȻ�Ͳ���ԭ����������ˣ����ǻ��ر�����״��ң��ͷֿ���
{
	Dir = Right;
	speed = 500;
	nLength = 4;
	HindCursor();       //���ع��
	StartPoint();       //��ʼ���ߵ�λ��
	MapInitialization();//��ͼ�ĳ�ʼ��
	DrawMap();          //����ͼ�߿�
	CreateFood();       //ʳ��
	CreatePoison();     //����
	int retCode = 0;
	int nLive = 1;        //�ߵ�״̬
	int saveflag = 1;
	while (nLive)
	{
		retCode = GetDir(); //��ȡ����
		if (retCode == 100)
		{
			save(); //����
			saveflag = 0;
			break;
		}

		nLive = MoveSnake(); //���ߵ��߼��Ǽ������ߺ����ͷλ�ã��ж���ͷλ��״̬��ײǽ����ʳ����Լ�,�յأ�Ȼ���ڵ�ͼ�ϻ����µ���λ�á�
		if (g_FoodExist == 0)//����ͼ���Ƿ���ʳ����û���򴴽��µ�ʳ��
		{
			CreateFood();
		}
		if (g_Poison == 0)   //����ͼ���Ƿ��ж�����û���򴴽��µĶ���
		{
			CreatePoison();
		}

		Sleep(speed);
	}

	//�������ڼ�¼��ͼ״̬������������ߵ�λ��
	for (int i = 0; i < nLength; i++)  
	{
		g_Map[Snake[i].X][Snake[i].Y] = Open_space;
	}

	// �����ͼ�е��ϰ���
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
		PrintDie();     //��ʾ������ʾ�����Ը����Լ���������Ƴ���ʾ��������ʾ
	}
}
