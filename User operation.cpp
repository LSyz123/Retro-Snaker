#include <Windows.h>
#include <conio.h>
#include "Snaker.h"
#include "User operation.h"


//��ȡ�û������룬�޸ķ���
int GetDir()
{
	if (_kbhit())  //_kbhit()�������ڷ���������Ӧ���������¼�����Ϸ�����ܱ�����������ʹ�ù��ĺ�����������������
	{
		//����һ��������������һ�������κΰ��������� true
		//_getch ���޻������룬����ʹ�ô����Եĺ���
		int input = _getch();
		//����Ҫ�ж��û�����ķ����Ƿ������ߵĵ��ˣ��߲��ᵹ����ֻ��ǰ����ת��
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
			return 100;//�˴�ת���浵
		}
		else if (input == ' ')    //ʹ����ͣ
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
