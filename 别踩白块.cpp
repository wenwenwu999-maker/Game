/*
要修改字符集
*/
#include <stdio.h>
#include<graphics.h>
#include<time.h>
#include<easyx.h>
#include<conio.h>
#define k 5
int arr [k] ;
int X;
int Y;
int score = 0;
void black()
{
	for (int y = 0; y < 4; y++)
	{
		arr[y] = rand()%4;//0~4
	}
}
void drawblack()
{
	for (int u = 0; u<5; u++)
	{
		fillrectangle(arr[u] * 100, u * 120, (arr[u] + 1) * 100, u * 120 + 120);
	}
}
bool play()
{
	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				X = msg.x / 100;
				Y = msg.y / 120;
				if (X == arr[3] && Y == 3)
				{
					for (int h = 3; h > 0; h--)
					{
						arr[h] = arr[h - 1];
					}
					arr[0] = rand() % 4;
					score += 1;
				}
				else 
				{
					return 1;
				}
				break;
			}
			return 0;
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	black();
	initgraph(500, 480,SHOWCONSOLE);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();
		setlinecolor(BLACK);
		setfillcolor(WHITE);
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				fillrectangle(i * 100, j * 120, i * 100 + 100, j * 120 + 120);
			}
		}
		setfillcolor(BLACK);
		drawblack();
		EndBatchDraw();
		if (play())
		{
			char str[1000];
			sprintf_s(str, "总分为:%d", score, score);
			MessageBox(GetHWnd(), str, "Game Over", MB_OK);
			exit(0);
		}
	}

	getchar();
	return 0;
}
