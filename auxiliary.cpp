#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>             //导入声音头文件
#pragma  comment (lib,"winmm.lib")//导入声音头文件库

#include"auxiliary.h"


//在指定的坐标使用指定的颜色打印指定的字符
void WriteChar(short x, short y, WORD color, const char* s) 
{
	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);  //句柄: 在windwos中句柄用于标识某一种东西，这个例子中，句柄
															//被用于标识当前控制台的输出缓冲区，用于显示具体的内同
	SetConsoleCursorPosition(OutputHandle, { y * 2, x });   //通过函数的调用实现移动光标到指定位置
														    //1: 想要修改的是哪一个输出缓冲区的光标位置
														    //2: 想要将光标移动到控制台的哪一个位置
	SetConsoleTextAttribute(OutputHandle, color); //为接下来需要打印的文字提供颜色
	printf(s);   //打印指定的图形
}

//隐藏光标
void HindCursor()
{
	HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE); /*句柄: 在windwos中句柄用于标识某一种东西，这个例子中，
														   句柄被用于标识当前控制台的输出缓冲区，用于显示具体的内容*/
	CONSOLE_CURSOR_INFO Cursor = { 1, 0 };       //定义结构体，用于保存光标的信息，参数二表示是否显示，此时0代表的是不显示光标
	SetConsoleCursorInfo(OutputHandle, &Cursor); //调用函数设置光标的属性
}

//设置背景音乐
void Music()
{
	PlaySound(L"yanzi.wav", NULL, SND_ASYNC | SND_LOOP);
}

//设置默认输入的是英文输入法函数
void English()
{
	keybd_event(VK_SHIFT, 0, 0, 0);
	Sleep(100);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}
