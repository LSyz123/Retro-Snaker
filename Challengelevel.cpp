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

//重新再来一次 游戏，或者选择等级继续游戏，或者直接退出游戏
int ChallengeLevel()
{
	int nSelect = 0;             //设置选择的操作变量
	int oVer = 1;                //设置标志，以方便后续的退出程序
	while (oVer)                 //使用循环，因为密码本和用户交互是一个持续的过程
	{
		ChallengeShow();         //挑战水平界面显示
		scanf_s("%d", &nSelect); //进行输入选择的操作设置变量
		switch (nSelect)
		{
			break;
		case 1:                  //继续游戏
		{
			system("cls");
			Choice();
		}
		break;
		case 2:                  //初级难度
		{
			system("cls");
			MapInitialization();
			DrawMap();
			Random_Obstacles(3);
			speed = 300;
			StartGame();
		}
		break;
		case 3:                  //中级难度
		{
			system("cls");
			MapInitialization();
			DrawMap();
			Random_Obstacles(5);
			speed = 250;
			StartGame();
		}
		break;
		case 4:                 //高级难度
		{
			system("cls");
			MapInitialization();
			DrawMap();
			Random_Obstacles(8);
			speed = 200;
			StartGame();
		}
		break;
		case 5:               //结束，回到主界面
		{
			flaglevel = 1;
			MapInitialization();
			oVer = 0;
		}
		system("pause");
		break;
		}
		system("cls");       //进行一下清屏，让用户看不到操作选项
	}

	Sleep(100);
	return 0;
}