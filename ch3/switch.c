#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int switchStudy(void) {
	// ���� �����ϱ� > rand()
	int ranNum = rand() % 3 + 1; // 1~3 ������ ���� ����
	
	printf("������ : %d\n", ranNum);

	// ���� �ʱ�ȭ
	printf("���� �ʱ�ȭ ����\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10);
	};

	srand(time(NULL)); // ���� �ʱ�ȭ (�̰� ������ ó�� ���� ������ ��µ�)

	printf("\n\n���� �ʱ�ȭ ����\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", rand() % 10);
	};
	

	printf("\n\n\n\n\n ���ǹ� ���������� \n");
	//srand(time(NULL)); //	���� �ʱ�ȭ, time(NULL)�� �̿��� ���� ������ �ʱ�ȭ�� ���α׷� ��ü���� �ѹ��� �ؾߵ�!
	int i = rand() % 3;	//	0~2 ��ȯ
	// ���ǹ��� Ȱ���� ����������
	if (i == 0) {
		printf("*** ����\n");
	}
	else if (i == 1) {
		printf("*** ����\n");
	}
	else if (i == 2) {
		printf("*** ��\n");
	}
	else {
		printf("XX\n");
	};



	// switch���� Ȱ���� ����������
	int j = rand() % 3;
	printf("\n\n\n\n\n switch ���������� \n");
	switch (j) {
	case 0 :
		printf("*** ����\n");
		break;
	case 1 :
		printf("*** ����\n");
		break;
	case 2 :
		printf("*** ��\n");
		break;
	default :	//	� ���� �ش����� ���� �� ������ ����
		printf("XX\n");
	}


	return 0;
}