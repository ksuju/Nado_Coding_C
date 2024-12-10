#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// �߸��� ����, ȿ�� Ȯ���ϴ� �Լ�
static void mix_medi(int treatment);
// ���� ���� �Լ�
static void answer(int treatment);

int main(void) {
	srand((unsigned int)time(NULL)); // ���� �ʱ�ȭ

	int treatment = rand() % 4 + 1;	// ��¥ �߸��� ��ȣ (1~4�� ����)

	printf("���� ����!\n\n");

	int next = 1;

	// ���� 3���� ���� �߸����� ��ȣ�� �������
	for (int i = 1; i < 4; i++) {
		printf("%d�� ���� \n", i);
		mix_medi(treatment);

		// ������ ������ �ƴ϶�� ��� �������� ���� ����
		if (i < 3) {

			while (1) {
				printf("���� ������ Ȯ���Ϸ��� 1��, ������ �����÷��� 0���� �Է��ϼ��� : ");
				scanf_s("%d", &next);

				if (next == 0 || next == 1) {
					break;	// ��ȿ�� �Է��̸� ���� ����
				}
				else {
					printf("0�Ǵ� 1�� �Է����ּ���.\n\n");
				};
			}
			
			if (next == 0) {
				break;	// ���� ���� �� ���� ����
			}
			else {
				printf("���ο� �߸����� �����մϴ�.\n\n");
			};
		}
	}

	// ������?
	answer(treatment);

	return 0;
}


// �߸��� ����, ȿ�� Ȯ��
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

// ���� ����
static void answer(int treatment) {
	int answer;

	while (1) { // ���� ������ ���� ��ȿ�� �Է¸� ���
		printf("������? (1~4 �� ����): ");
		scanf_s("%d", &answer);

		if (answer >= 1 && answer <= 4) { // ��ȿ�� ������ �Է�
			if (answer == treatment) {
				printf("\n�����Դϴ�~\n\n\n");
			}
			else {
				printf("\nƲ�Ƚ��ϴ�~\n\n\n");
			}
			break; // ��ȿ�� �Է��̸� ���� ����
		}
		else {
			printf("1���� 4������ ��ȣ�� �Է� �����մϴ�. �ٽ� �Է����ּ���.\n\n");
		}
	}
}