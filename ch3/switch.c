#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int switchStudy(void) {
	// 난수 생성하기 > rand()
	int ranNum = rand() % 3 + 1; // 1~3 범위의 난수 생성
	
	printf("난수는 : %d\n", ranNum);

	// 난수 초기화
	printf("난수 초기화 이전\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10);
	};

	srand(time(NULL)); // 난수 초기화 (이거 없으면 처음 뽑은 난수만 출력됨)

	printf("\n\n난수 초기화 이후\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10);
	};
	

	printf("\n\n\n\n\n 조건문 가위바위보 \n");
	//srand(time(NULL)); //	난수 초기화, time(NULL)을 이용한 난수 생성기 초기화는 프로그램 전체에서 한번만 해야됨!
	int i = rand() % 3;	//	0~2 반환
	// 조건문을 활용한 가위바위보
	if (i == 0) {
		printf("*** 가위\n");
	}
	else if (i == 1) {
		printf("*** 바위\n");
	}
	else if (i == 2) {
		printf("*** 보\n");
	}
	else {
		printf("XX\n");
	};



	// switch문을 활용한 가위바위보
	int j = rand() % 3;
	printf("\n\n\n\n\n switch 가위바위보 \n");
	switch (j) {
	case 0 :
		printf("*** 가위\n");
		break;
	case 1 :
		printf("*** 바위\n");
		break;
	case 2 :
		printf("*** 보\n");
		break;
	default :	//	어떤 값도 해당하지 않을 때 수행할 문장
		printf("XX\n");
	}


	return 0;
}