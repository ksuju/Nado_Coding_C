#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static int quiz();
static void result(int correct);

int main(void) {

	int correct = quiz();	// quiz 함수 호출, return값 quiz에 저장
	result(correct);	// quiz 함수에서 리턴받은 값을 result의 매개변수로 삽입, 함수 호출

	return 0;
}

static int quiz() {
	srand((unsigned int)time(NULL)); // 명시적 형변환 추가, 난수 초기화

	int count = 0;

	for (int i = 0; i < 5; i++) {
		int x = rand() % 18 + 2;
		int y = rand() % 18 + 2;

		int question = x * y;


		if (i == 4) {
			printf("마지막 문제!!!!!\n");
		}

		printf("%d X %d 정답은? : ", x, y);

		int answer;
		scanf_s("%d", &answer);
		
		

		if (answer == question) {
			printf("정답입니다! 짝짝짝!\n");
			count++;
		}
		else if (i == 4){
			printf("메롱ㅋ\n\n");
		}
		else {
			printf("틀렸습니다!바보 ㅋ\n\n");
		}
		printf("맞힌 문제 수 : %d\n\n", count);
	}

	return count;
}

static void result(int correct) {
	if (correct >= 0 && correct <= 2) {
		printf("혹시... 바보?");
	}
	else if (correct >= 3 && correct <= 4) {
		printf("조금만 더 분발하세요");
	}
	else if (correct == 5) {
		printf("혹시... 천재?");
	}
}

