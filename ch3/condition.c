#include <stdio.h>

int condition(void) {
	int age = 15;
	if (age >= 8 && age <= 13) {
		printf("�ʵ��л� �Դϴ�.\n");
	}
	else if (age >= 14 && age <= 16) {
		printf("���л� �Դϴ�.\n");
	}
	else if (age >= 17 && age <= 19) {
		printf("����л� �Դϴ�.\n");
	}
	else {
		printf("�����Դϴ�.\n");
	}


	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	
	// and ����
	if (a == b && c == d) {
		printf("a�� b�� ���� c�� d�� ����.\n");
	}
	else {
		printf("���� ���� �ٸ��ϴ�. (and)\n");
	};

	// or ����
	if (a == b || c == d) {
		printf("a�� b �Ǵ� c�� d�� ���� �����ϴ�.\n");
	}
	else {
		printf("���� ���� �ٸ��ϴ�. (or)\n");
	}


	// break, continue
	// 30���� �л� �� 5�������� �л��� ��ǥ�� �Ѵٸ�?
	for (int i = 1; i <= 30; i++) {
		if (i >= 6) {
			printf("������ �л��� ���� ������.\n");
			break;
		}
		else {
			if (i == 3) {
				printf("%d�� �л��� �Ἦ�Դϴ�.\n", i);
				continue;
			}
			printf("%d�� �л��� ��ǥ�� �غ��ϼ���.\n", i);
		}
		
	};
	return 0;
}