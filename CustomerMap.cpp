#include <Windows.h>
#include "auxiliary.h"
#include "Snaker.h"
#include "CustomerMap.h"
#include "DrawMap.h"
#include "MapInitialization.h"


int flag = 0;

//用户自己制定的游戏地图 
void Customer_Map()
{
	//MapInitialization();//地图初始化
	DrawMap();  //画出地图
	HindCursor();		//隐藏光标,直接画图
	HANDLE InputHandle = GetStdHandle(STD_INPUT_HANDLE);   //获取控制台输入缓冲区的句柄
	SetConsoleMode(InputHandle, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); 	//开启鼠标事件的接受: ENABLE_MOUSE_INPUT

	DWORD Number = 0;
	INPUT_RECORD InputRecord = { 0 };   //用于保存读取到的事件j

	while (ReadConsoleInput(InputHandle, &InputRecord, 1, &Number))
	{
		if (InputRecord.EventType == MOUSE_EVENT)   //接受的事件不止有鼠标类型,所以需要进行判断
		{
			COORD MouseCoord = InputRecord.Event.MouseEvent.dwMousePosition; 	//获取到鼠标的坐标
			CHAR Buffer[0x100] = { 0 };                                         //为所有的鼠标事件进行输出坐标的处理
			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //鼠标事件有非常多，我们可以单独响应某一个事件
			{
				if (MouseCoord.Y > Map_X || MouseCoord.X / 2 > Map_Y)//判断一下是不是在自己本身定义的图里面画障碍物
				{
					continue;
				}
				WriteChar(MouseCoord.Y, MouseCoord.X / 2, 0xF, "●");   //鼠标的左键按下,就执行这里
				g_Map[MouseCoord.Y][MouseCoord.X / 2] = Obstacle;       //用户画出来的东西设置成障碍物
			}
			else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				WriteChar(MouseCoord.Y, MouseCoord.X / 2, 0xF, "  ");   //鼠标的左键按下了，就执行这里
			}
		}
		else if (InputRecord.EventType == KEY_EVENT)                   //用户绘制地图完成，则根据按下的任意键盘进行结束。
		{
			flag = 1;
			
			break;
		}
	}
}
