#include <stdio.h>

int test(void) {
	// C��� �ݺ���
	// for��
	for (int i = 1; i <= 10; i++) {
		printf("Hello %d\n", i);
	}

	int i = 1;

	// while��
	while (i <= 10) {
		printf("while %d\n", i);
		i++;
	}

	// do-while��
	int j = 1;

	do {
		printf("do-while %d\n", j++);
	} while (j <= 10);

	return 0;
}