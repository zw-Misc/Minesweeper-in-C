#include "play.h"
extern int num;
bool inr(int n) {
	if (n >= 0 && n < num) { return true; }//判断一个数是否在棋盘坐标内
	else { return false; }
}

bool inprotect(int x, int y, int r, int c) {
	bool flag = false;
	if (x >= r - 1 && x <= r + 1) {
		if (y >= c - 1 && y <= c + 1) {
			flag = true;
		}
	}
	return flag;
}

void bombInit(int board[NUM][NUM], int r, int c) {//布雷函数
	int x = 0, y = 0;
	for (int i = MINE; i > 0; ) {
		x = (rand() % num); y = (rand() % num);
		if (board[x][y] != -1 && !inprotect(x, y, r, c)) { board[x][y] = -1; --i; }
		else { ; }
	}
	//---------0代表未翻开；1、2、3...、8代表周围几颗雷；-1代表地雷；-------------
	return;
}


int scanPoint(int board[NUM][NUM], int i, int j) {//扫描周边是否有雷的函数
	if (inr(i) && inr(j)) {
		if (board[i][j] == -1) { return 1; }
	}
	else { return 0; }
	return 0;
}

void dataInit(int board[NUM][NUM]) {//重点注意：这个函数在拓展算法时将会复用
	int prev[NUM][NUM];
	for (int i = 0; i < NUM; ++i) {
		for (int j = 0; j < NUM; ++j) {
			prev[i][j] = 0;
		}
	}
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			int res = 0;   //这个变量将会记录周边雷数，并传入prev
			if (board[i][j] == -1) { res = -1; }
			else {
				res = scanPoint(board, i - 1, j - 1) + scanPoint(board, i - 1, j) +
					scanPoint(board, i - 1, j + 1) + scanPoint(board, i, j - 1)
					+ scanPoint(board, i, j + 1) + scanPoint(board, i + 1, j - 1)
					+ scanPoint(board, i + 1, j) + scanPoint(board, i + 1, j + 1);
			}
			prev[i][j] = res + 20;
		}
	}
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			board[i][j] = prev[i][j];
		}
	}
}

void showBoard(int board[NUM][NUM]) {//输出棋盘
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) { printf("%2d  ", board[i][j]); }
		printf("\n");
	}
	return;
}

void getBoard(int board[NUM][NUM], int r, int c) {//自带输出，小子！

	for (int i = 0; i < NUM; ++i) {
		for (int j = 0; j < NUM; ++j) {
			board[i][j] = 0;
		}
	}//初始化
	bombInit(board, r, c);
	dataInit(board);
	showBoard(board);
	return;
}