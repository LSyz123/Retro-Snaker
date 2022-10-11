#include <Windows.h>
#include <stdio.h>

#include "Archive Game option.h"
#include "Archive reading.h"
#include "Archive Save.h"
#include "auxiliary.h"
#include "CustomerMap.h"
#include "DrawMap.h"
#include "Food.h"
#include "Menu.h"
#include "Poison.h"
#include "Random_Obstacles.h"
#include "Snaker.h"
#include "StartGame.h"
#include "User operation.h"
#include "ChallengeShow.h"
#include "Challengelevel.h"
#include "MapInitialization.h"


//������
int main(int* argc, char* argv[])
{
	system("title  Retro Snaker");
	Music();
	English();
	MapInitialization();//��ͼ��ʼ��
	int nSelect = 0;              //����ѡ��Ĳ�������
	int oVer = 1;                 //���ñ�־���Է���������˳�����
	while (oVer)                  //ʹ��ѭ������Ϊ���뱾���û�������һ�������Ĺ���
	{
		Menu();                   //�����溯��
		scanf_s("%d", &nSelect);  //��������ѡ��Ĳ������ñ���
		switch (nSelect)
		{
			case 1:                 //Start Game Function 
			{
				speed = 500;
				StartGame();
			}
			break;
			case 2:                 //Start Game Function 
			{
				system("cls");
				ChallengeLevel();
			}
			break;
			case 3:                //Continue with the last game
			{
				system("cls");
				Choice();         //�����ǿ�ʼ��Ϸ���Ǽ�����Ϸ

			}
			break;
			case 4:            	    //Customer Map
			{
				system("cls");
				Customer_Map();
			}
			break;
			case 5:                //Exit Procedure
			{
				oVer = 0;        
			}
			break;
			system("pause");
			break;
			}
			system("cls");        //����һ�����������û�����������ѡ��
		}
	return 0;
}

