#include <Windows.h>
#include"Snakehead.h"
#include "Snaker.h"
#include "auxiliary.h"

void Snakehead()
{
	//������ͷ
	g_Map[Snake[0].X][Snake[0].Y] = Self;   //������ͷ
	WriteChar(Snake[0].X, Snake[0].Y, FOREGROUND_RED, "��");
}