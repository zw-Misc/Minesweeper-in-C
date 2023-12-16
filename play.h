#pragma once
#include<graphics.h>
#include<windows.h>
#include<pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUM 20
#define NOOB 1
#define PRO 2
#define MASTER 3
#define LIST 9999
typedef struct level
{
	int width;
	int bomb;
	int arec;
}level;
/*����VS��֧�ֱ䳤���飬���ǲ���ȫ�ֱ������εķ�ʽ����ʼ����
   ����ֻ���������������̵�һ����������*/
extern int MINE;
void getBoard(int board[NUM][NUM], int r, int c);
void showBoard(int board[NUM][NUM]);
void dataInit(int board[NUM][NUM]);
int scanPoint(int board[NUM][NUM], int i, int j);

bool inr(int n);
void bombInit(int board[NUM][NUM], int r, int c);
bool inprotect(int x, int y, int r, int c);
//--------------------------------
void gameinit();
int mouseclick();
void open(int r, int c);
void gamedraw();
void judgement();
void game();
void openflag(int r, int c);
void failure();
int minenum();
void delay(double seconds);
void boomstart();
void boomend(int r, int c);
void* gameclock(void* (arg));//��ʱ�̲߳�������
void counter();//��ʱ��
void winner();
void play();// van���Ρ�Ϸ
void button(int x, int y, int width, int height, TCHAR* text);
void startgame();
void selectingmode();
void ranking();
void showlist();