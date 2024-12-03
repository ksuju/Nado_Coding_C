#include <stdio.h>

int condition(void) {
	int age = 15;
	if (age >= 8 && age <= 13) {
		printf("초등학생 입니다.\n");
	}
	else if (age >= 14 && age <= 16) {
		printf("중학생 입니다.\n");
	}
	else if (age >= 17 && age <= 19) {
		printf("고등학생 입니다.\n");
	}
	else {
		printf("성인입니다.\n");
	}


	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	
	// and 조건
	if (a == b && c == d) {
		printf("a와 b가 같고 c와 d가 같다.\n");
	}
	else {
		printf("값이 서로 다릅니다. (and)\n");
	};

	// or 조건
	if (a == b || c == d) {
		printf("a와 b 또는 c와 d의 값이 같습니다.\n");
	}
	else {
		printf("값이 서로 다릅니다. (or)\n");
	}


	// break, continue
	// 30명의 학생 중 5번까지의 학생만 발표를 한다면?
	for (int i = 1; i <= 30; i++) {
		if (i >= 6) {
			printf("나머지 학생은 집에 가세요.\n");
			break;
		}
		else {
			if (i == 3) {
				printf("%d번 학생은 결석입니다.\n", i);
				continue;
			}
			printf("%d번 학생은 발표를 준비하세요.\n", i);
		}
		
	};
	return 0;
}