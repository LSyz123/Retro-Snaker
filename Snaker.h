#pragma once

//��ͼ����
#define Map_X 40      
#define Map_Y 40

//��ʶ����
#define Up    0
#define Down  1
#define Left  2
#define Right 3

//�յأ�ʳ��ϰ���Լ�,����
#define Open_space  0
#define Food   1
#define Obstacle  2
#define Self   3
#define Poison 4
#define apple 5
#define Pear 6

#define ESC  27    //����

extern COORD Snake[100];          //��
extern int Dir;	                  //����Ĭ��Ϊ��
extern int nLength;               //���������ԭʼ���Ⱦ���4������
extern int Dir;	                  //����Ĭ��Ϊ��
extern int NewDir;                //������Ϸ֮����߷���
extern int g_Map[Map_X][Map_Y];   //��ͼ
extern int g_FoodExist;           //��ʼ����ʳ���ǲ����ڵ�
extern int g_Poison;              //��ʼ���Ķ����ǲ����ڵ�
extern int score;                 //��ʼ���ķ�����0       
extern int speed;                 //��ʼ��Ϸ���ٶ���300
extern int nLive;                 //�ߵ�״̬

void StartPoint();    //��ͷ��ʼ����
int MoveSnake();      //���ƶ�









