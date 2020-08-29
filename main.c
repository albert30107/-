#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void game(int);//遊戲進行
void start(void);
int Max, maxnow, minnow=0;
int boom;

void startgame(void) {
	int num;
	printf("按下enter開始遊戲\n");
	getchar();
	if (getchar() == '\n') {
		printf("輸入數字\n");
		scanf("%d", &num);
		game(num);
	}
}
void game(int num) {
	printf("boom=%d \n", boom);
	if (num > boom&&num<Max) {
		maxnow = num;
		printf("範圍從%d~%d\n",minnow, maxnow);
		scanf("%d", &num);
		if (num <= minnow || num >= maxnow) {
			printf("請重新輸入位於範圍內的數字\n");
			scanf("%d", &num);
		}
		game(num);
	}
	else if (num < boom && num>0) {
		minnow = num;
		printf("範圍從%d~%d\n", minnow,maxnow);
		scanf("%d", &num);
		if (num <= minnow || num >= maxnow) {
			printf("請重新輸入位於範圍內的數字\n");
			scanf("%d", &num);
		}
		game(num);
	}
	else if (num == boom) {
		printf("Explosion!!!!!!\n");
		int main(void);
	}
	
}
int main(void) {
	srand(time(NULL));
	int start,num;
	printf("1.開始遊戲 2.結束遊戲\n");
	scanf("%d", &start);
	switch (start)
	{
	case 1:
		printf("輸入最大值:"); scanf("%d", &Max);
		printf("範圍從0~%d\n", Max);
		boom = (rand() % Max) + 1;
		maxnow = Max;
		startgame();
		break;
	case 2:
		printf("離開\n");
		break;
	default:
		printf("輸入錯誤\n");
		break;
	}
	system("pause");
	return 0;

	
}