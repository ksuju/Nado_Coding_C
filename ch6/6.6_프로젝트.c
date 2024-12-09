#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static void mix_medi(int treatment);
static void answer(int treatment);

int main(void) {
	srand((unsigned int)time(NULL)); // ���� �ʱ�ȭ

	int treatment = rand() % 4 + 1;	// ��¥ �߸��� ��ȣ

	printf("���� ����!\n\n");

	// ���� 3���� ���� �߸����� ��ȣ�� �������
	for (int i = 1; i < 4; i++) {
		printf("%d�� ���� \n", i);
		mix_medi(treatment);
	}

	// ������?
	answer(treatment);

	return 0;
}


static void mix_medi(int treatment) {
	int mix = rand() % 2 + 2;	// ���� 2�� ������ 3�� ������ �������� ����
	int bottle[4] = {0};	// ���� ���� ��
	int length = sizeof(bottle) / sizeof(int);	// �߸�ȿ������ �ݺ����� �־��� ����

	// �������� ���� ����, mix�� ���� 2�� Ȥ�� 3��, �ߺ� ��� ����
	for (int i = 0; i < mix;) {
		int medi = rand() % 4 + 1;	// 1�� ~ 4�� �߸���
		int dupl = 0;	// �ߺ� üũ

		for (int j = 0; j < mix; j++) {
			if (bottle[j] == medi) {
				dupl = 1;	// �ߺ� �߰�!
				break;
			};
		};

		if (!dupl) {
			printf("%d�� ��ǰ : %d\n", i + 1, medi);
			bottle[i] = medi;
			i++;	// �ߺ��� ���� ��쿡�� i ����
		}

	}

	// �߸�ȿ������
	int found = 0;
	for (int i = 0; i < mix; i++) { // mix�� �˻�
		if (treatment == bottle[i]) {
			printf("�Ӹ��� �ڶ����ϴ�!\n\n\n");
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("�Ӹ��� �ڶ��� �ʾҽ��ϴ٤Ф�\n\n\n");
	}
}

static void answer(int treatment) {
	int answer;
	printf("������? : ");
	scanf_s("%d", &answer);

	if (answer == treatment) {
		printf("�����Դϴ�~\n\n\n");
	}
	else {
		printf("Ʋ�Ƚ��ϴ�~\n\n\n");
	}
}