#include <stdio.h>

int test(void) {
	// C언어 반복문
	// for문
	for (int i = 1; i <= 10; i++) {
		printf("Hello %d\n", i);
	}

	int i = 1;

	// while문
	while (i <= 10) {
		printf("while %d\n", i);
		i++;
	}

	// do-while문
	int j = 1;

	do {
		printf("do-while %d\n", j++);
	} while (j <= 10);

	return 0;
}