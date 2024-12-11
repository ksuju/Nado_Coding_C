#include <stdio.h>	// printf 등
#include <time.h>	// 시간 관련 함수를 사용하기 위함
#include <stdlib.h>	// exit() 함수를 사용하기 위함

int level;	 // 전역변수 선언, 레벨
int arrayFish[6];	// 어항
int num;	// 물을 줄 어항 번호
long totalElapsedTime = 0;	// 총 경과 시간
long prevElapsedTime = 0;	// 직전에 물을 준 시간 (물을 준 시간 간격)
int* cursor;	// 어항 배열에 접근할 포인터 변수


void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();
int main(void) {
	long startTime = 0;	// 게임 시작 시간을 담을 변수 선언 및 초기화
	initData();	// 게임 초기화 함수 호출
	startTime = clock();	// 프로그램 수행 이후 현재까지 흐른 시간을 "시작 시간" 으로 설정
	cursor = arrayFish;	// 포인터 변수에 어항 배열의 시작 주소 넣기

	while (1) {
		printfFishes();
		printf("몇 번 어항에 물을 줄까요? (1~6) ");
		scanf_s("%d", &num);

		// validation
		if (num < 1 || num > 6) {
			printf("\n입력값이 잘못됐습니다.\n");
			continue;
		}
		
		// 총 경과 시간, 초 단위로 표시
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;

		printf("총 경과 시간 : %ld초\n", totalElapsedTime);

		prevElapsedTime = totalElapsedTime - prevElapsedTime;	// 직전에 물을 준 이후로 흐른 시간

		printf("최근 경과 시간 : %ld초\n", prevElapsedTime);

		decreaseWater(prevElapsedTime);	// 어항의 물을 증발시키는 함수 호출

		if (cursor[num - 1] <= 0) {	// 조건 1. 어항의 물 높이가 0 이하
			printf("%d번 어항의 물고기는 이미 죽었습니다, 물을 주지 않습니다.\n", num);
		}
		else if (cursor[num - 1] + 1 <= 100) {	// 조건 2. 어항의 물 높이가 0보다 큼
			printf("%d번 어항에 물을 줍니다.\n\n", num);
			// 물을 주면 물 높이 + 10, (cursor[num-1] (물 높이) = cursor[num - 1] + 10 (물 높이 + 10))
			cursor[num - 1] += 10;
		}

		if (totalElapsedTime / 20 > level - 1) {	// 레벨업 확인 (20초마다)
			level++;	// 레벨업
			printf("*** 축하합니다. %d레벨에서 %d레벨로 올랐습니다. ***\n\n", level - 1, level);

			if (level == 5) {	// 최고 레벨에 도달하면, 게임 종료
				printf("*** 축하합니다! 최고 레벨에 도달했습니다. 게임을 종료합니다. *** \n\n");
				exit(0);
			}
		}

		if (checkFishAlive() == 0) {	// 모든 물고기가 죽었는지 확인
			printf("모든 물고기가 죽었습니다.. ㅠㅠ \n\n");
			exit(0);
		}
		else {	// 최소 한마리의 물고기가 살아있음
			printf("살아 있는 물고기가 있습니다!\n\n");
		}

		// 물 증발 계산 시 정확한 시간 간격을 유지하기 위한 코드 "prevElapsedTime 최신화"
		// 해주지 않으면? 물이 점점 기하급수적으로 빨리 줄어들음
		prevElapsedTime = totalElapsedTime;
	}

	return 0;
}


// 게임 초기화 함수
void initData() {
	level = 1;	// 레벨 초기화 (범위 1~5)
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100;	// 어항 물 높이 초기화 (범위 0~100)
	}
}


void printfFishes() {
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);

	for (int i = 0; i < 6; i++) {
		printf("  %3d ", arrayFish[i]);
	}
	printf("\n\n");
}


// 어항의 물을 증발시키는 함수
void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime);	// 증발하는 물의 양 계산

		//	물 높이가 0 미만이면, 물 높이는 0으로 고정
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}


// 모든 물고기가 죽었는지 확인하는 함수
int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0) {
			return 1;
		}
	}
	return 0;
}