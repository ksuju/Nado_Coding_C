#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static void mix_medi(int treatment);
static void answer(int treatment);

int main(void) {
	srand((unsigned int)time(NULL)); // 난수 초기화

	int treatment = rand() % 4 + 1;	// 진짜 발모제 번호

	printf("게임 시작!\n\n");

	// 조합 3개를 보고 발모제의 번호를 맞춰야함
	for (int i = 1; i < 4; i++) {
		printf("%d번 조합 \n", i);
		mix_medi(treatment);
	}

	// 정답은?
	answer(treatment);

	return 0;
}


static void mix_medi(int treatment) {
	int mix = rand() % 2 + 2;	// 약을 2개 섞을지 3개 섞을지 랜덤으로 정함
	int bottle[4] = {0};	// 약을 담을 병
	int length = sizeof(bottle) / sizeof(int);	// 발모효과검증 반복문에 넣어줄 길이

	// 랜덤으로 약을 섞음, mix에 따라서 2개 혹은 3개, 중복 허용 안함
	for (int i = 0; i < mix;) {
		int medi = rand() % 4 + 1;	// 1번 ~ 4번 발모제
		int dupl = 0;	// 중복 체크

		for (int j = 0; j < mix; j++) {
			if (bottle[j] == medi) {
				dupl = 1;	// 중복 발견!
				break;
			};
		};

		if (!dupl) {
			printf("%d번 약품 : %d\n", i + 1, medi);
			bottle[i] = medi;
			i++;	// 중복이 없을 경우에만 i 증가
		}

	}

	// 발모효과검증
	int found = 0;
	for (int i = 0; i < mix; i++) { // mix만 검사
		if (treatment == bottle[i]) {
			printf("머리가 자랐습니다!\n\n\n");
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("머리가 자라지 않았습니다ㅠㅠ\n\n\n");
	}
}

static void answer(int treatment) {
	int answer;
	printf("정답은? : ");
	scanf_s("%d", &answer);

	if (answer == treatment) {
		printf("정답입니다~\n\n\n");
	}
	else {
		printf("틀렸습니다~\n\n\n");
	}
}