#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 발모제 제조, 효과 확인하는 함수
static void mix_medi(int treatment);
// 정답 제출 함수
static void answer(int treatment);

int main(void) {
	srand((unsigned int)time(NULL)); // 난수 초기화

	int treatment = rand() % 4 + 1;	// 진짜 발모제 번호 (1~4중 랜덤)

	printf("게임 시작!\n\n");

	int next = 1;

	// 조합 3개를 보고 발모제의 번호를 맞춰야함
	for (int i = 1; i < 4; i++) {
		printf("%d번 조합 \n", i);
		mix_medi(treatment);

		// 마지막 조합이 아니라면 계속 조합할지 여부 결정
		if (i < 3) {

			while (1) {
				printf("다음 조합을 확인하려면 1번, 정답을 맞히시려면 0번을 입력하세요 : ");
				scanf_s("%d", &next);

				if (next == 0 || next == 1) {
					break;	// 유효한 입력이면 루프 종료
				}
				else {
					printf("0또는 1만 입력해주세요.\n\n");
				};
			}
			
			if (next == 0) {
				break;	// 루프 종료 후 정답 제출
			}
			else {
				printf("새로운 발모제를 조합합니다.\n\n");
			};
		}
	}

	// 정답은?
	answer(treatment);

	return 0;
}


// 발모제 제조, 효과 확인
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

// 정답 제출
static void answer(int treatment) {
	int answer;

	while (1) { // 무한 루프를 통해 유효한 입력만 허용
		printf("정답은? (1~4 중 선택): ");
		scanf_s("%d", &answer);

		if (answer >= 1 && answer <= 4) { // 유효한 범위의 입력
			if (answer == treatment) {
				printf("\n정답입니다~\n\n\n");
			}
			else {
				printf("\n틀렸습니다~\n\n\n");
			}
			break; // 유효한 입력이면 루프 종료
		}
		else {
			printf("1부터 4까지의 번호만 입력 가능합니다. 다시 입력해주세요.\n\n");
		}
	}
}