#pragma once

//地图坐标
#define Map_X 40      
#define Map_Y 40

//标识方向
#define Up    0
#define Down  1
#define Left  2
#define Right 3

//空地，食物，障碍物，自己,毒物
#define Open_space  0
#define Food   1
#define Obstacle  2
#define Self   3
#define Poison 4
#define apple 5
#define Pear 6

#define ESC  27    //返回

extern COORD Snake[100];          //蛇
extern int Dir;	                  //方向默认为右
extern int nLength;               //蛇身最初的原始长度就是4个方块
extern int Dir;	                  //方向默认为右
extern int NewDir;                //读档游戏之后的蛇方向
extern int g_Map[Map_X][Map_Y];   //地图
extern int g_FoodExist;           //初始化的食物是不存在的
extern int g_Poison;              //初始化的毒物是不存在的
extern int score;                 //初始化的分数是0       
extern int speed;                 //开始游戏的速度是300
extern int nLive;                 //蛇的状态

void StartPoint();    //蛇头开始坐标
int MoveSnake();      //蛇移动









