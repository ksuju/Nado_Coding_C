#include <stdio.h>;

int main(void) {
	// ���߹ݺ��� �ǽ� 1. ������ ���
	for (int i=1; i<=9; i++) {
		printf("%d��\n", i);

		for (int j=1; j<=9; j++) {
			printf("    %d x %d = %d\n", i, j, i*j);
		}
	}


	// ���߹ݺ��� �ǽ� 2. ��ǥ ���
	for (int i=0; i<5; i++) {
		for (int j=0; j<=i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	// ���߹ݺ��� �ǽ� 3. ��ǥ ������ ���� ���
	for (int i=0; i<5; i++) {
		for (int j = i; j <= 5 - 1; j++) {
			printf(" ");
		}
		for (int j=0; j<=i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	// ����üũ : �� ���
	for (int i = 5; i > 0; i--) {
		printf(" ");
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	// ������Ʈ : �Ƕ�̵带 �׾ƶ�
	int floor;
	printf("�� ������ �����ðڽ��ϱ�? (5�� ~ 100��) ");
	scanf_s("%d", &floor);

	for (int i = 0; i < floor; i++) {
		for (int j=i; j < floor-1; j++) {
			printf(" ");
		}
		for (int j=0; j<i*2+1; j++) {
			printf("*");
		}
		printf("\n");
	}



	return 0;
}