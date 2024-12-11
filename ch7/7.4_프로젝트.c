#include <stdio.h>	// printf ��
#include <time.h>	// �ð� ���� �Լ��� ����ϱ� ����
#include <stdlib.h>	// exit() �Լ��� ����ϱ� ����

int level;	 // �������� ����, ����
int arrayFish[6];	// ����
int num;	// ���� �� ���� ��ȣ
long totalElapsedTime = 0;	// �� ��� �ð�
long prevElapsedTime = 0;	// ������ ���� �� �ð� (���� �� �ð� ����)
int* cursor;	// ���� �迭�� ������ ������ ����


void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();
int main(void) {
	long startTime = 0;	// ���� ���� �ð��� ���� ���� ���� �� �ʱ�ȭ
	initData();	// ���� �ʱ�ȭ �Լ� ȣ��
	startTime = clock();	// ���α׷� ���� ���� ������� �帥 �ð��� "���� �ð�" ���� ����
	cursor = arrayFish;	// ������ ������ ���� �迭�� ���� �ּ� �ֱ�

	while (1) {
		printfFishes();
		printf("�� �� ���׿� ���� �ٱ��? (1~6) ");
		scanf_s("%d", &num);

		// validation
		if (num < 1 || num > 6) {
			printf("\n�Է°��� �߸��ƽ��ϴ�.\n");
			continue;
		}
		
		// �� ��� �ð�, �� ������ ǥ��
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;

		printf("�� ��� �ð� : %ld��\n", totalElapsedTime);

		prevElapsedTime = totalElapsedTime - prevElapsedTime;	// ������ ���� �� ���ķ� �帥 �ð�

		printf("�ֱ� ��� �ð� : %ld��\n", prevElapsedTime);

		decreaseWater(prevElapsedTime);	// ������ ���� ���߽�Ű�� �Լ� ȣ��

		if (cursor[num - 1] <= 0) {	// ���� 1. ������ �� ���̰� 0 ����
			printf("%d�� ������ ������ �̹� �׾����ϴ�, ���� ���� �ʽ��ϴ�.\n", num);
		}
		else if (cursor[num - 1] + 1 <= 100) {	// ���� 2. ������ �� ���̰� 0���� ŭ
			printf("%d�� ���׿� ���� �ݴϴ�.\n\n", num);
			// ���� �ָ� �� ���� + 10, (cursor[num-1] (�� ����) = cursor[num - 1] + 10 (�� ���� + 10))
			cursor[num - 1] += 10;
		}

		if (totalElapsedTime / 20 > level - 1) {	// ������ Ȯ�� (20�ʸ���)
			level++;	// ������
			printf("*** �����մϴ�. %d�������� %d������ �ö����ϴ�. ***\n\n", level - 1, level);

			if (level == 5) {	// �ְ� ������ �����ϸ�, ���� ����
				printf("*** �����մϴ�! �ְ� ������ �����߽��ϴ�. ������ �����մϴ�. *** \n\n");
				exit(0);
			}
		}

		if (checkFishAlive() == 0) {	// ��� ����Ⱑ �׾����� Ȯ��
			printf("��� ����Ⱑ �׾����ϴ�.. �Ф� \n\n");
			exit(0);
		}
		else {	// �ּ� �Ѹ����� ����Ⱑ �������
			printf("��� �ִ� ����Ⱑ �ֽ��ϴ�!\n\n");
		}

		// �� ���� ��� �� ��Ȯ�� �ð� ������ �����ϱ� ���� �ڵ� "prevElapsedTime �ֽ�ȭ"
		// ������ ������? ���� ���� ���ϱ޼������� ���� �پ����
		prevElapsedTime = totalElapsedTime;
	}

	return 0;
}


// ���� �ʱ�ȭ �Լ�
void initData() {
	level = 1;	// ���� �ʱ�ȭ (���� 1~5)
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100;	// ���� �� ���� �ʱ�ȭ (���� 0~100)
	}
}


void printfFishes() {
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);

	for (int i = 0; i < 6; i++) {
		printf("  %3d ", arrayFish[i]);
	}
	printf("\n\n");
}


// ������ ���� ���߽�Ű�� �Լ�
void decreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime);	// �����ϴ� ���� �� ���

		//	�� ���̰� 0 �̸��̸�, �� ���̴� 0���� ����
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}


// ��� ����Ⱑ �׾����� Ȯ���ϴ� �Լ�
int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0) {
			return 1;
		}
	}
	return 0;
}