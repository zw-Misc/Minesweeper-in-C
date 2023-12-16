#include "play.h"

//-------------------------头文件
int num;
int MINE;
int A;
int graph;
int choice;
IMAGE initial;
//-------------------------项目全局变量

level noob = { 10,3,30 };
level pro = { 15,40,30 };
level master = { 20,80,30 };
//————————————————————————————难度数据

void button(int x, int y, int width, int height, TCHAR* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(80, 80, 80));
	fillroundrect(x, y, x + width, y + height, 10, 10);
	settextcolor(WHITE);
	settextstyle(20, 10, "楷体");
	int tx = x + (width - textwidth(text)) / 2;
	int ty = y + (height - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}


void startgame()
{
	initgraph(600, 800, NULL);
	setbkcolor(WHITE);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  // 获取屏幕宽度
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);  // 获取屏幕高度
	int windowWidth = 600;
	int windowHeight = 800;
	int x = (screenWidth - windowWidth) / 2;  // 计算窗口左上角的 x 坐标
	int y = (screenHeight - windowHeight) / 2;  // 计算窗口左上角的 y 坐标
	HWND minesweep1 = GetHWnd();
	MoveWindow(minesweep1, x, y, 600, 800, FALSE);  // 创建窗口并指定左上角坐标
	cleardevice();
	loadimage(&initial, "./gameimage/minesweep.png", 600, 400);
	putimage(0, 0, &initial);
	TCHAR noo[50] = "1.简单难度";
	TCHAR nor[50] = "2.正常难度";
	TCHAR har[50] = "3.困难难度";
	TCHAR ex[50] = "退出游戏";
	TCHAR rank[50] = "历史记录";
	button(20, 650, 120, 50, noo);
	button(160, 650, 120, 50, nor);
	button(300, 650, 120, 50, har);
	button(440, 650, 120, 50, ex);
	button(220, 700, 120, 50, rank);
	ExMessage msg{};
	while (true)
	{
		//printf("%3d %3d %3d", msg.x, msg.y, msg.message);//测试行，专门用于检测鼠标坐标和按钮事件msg.message值的一行语句
		//Sleep(100);
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (msg.x >= 20 && msg.x <= 140 && msg.y > 650 && msg.y < 700 && msg.message == WM_LBUTTONDOWN)
			{
				//简单
				choice = 1;
				break;
			}
			if (msg.x >= 160 && msg.x <= 280 && msg.y > 650 && msg.y < 700 && msg.message == WM_LBUTTONDOWN)
			{
				//普通
				choice = 2;
				break;
			}
			if (msg.x >= 300 && msg.x <= 420 && msg.y > 650 && msg.y < 700 && msg.message == WM_LBUTTONDOWN)
			{
				//困难
				choice = 3;
				break;
			}
			if (msg.x >= 440 && msg.x <= 560 && msg.y >= 650 && msg.y <= 700 && msg.message == WM_LBUTTONDOWN)
			{
				//退出
				_exit(0);
				break;
			}
			if (msg.x >= 220 && msg.x <= 340 && msg.y > 700 && msg.y < 750 && msg.message == WM_LBUTTONDOWN)
			{
				//排行榜
				showlist();
			}
		}
	}
	return;
}

void selectingmode()
{
	while (114514 != 1919810)
	{
		if (choice == NOOB)
		{
			num = noob.width;
			MINE = noob.bomb;
			A = noob.arec;
			graph = num * A;
			break;
		}
		else if (choice == PRO)
		{
			num = pro.width;
			MINE = pro.bomb;
			A = pro.arec;
			graph = num * A;
			break;
		}
		else if (choice == MASTER)
		{
			num = master.width;
			MINE = master.bomb;
			A = master.arec;
			graph = num * A;
			break;
		}
		else
		{
			exit(0);
		}
	}
}

int main() {
	srand((unsigned)time(NULL));//primer
	//puts("Which do you want to choose?\n1.noob\n2.pro\n3.master\n4.molecular");

	startgame();
	selectingmode();
	play();
	//启动连招
	return 0;
}