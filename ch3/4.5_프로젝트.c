#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void UpDownGame(int num); // �Լ� ���� (������Ÿ��)

int main(void) {

	srand((unsigned int)time(NULL)); // ����� ����ȯ �߰�, ���� �ʱ�ȭ
	int num = rand() % 100 + 1;
	//printf("���� : %d\n", num);

	UpDownGame(num);	// ���� ����!

	return 0;
}

void UpDownGame(int num) {
	int count = 0;	// �⺻ ī��Ʈ
	printf("���� �Է��ϼ��� : ");
	while (1) {
		if (count == 5) {	// ���� ��ȸ�� ��� ����������, ��ȸ 5��
			printf("\n\n\n��ȸ�� ��� �����ϼ̽��ϴ�. Ż��! ��!\n");
			printf("������ %d�����ϴ�. �޷�\n", num);	// ��ø���
			break;
		}
		int answer;
		scanf_s("%d", &answer);
		printf("�Է��� ���� %d�Դϴ�. \n", answer);


		if (answer >= 0 && answer <= 100) {
			if (answer == num) {
				printf("�����Դϴ�!\n");
				count = 0;
				break;
			}
			else if (answer > num) {
				printf("�� ���� ���� �Է��ϼ���.\n");
				count++;
			}
			else if (answer < num) {
				printf("�� ū ���� �Է��ϼ���.\n");
				count++;
			}
		}
		else {
			printf("ERROR\n");
		}
	printf("���� ��ȸ : %d \n", 5 - count);
	}
}