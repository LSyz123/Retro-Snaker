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


//��Ϸ�Ķ����ʹ浵��˼·�������Ƕ�������->�浵����->ʲôʱ����ж���(��ʼһ������Ϸ��ʱ��)->ʲôʱ����еĶ���(��Ϸ��ESC���ص�ʱ��)
//��Ϸ״̬�ı�־
//��Ϸ״̬�Ĵ浵������

void LoadPoint()
{
	for (int i = 0; i < nLength; i++)
	{
		WriteChar(Snake[i].X, Snake[i].Y, FOREGROUND_RED, "��");
	}
}

//����������Ϸ
void load_game()
{
	HindCursor();     //���ع��
	int nLive = 1;
	LoadPoint();     //��ʼ���ߵ�λ��

	DrawMap();        //��ʼ����ͼ

	if (g_FoodExist == 0) //����ͼ���Ƿ���ʳ����û���򴴽��µ�ʳ��
	{
		CreateFood();
	}
	if (g_Poison == 0)  //����ͼ���Ƿ��ж�����û���򴴽��µĶ���
	{
		CreatePoison();
	}

	int saveflag = 1;
	int retCode = 0;
	while (nLive)
	{
		retCode = GetDir();     //��ȡ����
		if (retCode == 100)
		{
			save();
			saveflag = 0;
			break;
		}

		nLive = MoveSnake();  //���ߵ��߼��Ǽ������ߺ����ͷλ�ã��ж���ͷλ��״̬
		                      //��ײǽ����ʳ����Լ����յأ�Ȼ���ٵ�ͼ�ϻ����µ��ߵ�λ�á�
		if (g_FoodExist == 0) //����ͼ���Ƿ���ʳ����û���򴴽��µ�ʳ��
		{
			CreateFood();
		}
		if (g_Poison == 0)  //����ͼ���Ƿ��ж�����û���򴴽��µĶ���
		{
			CreatePoison();
		}

		Sleep(speed);
	}

	for (int i = 0; i < nLength; i++)  //�������ڼ�¼��ͼ״̬������������ߵ�λ��
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
		PrintDie();     //��ʾ������ʾ�����Ը����Լ���������Ƴ���ʾ��������ʾ
	}
}

//��Ϸ��������
void load()
{
	//��ȡ��Ϸ�浵
	FILE* fp = NULL;     
	fopen_s(&fp, "Snake.txt", "rb");
	if (fp== NULL) 
	{
		fprintf(stderr, "No Game Cache Here!\n");
		return;
	}

	//��ȡ�߳��� 
	fread(&nLength, sizeof(int), 1, fp);
	//��ȡ���� 
	fread(&Dir, sizeof(int), 1, fp);

	//��ȡʳ������
	int TempX = 0;
	int TempY = 0;
	fread(&TempX, sizeof(int), 1, fp);
	fread(&TempY, sizeof(int), 1, fp);

	if (TempX != -1 && TempY != -1)
	{
		g_FoodExist = 1;
		g_Map[TempX][TempY] = Food;
		WriteChar(TempX, TempY, FOREGROUND_GREEN, "��");
	}

	//��ȡ��������
	fread(&TempX, sizeof(int), 1, fp);
	fread(&TempY, sizeof(int), 1, fp);

	if (TempX != -1 && TempY != -1)
	{
		g_Poison = 1;
		g_Map[TempX][TempY] = Poison;
		WriteChar(TempX, TempY, FOREGROUND_RED, "��");
	}
	//��ȡ����
	fread(&score, sizeof(int), 1, fp);
	//��ȡ�ٶ�
	fread(&speed, sizeof(int), 1, fp);
	//��ȡ��ͷ����

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

		WriteChar(TempX, TempY, 0xF, "��");
	}

	fclose(fp);

	load_game();  //������������Ϸ
}
