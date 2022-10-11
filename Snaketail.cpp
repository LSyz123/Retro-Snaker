#include <windows.h>
#include <stdio.h>
#include "Snaketail.h"
#include "Snaker.h"
#include "auxiliary.h"

void Snaketail()
{
	//Çå³ýÉßÎ²
	g_Map[Snake[nLength - 1].X][Snake[nLength - 1].Y] = Open_space;
	WriteChar(Snake[nLength - 1].X, Snake[nLength - 1].Y, 0, "  ");
}

