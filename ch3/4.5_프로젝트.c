#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void UpDownGame(int num); // 함수 선언 (프로토타입)

int main(void) {

	srand((unsigned int)time(NULL)); // 명시적 형변환 추가, 난수 초기화
	int num = rand() % 100 + 1;
	//printf("정답 : %d\n", num);

	UpDownGame(num);	// 게임 시작!

	return 0;
}

void UpDownGame(int num) {
	int count = 0;	// 기본 카운트
	printf("값을 입력하세요 : ");
	while (1) {
		if (count == 5) {	// 게임 기회를 모두 소진했을시, 기회 5번
			printf("\n\n\n기회를 모두 소진하셨습니다. 탈락! 땡!\n");
			printf("정답은 %d였습니다. 메롱\n", num);	// 약올리기
			break;
		}
		int answer;
		scanf_s("%d", &answer);
		printf("입력한 값은 %d입니다. \n", answer);


		if (answer >= 0 && answer <= 100) {
			if (answer == num) {
				printf("정답입니다!\n");
				count = 0;
				break;
			}
			else if (answer > num) {
				printf("더 작은 값을 입력하세요.\n");
				count++;
			}
			else if (answer < num) {
				printf("더 큰 값을 입력하세요.\n");
				count++;
			}
		}
		else {
			printf("ERROR\n");
		}
	printf("남은 기회 : %d \n", 5 - count);
	}
}