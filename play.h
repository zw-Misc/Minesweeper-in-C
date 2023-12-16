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
/*由于VS不支持变长数组，我们采用全局变量传参的方式来初始化，
   并且只利用最大情况下棋盘的一部分来传参*/
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
void* gameclock(void* (arg));//计时线程参数函数
void counter();//计时器
void winner();
void play();// van♂游♂戏
void button(int x, int y, int width, int height, TCHAR* text);
void startgame();
void selectingmode();
void ranking();
void showlist();