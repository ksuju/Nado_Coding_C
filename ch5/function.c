#include <stdio.h>
void p(int num);
int add(int num1, int num2);

int functionStudy(void) {
	int num = 2;
	p(num);

	num += 3;
	p(num);

	num -= 1;
	p(num);

	num *= 3;
	p(num);

	num /= 6;
	p(num);

	return 0;
}


void p(int num) {
	printf("num�� %d�Դϴ�.\n", num);
}

int add(int num1, int num2) {
	return num1 + num2;
}

