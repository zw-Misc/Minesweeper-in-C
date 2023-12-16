#include "play.h"

//-------------------------ͷ�ļ�
int num;
int MINE;
int A;
int graph;
int choice;
IMAGE initial;
//-------------------------��Ŀȫ�ֱ���

level noob = { 10,3,30 };
level pro = { 15,40,30 };
level master = { 20,80,30 };
//���������������������������������������������������������Ѷ�����

void button(int x, int y, int width, int height, TCHAR* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(80, 80, 80));
	fillroundrect(x, y, x + width, y + height, 10, 10);
	settextcolor(WHITE);
	settextstyle(20, 10, "����");
	int tx = x + (width - textwidth(text)) / 2;
	int ty = y + (height - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}


void startgame()
{
	initgraph(600, 800, NULL);
	setbkcolor(WHITE);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  // ��ȡ��Ļ���
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);  // ��ȡ��Ļ�߶�
	int windowWidth = 600;
	int windowHeight = 800;
	int x = (screenWidth - windowWidth) / 2;  // ���㴰�����Ͻǵ� x ����
	int y = (screenHeight - windowHeight) / 2;  // ���㴰�����Ͻǵ� y ����
	HWND minesweep1 = GetHWnd();
	MoveWindow(minesweep1, x, y, 600, 800, FALSE);  // �������ڲ�ָ�����Ͻ�����
	cleardevice();
	loadimage(&initial, "./gameimage/minesweep.png", 600, 400);
	putimage(0, 0, &initial);
	TCHAR noo[50] = "1.���Ѷ�";
	TCHAR nor[50] = "2.�����Ѷ�";
	TCHAR har[50] = "3.�����Ѷ�";
	TCHAR ex[50] = "�˳���Ϸ";
	TCHAR rank[50] = "��ʷ��¼";
	button(20, 650, 120, 50, noo);
	button(160, 650, 120, 50, nor);
	button(300, 650, 120, 50, har);
	button(440, 650, 120, 50, ex);
	button(220, 700, 120, 50, rank);
	ExMessage msg{};
	while (true)
	{
		//printf("%3d %3d %3d", msg.x, msg.y, msg.message);//�����У�ר�����ڼ���������Ͱ�ť�¼�msg.messageֵ��һ�����
		//Sleep(100);
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (msg.x >= 20 && msg.x <= 140 && msg.y > 650 && msg.y < 700 && msg.message == WM_LBUTTONDOWN)
			{
				//��
				choice = 1;
				break;
			}
			if (msg.x >= 160 && msg.x <= 280 && msg.y > 650 && msg.y < 700 && msg.message == WM_LBUTTONDOWN)
			{
				//��ͨ
				choice = 2;
				break;
			}
			if (msg.x >= 300 && msg.x <= 420 && msg.y > 650 && msg.y < 700 && msg.message == WM_LBUTTONDOWN)
			{
				//����
				choice = 3;
				break;
			}
			if (msg.x >= 440 && msg.x <= 560 && msg.y >= 650 && msg.y <= 700 && msg.message == WM_LBUTTONDOWN)
			{
				//�˳�
				_exit(0);
				break;
			}
			if (msg.x >= 220 && msg.x <= 340 && msg.y > 700 && msg.y < 750 && msg.message == WM_LBUTTONDOWN)
			{
				//���а�
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
	//��������
	return 0;
}