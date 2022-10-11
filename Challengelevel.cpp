#include <stdio.h>
#include <windows.h>
#include "StartGame.h"
#include "DrawMap.h"
#include "Random_Obstacles.h"
#include "Snaker.h"
#include "Challengelevel.h"
#include "Archive Game option.h"
#include "Archive reading.h"
#include "ChallengeShow.h"
#include "MapInitialization.h"

int flaglevel = 0;

//��������һ�� ��Ϸ������ѡ��ȼ�������Ϸ������ֱ���˳���Ϸ
int ChallengeLevel()
{
	int nSelect = 0;             //����ѡ��Ĳ�������
	int oVer = 1;                //���ñ�־���Է���������˳�����
	while (oVer)                 //ʹ��ѭ������Ϊ���뱾���û�������һ�������Ĺ���
	{
		ChallengeShow();         //��սˮƽ������ʾ
		scanf_s("%d", &nSelect); //��������ѡ��Ĳ������ñ���
		switch (nSelect)
		{
			break;
		case 1:                  //������Ϸ
		{
			system("cls");
			Choice();
		}
		break;
		case 2:                  //�����Ѷ�
		{
			system("cls");
			MapInitialization();
			DrawMap();
			Random_Obstacles(3);
			speed = 300;
			StartGame();
		}
		break;
		case 3:                  //�м��Ѷ�
		{
			system("cls");
			MapInitialization();
			DrawMap();
			Random_Obstacles(5);
			speed = 250;
			StartGame();
		}
		break;
		case 4:                 //�߼��Ѷ�
		{
			system("cls");
			MapInitialization();
			DrawMap();
			Random_Obstacles(8);
			speed = 200;
			StartGame();
		}
		break;
		case 5:               //�������ص�������
		{
			flaglevel = 1;
			MapInitialization();
			oVer = 0;
		}
		system("pause");
		break;
		}
		system("cls");       //����һ�����������û�����������ѡ��
	}

	Sleep(100);
	return 0;
}