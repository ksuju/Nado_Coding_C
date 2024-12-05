#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static int quiz();
static void result(int correct);

int main(void) {

	int correct = quiz();	// quiz �Լ� ȣ��, return�� quiz�� ����
	result(correct);	// quiz �Լ����� ���Ϲ��� ���� result�� �Ű������� ����, �Լ� ȣ��

	return 0;
}

static int quiz() {
	srand((unsigned int)time(NULL)); // ����� ����ȯ �߰�, ���� �ʱ�ȭ

	int count = 0;

	for (int i = 0; i < 5; i++) {
		int x = rand() % 18 + 2;
		int y = rand() % 18 + 2;

		int question = x * y;


		if (i == 4) {
			printf("������ ����!!!!!\n");
		}

		printf("%d X %d ������? : ", x, y);

		int answer;
		scanf_s("%d", &answer);
		
		

		if (answer == question) {
			printf("�����Դϴ�! ¦¦¦!\n");
			count++;
		}
		else if (i == 4){
			printf("�޷դ�\n\n");
		}
		else {
			printf("Ʋ�Ƚ��ϴ�!�ٺ� ��\n\n");
		}
		printf("���� ���� �� : %d\n\n", count);
	}

	return count;
}

static void result(int correct) {
	if (correct >= 0 && correct <= 2) {
		printf("Ȥ��... �ٺ�?");
	}
	else if (correct >= 3 && correct <= 4) {
		printf("���ݸ� �� �й��ϼ���");
	}
	else if (correct == 5) {
		printf("Ȥ��... õ��?");
	}
}

