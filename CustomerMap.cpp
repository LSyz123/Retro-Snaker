#include <Windows.h>
#include "auxiliary.h"
#include "Snaker.h"
#include "CustomerMap.h"
#include "DrawMap.h"
#include "MapInitialization.h"


int flag = 0;

//�û��Լ��ƶ�����Ϸ��ͼ 
void Customer_Map()
{
	//MapInitialization();//��ͼ��ʼ��
	DrawMap();  //������ͼ
	HindCursor();		//���ع��,ֱ�ӻ�ͼ
	HANDLE InputHandle = GetStdHandle(STD_INPUT_HANDLE);   //��ȡ����̨���뻺�����ľ��
	SetConsoleMode(InputHandle, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); 	//��������¼��Ľ���: ENABLE_MOUSE_INPUT

	DWORD Number = 0;
	INPUT_RECORD InputRecord = { 0 };   //���ڱ����ȡ�����¼�j

	while (ReadConsoleInput(InputHandle, &InputRecord, 1, &Number))
	{
		if (InputRecord.EventType == MOUSE_EVENT)   //���ܵ��¼���ֹ���������,������Ҫ�����ж�
		{
			COORD MouseCoord = InputRecord.Event.MouseEvent.dwMousePosition; 	//��ȡ����������
			CHAR Buffer[0x100] = { 0 };                                         //Ϊ���е�����¼������������Ĵ���
			if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //����¼��зǳ��࣬���ǿ��Ե�����Ӧĳһ���¼�
			{
				if (MouseCoord.Y > Map_X || MouseCoord.X / 2 > Map_Y)//�ж�һ���ǲ������Լ��������ͼ���滭�ϰ���
				{
					continue;
				}
				WriteChar(MouseCoord.Y, MouseCoord.X / 2, 0xF, "��");   //�����������,��ִ������
				g_Map[MouseCoord.Y][MouseCoord.X / 2] = Obstacle;       //�û��������Ķ������ó��ϰ���
			}
			else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				WriteChar(MouseCoord.Y, MouseCoord.X / 2, 0xF, "  ");   //������������ˣ���ִ������
			}
		}
		else if (InputRecord.EventType == KEY_EVENT)                   //�û����Ƶ�ͼ��ɣ�����ݰ��µ�������̽��н�����
		{
			flag = 1;
			
			break;
		}
	}
}
