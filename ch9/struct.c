#include <stdio.h>

// 구조체는 main함수 위 전역 위치에 정의함!
struct GameInfo {	// 구조체 정의
	char* name;	// 구조체 멤버들
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;	// 구조체의 멤버로 구조체 포인터 설정
};

int stst(void) {
	char* name = "나도게임";
	int year = 2022;
	int price = 50;
	char* company = "나도회사";

	char* name2 = "님도게임";
	int year2 = 2022;
	int price2 = 50;
	char* company2 = "님도회사";


	// 구조체 변수 선언하기 > struct 구조체명 변수명;
	struct GameInfo gameInfo1;	// 구조체 변수

	// 구조체 멤버 저장
	gameInfo1.name = "구조체게임";
	gameInfo1.year = 2024;
	gameInfo1.price = 100;
	gameInfo1.company = "구조체게임회사";

	// 구조체 멤버 출력 (멤버의 타입에 맞게 출력)
	printf(" ================= 게임 출시 정보 ================= \n");
	printf("게임 이름 : %s\n", gameInfo1.name);
	printf("발매 년도 : %d\n", gameInfo1.year);
	printf("게임 가격 : %d\n", gameInfo1.price);
	printf("제작 회사 : %s\n", gameInfo1.company);

	// 구조체 멤버 더 편하게 저장하기
	struct GameInfo gameInfo2 = { "편한게임", 2030, 3000, "편한게임회사" };
	printf("\n\n ================= 게임 출시 정보 ================= \n");
	printf("게임 이름 : %s\n", gameInfo2.name);
	printf("발매 년도 : %d\n", gameInfo2.year);
	printf("게임 가격 : %d\n", gameInfo2.price);
	printf("제작 회사 : %s\n", gameInfo2.company);

	// 구조체 배열 만들기
	// struct 구조체명 배열명[배열크기];

	struct GameInfo gameArray[2] = {
		{"배열게임", 2023, 10, "배열게임회사"},
		{"배열게임임", 2024, 100, "배열게임회사임"},
	};

	printf("\n\n ================= 게임 출시 정보 ================= \n");
	printf("게임 이름 : %s\n", gameArray[0].name);
	printf("발매 년도 : %d\n", gameArray[0].year);
	printf("게임 가격 : %d\n", gameArray[0].price);
	printf("제작 회사 : %s\n", gameArray[0].company);


	// 구조체 포인터 사용하기 > 구조체 포인터 : 구조체 변수의 주소를 가리키는 변수
	// struct 구조체명 * 변수명;

	struct GameInfo * gamePtr;	// 구조체 포인터 변수 선언
	gamePtr = &gameInfo1;
	printf("\n\n ================= 게임 출시 정보 ================= \n");
	printf("게임 이름 : %s\n", (*gamePtr).name);
	printf("발매 년도 : %d\n", (*gamePtr).year);
	printf("게임 가격 : %d\n", gamePtr -> price);	// 화살표, 간접멤버 참조 연산자를 사용하면 가독성이 더 좋음
	printf("제작 회사 : %s\n", gamePtr -> company);


	// 구조체 안의 구조체
	struct GameInfo game1 = {"재밌는게임", 2025, 13000, "재밌는게임회사"};
	struct GameInfo game2 = { "음..게임", 2022, 3000, "그냥게임회사" };
	game1.friendGame = &game2;
	// friendGame은 GameInfo 구조체 안에 멤버로 존재하는 구조체 포인터
	printf("\n\n ================= 게임 출시 정보 ================= \n");
	printf("게임 이름 : %s\n", game1.friendGame -> name);
	printf("발매 년도 : %d\n", game1.friendGame -> year);
	printf("게임 가격 : %d\n", game1.friendGame -> price);
	printf("제작 회사 : %s\n", game1.friendGame -> company);

	return 0;
}