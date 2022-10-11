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


//主函数
int main(int* argc, char* argv[])
{
	system("title  Retro Snaker");
	Music();
	English();
	MapInitialization();//地图初始化
	int nSelect = 0;              //设置选择的操作变量
	int oVer = 1;                 //设置标志，以方便后续的退出程序
	while (oVer)                  //使用循环，因为密码本和用户交互是一个持续的过程
	{
		Menu();                   //主界面函数
		scanf_s("%d", &nSelect);  //进行输入选择的操作设置变量
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
				Choice();         //决定是开始游戏还是继续游戏

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
			system("cls");        //进行一下清屏，让用户看不到操作选项
		}
	return 0;
}

