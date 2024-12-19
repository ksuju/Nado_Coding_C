#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	char* name;
	char* character;
	int age;
	int level;
} CAT;

CAT cats[5];
int collection[5] = { 0, 0, 0, 0, 0 };	// 0 = 빈 상자, 1 = 고양이가 들어간 상자

void initCats();
void printCat(int selected);
int checkCollection();
int main(void) {
	srand((unsigned int)time(NULL)); // 난수 초기화
	initCats();
	while (1) {
		printf("어느 고양이가 나올까?\nEnter를 눌러 확인하기!");
		getchar();	// Enter 입력받기
		int selected = rand() % 5;
		printCat(selected);
		collection[selected] = 1;	// 0 = 빈 상자, 1 = 고양이가 들어간 상자
		int collectAll = checkCollection();
	}
	return 0;
}

void initCats() {
	cats[0].name = "깜냥이";
	cats[0].age = 5;
	cats[0].character = "온순함";
	cats[0].level = 1;
	cats[1].name = "귀요미";
	cats[1].age = 2;
	cats[1].character = "까칠함";
	cats[1].level = 2;
	cats[2].name = "수줍이";
	cats[2].age = 8;
	cats[2].character = "잠이많음";
	cats[2].level = 3;
	cats[3].name = "까꿍이";
	cats[3].age = 2;
	cats[3].character = "시끄러움";
	cats[3].level = 4;
	cats[4].name = "돼냥이";
	cats[4].age = 1;
	cats[4].character = "식탐많음";
	cats[4].level = 5;
}

// 뽑은 고양이 출력 함수
void printCat(int selected) {
	printf("\n\n === 어떤 고양이가 나왔을까? === \n\n");
	printf(" 이름 : %s\n", cats[selected].name);
	printf(" 나이 : %d\n", cats[selected].age);
	printf(" 특징 : %s\n", cats[selected].character);
	//printf(" 레벨 : %d\n", cats[selected].level);
	printf(" 레벨 : ");
	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "★");	// 레벨은 숫자 대신 별 기호로 출력
	}
	printf("\n\n");
}


// 모은 고양이 확인하는 함수
int checkCollection() {
	int collectAll = 1;	// 디폴트 : 고양이를 모두 모은 상태
	printf("\n\n ==== 고양이 보유 목록 ==== \n\n");
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%10s", "(빈 상자)");
			collectAll = 0;	// 고양이를 전부 모으지 못한 상태
		}
		else {
			printf("%10s", cats[i].name);
		}
	}
	printf("\n===================\n\n");

	if (collectAll) {
		printf("\n\n 축하합니다! 모든 고양이를 모았습니다! \n\n");
	}

	return collectAll;
}