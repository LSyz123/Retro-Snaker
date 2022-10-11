#include <Windows.h>
#include"Snakehead.h"
#include "Snaker.h"
#include "auxiliary.h"

void Snakehead()
{
	//画出蛇头
	g_Map[Snake[0].X][Snake[0].Y] = Self;   //画出蛇头
	WriteChar(Snake[0].X, Snake[0].Y, FOREGROUND_RED, "■");
}