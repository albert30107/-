#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void game(int);//�C���i��
void start(void);
int Max, maxnow, minnow=0;
int boom;

void startgame(void) {
	int num;
	printf("���Uenter�}�l�C��\n");
	getchar();
	if (getchar() == '\n') {
		printf("��J�Ʀr\n");
		scanf("%d", &num);
		game(num);
	}
}
void game(int num) {
	printf("boom=%d \n", boom);
	if (num > boom&&num<Max) {
		maxnow = num;
		printf("�d��q%d~%d\n",minnow, maxnow);
		scanf("%d", &num);
		if (num <= minnow || num >= maxnow) {
			printf("�Э��s��J���d�򤺪��Ʀr\n");
			scanf("%d", &num);
		}
		game(num);
	}
	else if (num < boom && num>0) {
		minnow = num;
		printf("�d��q%d~%d\n", minnow,maxnow);
		scanf("%d", &num);
		if (num <= minnow || num >= maxnow) {
			printf("�Э��s��J���d�򤺪��Ʀr\n");
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
	printf("1.�}�l�C�� 2.�����C��\n");
	scanf("%d", &start);
	switch (start)
	{
	case 1:
		printf("��J�̤j��:"); scanf("%d", &Max);
		printf("�d��q0~%d\n", Max);
		boom = (rand() % Max) + 1;
		maxnow = Max;
		startgame();
		break;
	case 2:
		printf("���}\n");
		break;
	default:
		printf("��J���~\n");
		break;
	}
	system("pause");
	return 0;

	
}