#include <stdio.h>;

int main(void) {
	// 이중반복문 실습 1. 구구단 출력
	for (int i=1; i<=9; i++) {
		printf("%d단\n", i);

		for (int j=1; j<=9; j++) {
			printf("    %d x %d = %d\n", i, j, i*j);
		}
	}


	// 이중반복문 실습 2. 별표 출력
	for (int i=0; i<5; i++) {
		for (int j=0; j<=i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	// 이중반복문 실습 3. 별표 오른쪽 정렬 출력
	for (int i=0; i<5; i++) {
		for (int j = i; j <= 5 - 1; j++) {
			printf(" ");
		}
		for (int j=0; j<=i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	// 셀프체크 : 별 출력
	for (int i = 5; i > 0; i--) {
		printf(" ");
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	// 프로젝트 : 피라미드를 쌓아라
	int floor;
	printf("몇 층으로 쌓으시겠습니까? (5층 ~ 100층) ");
	scanf_s("%d", &floor);

	for (int i = 0; i < floor; i++) {
		for (int j=i; j < floor-1; j++) {
			printf(" ");
		}
		for (int j=0; j<i*2+1; j++) {
			printf("*");
		}
		printf("\n");
	}



	return 0;
}