#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000	// �ڵ� ������ MAX��� ���� ���Ǹ� ���� 10000���� ġȯ, �迭�� ������ �� �����

int main(void) {
	// fputs() �Լ��� ���� ����
	// 1. fopen() �Լ��� ���� ���Ͽ� ���� ������ ��´�.
	// FILE * �����͸� = fopen(���ϸ�, ���ϸ��);
	
	//FILE* file = fopen("C:\\test\\test1.txt", "wb");	// ���� ����
	//if (file == NULL) {
	//	printf("���� ���� ����\n");
	//	return 1;
	//}
	//fputs("fputs() �Լ��� ���� �� ����\n", file);
	//fputs("�� ������?\n", file);
	//fputs("�� ������?\n", file);

	//fclose(file);	// fopen() �Լ��� �۾��ϰ� ���� ������ �ݵ�� �ݾƾ� ��!


	// 2. fgets() �Լ��� ���� �б�
	//char line[MAX] = { 0 };
	//FILE* file = fopen("C:\\test\\test1.txt", "rb");	// �б� ����
	//if (file == NULL) {
	//	printf("���� ���� ����\n");
	//	return 1;
	//}
	//while (fgets(line, MAX, file) != NULL) {
	//	printf("%s", line);
	//}
	//fclose(file);



	// 3. ������ ������ ���� ������ϱ� (fprintf, fscanf)
	// fprintf (����������, "����������", ��);
	// fscanf (����������, "����������", &������);

	// 3-1 : fprintf �Լ��� ���� ����
	//FILE * file = fopen("C:\\test\\test2.txt", "wb");	// ���� ����, ���� ������ ���
	//
	//if (file == NULL) {
	//	printf("���� ���� ����\n");
	//	return 1;
	//}

	//fprintf(file, "%s %d %d %d %d %d %d\n", "��÷��ȣ", 1, 2, 3, 4, 5, 6);
	//fprintf(file, "%s %d\n", "���ʽ���ȣ", 7);


	// 3-2 : fscanf()�Լ��� ���� �б�
	char str1[MAX];
	char str2[MAX];
	int num[6] = {0, 0, 0, 0, 0, 0};
	int bonus = 0;

	FILE * file = fopen("C:\\test\\test2.txt", "rb");
	if (file == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}
	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2],
		&num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3],
		num[4], num[5]);
	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);
	fclose(file);
	return 0;
}