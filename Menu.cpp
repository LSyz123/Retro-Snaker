#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


//游戏的主界面函数
void Menu()
{
	// 设置配色
	system("color 0F");

	printf("**********************************************************************\n");
	printf("*                                                                    *\n");
	printf("*                  Welcome to the snake game world                   *\n");
	printf("*                                                                    *\n");
	printf("*                   1.Start the game                                 *\n");
	printf("*                   2.Challenge level                                *\n");
	printf("*                   3.Continue  game                                 *\n");
	printf("*                   4.Custom Map                                     *\n");
	printf("*                   5.Exit the game                                  *\n");
	printf("*                                                                    *\n");
	printf("**********************************************************************\n");
	printf("Please enter what you want to do:\n");
}

void PrintSave()
{
	// 设置配色
	system("color 0F");
	system("cls");
	printf("Game Saved!\n");   //界面可以根据自己需求进行设计
	system("pause");
}


void PrintDie()
{
	// 设置配色
	system("color 0F");
	system("cls");
	printf("You Died!\n");   //界面可以根据自己需求进行设计
	system("pause");
}
