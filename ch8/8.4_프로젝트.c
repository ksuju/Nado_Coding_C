#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int arrayAnimal[4][5] = { 0 };	// 동물 이름을 배치할 카드 지도용 배열
char* strAnimal[10];	// 동물 이름 배열
int checkAnimal[4][5];	// 카드 뒷면, 앞면 확인 배열 선언

void initAnimalArray();	// 배열 초기화 함수
void initAnimalName();	// 동물 이름 배열 초기화 함수
void shuffleAnimal();	// 카드 섞기 함수
int getEmptyPosition();	// 빈 공간 찾기 함수
int conv_pos_x(int x);	// x좌표 반환 함수
int conv_pos_y(int y);	// y좌표 반환 함수
void printAnimals();	// 카드 지도 출력 함수
void printQuestion();	// 문제 출력 함수
int foundAllAnimals();	// 게임 종료 함수

int main(void) {
	srand((unsigned int)time(NULL)); // 난수 초기화
	initAnimalArray();
	initAnimalName();
	shuffleAnimal();
	int failCount = 0;	// 총 실패 횟수를 저장할 변수 선언, 초기화

	while (1) {
		int select1 = 0;
		int select2 = 0;
		printAnimals();	// 카드 지도 출력
		printQuestion();	// 문제 출력
		printf("\n뒤집을 카드 2장을 고르세요. (예: 12 4) -> ");
		scanf_s("%d %d", &select1, &select2);
		
		if (select1 == select2) {	// 같은 카드 선택 시 무효
			continue;
		}

		// 입력받은 카드 번호를 x, y 좌표로 변환
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);
		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// 두 카드가 같은 동물이고 뒷면인 경우
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0
			&& (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]))) {
			printf("\n\n빙고! %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);

			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else {	// 두 카드가 같은 동물이거나 앞면인 경우
			printf("\n\n땡! 서로 다른 동물 카드거나 이미 뒤집힌 카드입니다. \n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);

			printf("\n");
			failCount++;	// 실패 횟수 1 증가
		}

		// 게임 종료
		if (foundAllAnimals() == 1) {
			printf("\n\n 모든 동물을 찾았습니다! \n");
			printf("총 %d번 실패했습니다.\n", failCount);
			break;
		}
	}
	return 0;
}


// 배열 초기화 함수
void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;	//	-1 : 카드 상태 (뒷면)
		}
	}
}

// 동물 이름 배열 초기화 함수
void initAnimalName() {
	strAnimal[0] = "돼지";
	strAnimal[1] = "소";
	strAnimal[2] = "호랑이";
	strAnimal[3] = "토끼";
	strAnimal[4] = "뱀";
	strAnimal[5] = "말";
	strAnimal[6] = "양";
	strAnimal[7] = "원숭이";
	strAnimal[8] = "닭";
	strAnimal[9] = "개";
}

// 카드 섞기
void shuffleAnimal() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// 빈 공간 찾기 함수
int getEmptyPosition() {
	while (1) {
		int randPos = rand() % 20;
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) {	// 해당 위치가 비어있는지 확인!
			return randPos;	// 찾은 공간이 비어있다면, 카드 번호 반환함
		}
	}

	return 0;	// 빈 공간이 없다면 0 반환
}


// x좌표 반환 함수
int conv_pos_x(int x) {
	return x / 5;
}


// y좌표 반환 함수
int conv_pos_y(int y) {
	return y % 5;
}


// 카드 지도 출력 함수
void printAnimals() {
	printf("====== 동물의 위치는? ======\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");	// 가독성을 위한 줄바꿈
	}
	printf("\n==================================\n");	// 구분선 출력
}


//  문제 출력 함수
void printQuestion() {
	printf("\n(문제)\n\n");
	int seq = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] != 0) {	// 카드가 앞면일 경우
				printf("%8s", strAnimal[arrayAnimal[i][j]]);	// 동물 이름 출력	
			}
			else {	// 카드가 뒷면이면?
				printf("%8d", seq);	// 카드 번호 출력
			}
			seq++;
		}
		printf("\n");
	}
}


// 게임 종료 함수
int foundAllAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;	// 뒤집지 않은 카드가 있음
			}
		}
	}
	return 1;	// 모든 카드 뒤집음
}