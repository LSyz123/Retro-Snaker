#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


//��Ϸ�������溯��
void Menu()
{
	// ������ɫ
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
	// ������ɫ
	system("color 0F");
	system("cls");
	printf("Game Saved!\n");   //������Ը����Լ�����������
	system("pause");
}


void PrintDie()
{
	// ������ɫ
	system("color 0F");
	system("cls");
	printf("You Died!\n");   //������Ը����Լ�����������
	system("pause");
}
