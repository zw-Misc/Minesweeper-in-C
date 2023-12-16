#pragma warning (disable:4996)
#include "play.h"//ʲô���߰���ĺꡢͷ�ļ�ȫ��main.h����ģ�MINE��BoardInit.h�����
//#define MINE 80//����������
//#define num 20//һ��ͼƬ����
//-------------------------------------------------------������ȫ�ֱ���
int start = 0;//�����û�е��
int timerrun = 0;
bool inopenflag = false;
int i, j, flag;
int cnt;
int curt;//��Ϸʱ��
extern int num;
extern int MINE;
extern int A;
extern int graph;
extern int choice;
extern level noob;
extern level pro;
extern level master;
char buf[11][32] = { 0 };
int map[NUM][NUM];//���׵�ͼȫ������
pthread_t GameClock;//��ʱ���̴߳���ȫ�ֱ���
//����Ժ���ʲô�������¿�����дһ���߳�ȫ�̷ű������ֳ���������ʦ��bushi��
//����pthread.h�ļ���ַ��https://blog.csdn.net/weixin_54730871/article/details/131387382
//-------------------------------------------------------�����ǵȼ����ݽṹ��ԭ��

//--------------------------------------------------------������ͼƬ��Դ�ļ�
IMAGE gameimg[23];
IMAGE numimg[10];
//--------------------------------------------------------�����Ǵ�������
void play()
{
	char tmp[20] = { 0 };
	for (int s = 0; s < 23; s++)
	{
		sprintf_s(tmp, "./gameimage/%d.png", s);
		loadimage(&gameimg[s], tmp, A, A);//����ƽ��ͼƬ
	}
	for (int t = 0; t < 10; ++t) {
		sprintf_s(tmp, "./numimage/%d.png", t);
		loadimage(&numimg[t], tmp, 36, 60);//��������ͼƬ
	}
	initgraph(graph, graph * 3 / 2);
	setbkcolor(WHITE);
	setcolor(WHITE);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);  // ��ȡ��Ļ���
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);  // ��ȡ��Ļ�߶�
	int windowWidth = graph + 15;
	int windowHeight = graph * 3 / 2;
	int x = (screenWidth - windowWidth) / 2;  // ���㴰�����Ͻǵ� x ����
	int y = (screenHeight - windowHeight) / 2;  // ���㴰�����Ͻǵ� y ����
	HWND minesweep1 = GetHWnd();
	MoveWindow(minesweep1, x, y, graph + 15, graph * 3 / 2, FALSE);  // �������ڲ�ָ�����Ͻ�����
	cleardevice();
	game();
	closegraph();
	return;
}

void game()
{

	gameinit();
	while (1)
	{
		cnt = MINE;
		counter();
		judgement();
	}
}

void gameinit()
{
	start = 0;
	settextcolor(BLACK);
	outtextxy(graph / 4 * 1 - 28, graph / 12 * 13 + 70, "Counter");
	settextcolor(BLACK);
	outtextxy(graph / 4 * 3 - 21, graph / 12 * 13 + 70, "Timer");
	putimage(graph / 4 * 1 - 54, graph / 12 * 13, &numimg[MINE / 100]);
	putimage(graph / 4 * 1 - 18, graph / 12 * 13, &numimg[(MINE % 100) / 10]);
	putimage(graph / 4 * 1 + 18, graph / 12 * 13, &numimg[MINE % 10]);
	putimage(graph / 4 * 3 - 54, graph / 12 * 13, &numimg[0]);
	putimage(graph / 4 * 3 - 18, graph / 12 * 13, &numimg[0]);
	putimage(graph / 4 * 3 + 18, graph / 12 * 13, &numimg[0]);
	for (int i = 0; i < NUM; ++i) {
		for (int j = 0; j < NUM; ++j) {
			map[i][j] = 0;
		}
	}
	boomstart();
	gamedraw();
}

void gamedraw()
{
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (map[i][j] == -1)//-------- ����  ����mapֵ
			{
				putimage(j * A, i * A, &gameimg[9]);
			}
			else if (map[i][j] >= 0 && map[i][j] <= 8)//--------���� ����mapֵ
			{
				putimage(j * A, i * A, &gameimg[map[i][j]]);
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28 || map[i][j] == 1000)//--------���������� ����mapֵ
			{
				putimage(j * A, i * A, &gameimg[10]);
			}
			else if (map[i][j] >= 39 && map[i][j] <= 48) {////--------���������� ����mapֵ
				putimage(j * A, i * A, &gameimg[11]);
			}
			else if (map[i][j] >= 59 && map[i][j] <= 68) {////--------�ʺŸ������� ����mapֵ
				putimage(j * A, i * A, &gameimg[12]);
			}
			else if (map[i][j] == -9)//�Լ����ֵ��е���-------����mapֵ
			{
				putimage(j * A, i * A, &gameimg[13]);
			}
			else if (map[i][j] == -5) {//�������-------����mapֵ
				putimage(j * A, i * A, &gameimg[14]);
			}
			else if (map[i][j] >= 99 && map[i][j] <= 108 || map[i][j] == 1006) {
				putimage(j * A, i * A, &gameimg[15]);
			}
			else if (map[i][j] >= 119 && map[i][j] <= 128) {
				putimage(j * A, i * A, &gameimg[16]);
			}
			else if (map[i][j] >= 139 && map[i][j] <= 148) {
				putimage(j * A, i * A, &gameimg[17]);
			}
			else if (map[i][j] == 1001) {
				putimage(j * A, i * A, &gameimg[18]);
			}
			else if (map[i][j] == 1002) {
				putimage(j * A, i * A, &gameimg[19]);
			}
			else if (map[i][j] == 1003) {
				putimage(j * A, i * A, &gameimg[20]);
			}
			else if (map[i][j] == 1004) {
				putimage(j * A, i * A, &gameimg[21]);
			}
			else if (map[i][j] == 1005) {
				putimage(j * A, i * A, &gameimg[22]);
			}
		}
	}
}

int mouseclick()
{
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (msg.x >= num * A || msg.x <= 0 || msg.y <= 0 || msg.y >= num * A) {
			return 0;
		}
		int r = msg.y / A;
		int c = msg.x / A;
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				if (map[i][j] >= 99)
				{
					map[i][j] -= 80;
				}
			}
		}
		if (map[r][c] >= 19 && map[r][c] <= 28)
		{
			map[r][c] += 80;
		}
		if (map[r][c] >= 39 && map[r][c] <= 48)
		{
			map[r][c] += 80;
		}
		if (map[r][c] >= 59 && map[r][c] <= 68)
		{
			map[r][c] += 80;
		}
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN://������
			if (start == 0) {
				if (timerrun == 0)
				{
					pthread_create(&GameClock, NULL, gameclock, NULL);
					//���˵�һ��֮��ʼ��ʱ�������߳�
					timerrun = 114514;//������ʱ�̣߳����Ե�һ�ε����ʵ������
				}
				getBoard(map, r, c);
				start += 114514;
			}
			if (map[r][c] >= 19 && map[r][c] <= 28)
			{
				map[r][c] += 80;
			}
			if (map[r][c] >= 39 && map[r][c] <= 48)
			{
				map[r][c] += 80;
			}
			if (map[r][c] >= 59 && map[r][c] <= 68)
			{
				map[r][c] += 80;
			}
			if (map[r][c] >= 99 && map[r][c] <= 108)
			{
				map[r][c] -= 100;
				++cnt;
				open(r, c);
			}
			break;

		case WM_RBUTTONDOWN://�Ҽ����
			if (map[r][c] >= 99 && map[r][c] <= 108 && start != 0)//ǳ���ո�
			{
				map[r][c] -= 60;//��Ϊ��ɫ����
			}
			else if (map[r][c] >= 119 && map[r][c] <= 128)//ǳ��ɫ����
			{
				map[r][c] -= 60;
			}
			else if (map[r][c] >= 139 && map[r][c] <= 148) //�ʺ�
			{
				map[r][c] -= 120;
			}
			else if (map[r][c] >= 0 && map[r][c] < 9)
			{
				openflag(r, c);
			}
			break;
		}
		return map[r][c];
	}
	return 0;
}

void judgement()//�����ж���Ϸ�Ƿ����
{
	gamedraw();
	bool isfailure = false;//����openflag���ж����õĶ������
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			if (map[i][j] == -1) {
				isfailure = true;
				break;
			}
		}
	}
	if (mouseclick() == -1 || isfailure)//����ֵ-1��˵�����ף�������Ϸʧ��
	{
		if (timerrun != 0)
		{
			timerrun = 0;
		}//ֹͣ��ʱ�߳�, ע�⣺�ò������������ȼ����κκ�Ӵ��벻��������ǰ
		failure();//�¼ӵ�Ч��
	}
	else if (minenum() == MINE)
	{
		if (timerrun != 0)
		{
			timerrun = 0;
		}//ֹͣ��ʱ�߳�, ע�⣺�ò������������ȼ����κκ�Ӵ��벻��������ǰ
		gamedraw();
		winner();
		ranking();
		int isok = MessageBox(GetHWnd(), "BRIILANT! You won the game!\nOne time more?", "Notice", MB_OKCANCEL);
		if (isok == IDOK)
		{
			game();//����д����gameinit���������½�һ��game()��������ִ����Ϸ����������--23.12.01
		}
		else {
			startgame();
			selectingmode();
			play();
		}
	}
}

void open(int r, int c)
{
	if (map[r][c] == 0)
	{
		for (int m = r - 1; m <= r + 1; m++)
		{
			for (int n = c - 1; n <= c + 1; n++)
			{
				if (m >= 0 && m < num && n >= 0 && n < num)
				{
					if (map[m][n] >= 20 && map[m][n] <= 28)
					{
						map[m][n] -= 20;
						open(m, n);
					}
				}
			}
		}
	}
	else if (map[r][c] >= 20 && map[r][c] <= 28) {
		map[r][c] -= 20;
		++cnt;
	}
}

void openflag(int r, int c) {
	inopenflag = true;
	int count = 0;
	for (int i = r - 1; i <= r + 1; i++) {
		for (int j = c - 1; j <= c + 1; j++)
		{
			if (i >= 0 && i < num && j >= 0 && j < num)
			{
				if (map[i][j] >= 39 && map[i][j] <= 48) {
					count++;
				}
			}
			else {
				continue;
			}
		}
	}
	if (count == map[r][c])
	{
		for (int i = r - 1; i <= r + 1; i++)
			for (int j = c - 1; j <= c + 1; j++)
			{
				if (i >= 0 && i < num && j >= 0 && j < num)
				{
					if (map[i][j] >= 19 && map[i][j] <= 28) {
						map[i][j] -= 20; ++cnt;
					}
					open(i, j);
				}

			}
	}
	inopenflag = false;
}

void failure() {
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			if (map[i][j] == -1 && !inopenflag)
			{
				map[i][j] = -9;
			}
			else if (map[i][j] >= 40 && map[i][j] <= 48)
			{
				map[i][j] = -5;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (map[i][j] == -9)
			{
				boomend(i, j);
			}
		}
	}
	gamedraw();
	int isok = MessageBox(GetHWnd(), "Oops! You clicked on the boom!\nWould you want to play again?", "Notice", MB_OKCANCEL);
	if (isok == IDOK)
	{
		game();//����д����gameinit���������½�һ��game()��������ִ����Ϸ����������--23.12.01
	}
	else
	{
		startgame();
		selectingmode();
		play();
	}
}

void winner()
{
	for (int m = num - 1; m >= -6; m--)
	{
		for (int n = 0; n < num; n++)
		{
			if (m >= 0) {
				map[m][n] = 1006;
			}
			if (m + 1 < num && m + 1 >= 0) {
				map[m + 1][n] = 1005;
			}
			if (m + 2 < num && m + 2 >= 0) {
				map[m + 2][n] = 1004;
			}
			if (m + 3 < num && m + 3 >= 0) {
				map[m + 3][n] = 1003;
			}
			if (m + 4 < num && m + 4 >= 0) {
				map[m + 4][n] = 1002;
			}
			if (m + 5 < num && m + 5 >= 0) {
				map[m + 5][n] = 1001;
			}
			if (m + 6 < num) {
				map[m + 6][n] = 1000;
			}
		}
		gamedraw();
		delay(0.1);
	}
}

int minenum()
{
	int minecounter = 0;
	for (int r = 0; r < num; r++)
	{
		for (int c = 0; c < num; c++) {
			if (map[r][c] >= 19)
			{
				minecounter++;
			}
		}
	}
	return minecounter;
}

void delay(double seconds)
{
	double start = clock();
	double lay = (double)seconds * CLOCKS_PER_SEC;
	while ((clock() - start) < lay);
}

void boomstart()
{
	int x = 0, r = num / 2, c = num / 2;
	while (x <= sqrt(max(num - r, r) * max(num - r, r) + max(num - c, c) * max(num - c, c)) + 1) {
		for (i = r - x; i <= r + x; i++)
		{
			for (j = c - x; j <= c + x; j++)
			{
				if (i >= 0 && i < num && j >= 0 && j < num)
				{
					if (sqrt((i - r) * (i - r) + (j - c) * (j - c)) <= x + 0.5 && sqrt((i - r) * (i - r) + (j - c) * (j - c)) >= x - 0.5 && map[i][j] == 0)
					{//��Բ����
						map[i][j] += 100;
					}
					else if (sqrt((i - r) * (i - r) + (j - c) * (j - c)) <= x + 0.5 && map[i][j] == 100)
					{//��Բ����
						map[i][j] -= 80;
					}
				}
			}
		}
		gamedraw();
		delay(0.1);
		x++;//�Ӱ뾶
	}
	flushmessage();
}

void boomend(int r, int c)
{
	int x = 0;
	while (x <= sqrt(max(num - r, r) * max(num - r, r) + max(num - c, c) * max(num - c, c)) + 1) {
		for (i = r - x; i <= r + x; i++)
		{
			for (j = c - x; j <= c + x; j++)
			{
				if (i >= 0 && i < num && j >= 0 && j < num)
				{
					if (sqrt((i - r) * (i - r) + (j - c) * (j - c)) <= x + 0.5 && sqrt((i - r) * (i - r) + (j - c) * (j - c)) >= x - 0.5)
					{
						if (map[i][j] > 19 && map[i][j] <= 28)
						{
							map[i][j] += 80;
						}
						if (map[i][j] >= 39 && map[i][j] <= 48)
						{
							map[i][j] += 80;
						}
						if (map[i][j] >= 59 && map[i][j] <= 68)
						{
							map[i][j] += 80;
						}
						if (map[i][j] == 19)
						{
							map[i][j] = -1;
						}
					}
				}
			}
		}
		gamedraw();
		for (i = r - x; i <= r + x; i++)
		{
			for (j = c - x; j <= c + x; j++)
			{
				if (i >= 0 && i < num && j >= 0 && j < num)
				{
					if (map[i][j] >= 100 && map[i][j] <= 148)
					{
						map[i][j] -= 80;
					}
				}
			}
		}
		delay(0.08);
		x++;
	}
}

void counter()//������
{
	char tmp[20] = { 0 };
	for (int r = 0; r < num; r++)
	{
		for (int c = 0; c < num; c++)
		{
			if ((map[r][c] >= 39 && map[r][c] <= 48) || (map[r][c] >= 119 && map[r][c] <= 128))
			{
				cnt = cnt - 1;
			}
		}
	}
	putimage(graph / 4 * 1 - 54, graph / 12 * 13, &numimg[cnt / 100]);
	putimage(graph / 4 * 1 - 18, graph / 12 * 13, &numimg[(cnt % 100) / 10]);
	putimage(graph / 4 * 1 + 18, graph / 12 * 13, &numimg[cnt % 10]);
	//printf("%3d", cnt);
	//Sleep(1000);
}

void* gameclock(void* (arg)) {//��ʱ���̲߳�������
	curt = 0;
	while (timerrun) {
		Sleep(1000);
		++curt;
		//printf("You played the game for %d seconds\n",curt);//�̲߳��Դ���
		int a = 0;//��λ
		int b = 0;//ʮλ
		int c = 0;//��λ     //curt����999ֱ�ӹ��� :)
		if (curt <= 999) {
			a = curt / 100;
			b = (curt - a * 100) / 10;
			c = curt - a * 100 - b * 10;
			//��ȡ��λ��
			putimage(graph / 4 * 3 - 54, graph / 12 * 13, &numimg[a]);
			putimage(graph / 4 * 3 - 18, graph / 12 * 13, &numimg[b]);
			putimage(graph / 4 * 3 + 18, graph / 12 * 13, &numimg[c]);
			//��ʾ
		}
	}
	pthread_exit(NULL);//�߳̾͵��˽�����
	return NULL;
}

void ranking()
{
	int i;
	char str[7];                     //Ҫ���������
	int min = curt / 60;
	int sec = curt % 60;
	if (min < 10 && min>0) {
		str[0] = '0';
		_itoa(min * 100 + sec, str + 1, 10);
	}
	else if (min == 0) {
		str[0] = str[1] = '0';
		if (sec > 10)
			_itoa(sec, str + 2, 10);
		else {
			str[2] = '0';
			_itoa(sec, str + 3, 10);
		}
	}
	else {
		_itoa(min * 100 + sec, str, 10);
	}
	str[4] = str[3];
	str[3] = str[2];
	str[2] = ':';
	str[5] = '\n';
	str[6] = '\0';
	FILE* fp = NULL;
	if (choice == NOOB)
	{
		fp = fopen("./ranking/ranknoob.txt", "r");
	}
	if (choice == PRO)
	{
		fp = fopen("./ranking/ranknormal.txt", "r");//�����޸����ļ���������
	}
	if (choice == MASTER)
	{
		fp = fopen("./ranking/rankmaster.txt", "r");
	}
	//����ʽ���ļ���
	for (i = 0; i < 10; i++)
	{
		fgets(buf[i], 32, fp);
	}
	fclose(fp);
	int x = 0;
	for (int j = 0; j < 10; j++)
	{
		if (strcmp(buf[j], str) <= 0)
			x = j;
		if (j == 0 && strcmp(buf[j], str) >= 0)
			x = -1;
	}
	for (i = 9; i >= x + 1; i--)                    //ɾ����2��
	{
		strcpy(buf[i + 1], buf[i]);
	}
	strcpy(buf[x + 1], str);                    //���뵽��x+1�С�
	if (choice == NOOB)
	{
		fp = fopen("./ranking/ranknoob.txt", "w");
	}
	if (choice == PRO)
	{
		fp = fopen("./ranking/ranknormal.txt", "w");
	}
	if (choice == MASTER)
		fp = fopen("./ranking/rankmaster.txt", "w");               //д��ʽ���ļ���
	for (i = 0; i < 10; i++)
	{
		fputs(buf[i], fp);
	}

	fclose(fp);//�ر��ļ���
	fflush(fp);
	fp = NULL;
	if (choice == NOOB)
		fp = fopen("./ranking/ranknoob.txt", "r");
	if (choice == PRO)
		fp = fopen("./ranking/ranknormal.txt", "r");
	if (choice == MASTER)
		fp = fopen("./ranking/rankmaster.txt", "r");            //д��ʽ���ļ���
	for (i = 0; i < 10; i++)
	{
		fgets(buf[i], 32, fp);
	}
	fclose(fp);
	return;
}

void showlist()
{
	ExMessage msg{};

	TCHAR back[50] = "����������";
	char listnoob [11][32] = {0};
	char listnormal[11][32] = {0};
	char listmaster[11][32] = {0};
	FILE* flistnoob = NULL;
	FILE* flistnormal = NULL;
	FILE* flistmaster = NULL;

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

	flistnoob = fopen("./ranking/ranknoob.txt", "r");
	flistnormal = fopen("./ranking/ranknormal.txt", "r");
	flistmaster = fopen("./ranking/rankmaster.txt", "r");
	/*fread(listnoob, sizeof(char), sizeof(listnoob), flistnoob);
	fread(listnormal, sizeof(char), sizeof(listnormal), flistnormal);
	fread(listmaster, sizeof(char), sizeof(listmaster), flistmaster);*/
	for (i = 0; i < 10; i++)
	{
		fgets(listnoob[i], 32, flistnoob);
	}
	for (i = 0; i < 10; i++)
	{
		fgets(listnormal[i], 32, flistnormal);
	}
	for (i = 0; i < 10; i++)
	{
		fgets(listmaster[i], 32, flistmaster);
	}
	settextcolor(BLACK);
	settextstyle(20, 10, "����");
	outtextxy(20, 5, "���Ѷ�:");
	for (int i = 0; i < 11; i++)
	{
		outtextxy(20, 25*i+30, (TCHAR*)listnoob[i]);
	}
	outtextxy(180, 5, "�����Ѷ�:");
	for (int i = 0; i < 11; i++)
	{
		outtextxy(180, 25 * i + 30, (TCHAR*)listnormal[i]);
	}
	outtextxy(350, 5, "�����Ѷ�:");
	for (int i = 0; i < 11; i++)
	{
		outtextxy(350, 25 * i + 30, (TCHAR*)listmaster[i]);
	}
	button(200, 650, 150, 75, back);
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (msg.x >= 200 && msg.x <= 350 && msg.y > 650 && msg.y < 725 && msg.message == WM_LBUTTONDOWN)
			{
				//����
				startgame();
				startgame();
				selectingmode();
				play();
			}
		}
	}
}