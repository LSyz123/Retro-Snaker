#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>             //��������ͷ�ļ�
#pragma  comment (lib,"winmm.lib")//��������ͷ�ļ���

#include"auxiliary.h"


//��ָ��������ʹ��ָ������ɫ��ӡָ�����ַ�
void WriteChar(short x, short y, WORD color, const char* s) 
{
	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);  //���: ��windwos�о�����ڱ�ʶĳһ�ֶ�������������У����
															//�����ڱ�ʶ��ǰ����̨�������������������ʾ�������ͬ
	SetConsoleCursorPosition(OutputHandle, { y * 2, x });   //ͨ�������ĵ���ʵ���ƶ���굽ָ��λ��
														    //1: ��Ҫ�޸ĵ�����һ������������Ĺ��λ��
														    //2: ��Ҫ������ƶ�������̨����һ��λ��
	SetConsoleTextAttribute(OutputHandle, color); //Ϊ��������Ҫ��ӡ�������ṩ��ɫ
	printf(s);   //��ӡָ����ͼ��
}

//���ع��
void HindCursor()
{
	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE); /*���: ��windwos�о�����ڱ�ʶĳһ�ֶ�������������У�
														   ��������ڱ�ʶ��ǰ����̨�������������������ʾ���������*/
	CONSOLE_CURSOR_INFO Cursor = { 1, 0 };       //����ṹ�壬���ڱ��������Ϣ����������ʾ�Ƿ���ʾ����ʱ0������ǲ���ʾ���
	SetConsoleCursorInfo(OutputHandle, &Cursor); //���ú������ù�������
}

//���ñ�������
void Music()
{
	PlaySound(L"yanzi.wav", NULL, SND_ASYNC | SND_LOOP);
}

//����Ĭ���������Ӣ�����뷨����
void English()
{
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}
