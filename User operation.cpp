#include <Windows.h>
#include <conio.h>
#include "Snaker.h"
#include "User operation.h"


//获取用户的输入，修改方向
int GetDir()
{
	if (_kbhit())  //_kbhit()函数用于非阻塞地响应键盘输入事件，游戏本身不能被阻塞，所以使用过的函数不能是阻塞函数
	{
		//这是一个非阻塞函数，一旦按下任何按键，返回 true
		//_getch 是无回显输入，不能使用带回显的函数
		int input = _getch();
		//这里要判断用户输入的方向是否会造成蛇的倒退，蛇不会倒车，只会前进和转弯
		if (input == 'w' || input == 'W')
		{
			if (Dir != Down)
			{
				Dir = Up;
			}
		}
		else if (input == 'a' || input == 'A')
		{
			if (Dir != Right)
			{
				Dir = Left;
			}
		}
		else if (input == 's' || input == 'S')
		{
			if (Dir != Up)
			{
				Dir = Down;
			}
		}
		else if (input == 'd' || input == 'D')
		{
			if (Dir != Left)
			{
				Dir = Right;
			}
		}
		else if (input == ESC)
		{
			return 100;//此处转到存档
		}
		else if (input == ' ')    //使用暂停
		{
			while (TRUE)
			{
				Sleep(100);
				if (_getch() == ' ')
				{
					break;
				}
			}
		}
	}
	return 0;
}
