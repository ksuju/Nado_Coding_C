//#include <stdio.h>
//
//int array(void) {
//
//	// �迭 �����ϱ�
//	// �ڷ��� �迭�� [�迭ũ��];
//	// �迭ũ�⿡�� �׻� ����� ���� �� �ִ�!
//	// �迭�� �����ϸ� �׻� �ʱ�ȭ �ؾ���
//	int subway_array[3];
//
//	subway_array[0] = 10;
//	subway_array[1] = 20;
//	subway_array[2] = 30;
//	
//	// �迭 ���� ���ϱ� ***
//	// �ڹٿʹ� �ٸ�! length �޼��尡 ����!
//	// sizeof(int �迭) = int �ڷ����� ũ�� 4 * �迭�� ������ (�迭 ��ü�� ����Ʈ ũ�⸦ ��ȯ)
//	// ���� �Ʒ��� ���� ������ ����� ��Ȯ�� ���̸� �� �� ����
//	int array_length = sizeof(subway_array) / sizeof(int);
//
//	for (int i = 0; i < array_length; i++) {
//		printf("����ö %dȣ���� %d���� Ÿ�� �ֽ��ϴ�.\n", i + 1, subway_array[i]);
//	}
//
//
//	// �Ϻΰ� �ʱ�ȭ
//	// ũ�Ⱑ 10�� �迭�� 3���� �ʱ�ȭ �� ���? 1, 2, 3, 0, 0 ~~~ �̷��� �ʱ�ȭ��
//	int arr[10] = { 1, 2, 3 };
//
//	int arr_length = sizeof(arr) / sizeof(int);
//
//	for (int i = 0; i < arr_length; i++) {
//		printf("%d\n", arr[i]);
//	}
//
//	// �迭 ũ����� ��� ���?
//	// �ʱ�ȭ�� �迭�� ũ�⸸ŭ �迭�� ������
//	// arr2 �� �迭 ���̴� 2
//	int arr2[] = { 1, 2 };
//
//
//	// �Ǽ��� �迭 �ʱ�ȭ
//	// ��� ����
//	float floatArr[] = { 1.0f, 2.0f, 3.0f };
//	int floatArr_length = sizeof(floatArr) / sizeof(float);	// float�� ũ��� ���� (�ڷ����� �°� ����)
//	for (int i = 0; i < floatArr_length; i++) {
//		printf("%.2f\n", floatArr[i]);
//	}
//
//
//	// �迭�� ���ڿ� �����ϱ�
//	// �迭 ũ��� ���ڼ��� ������ ���ڰ� ����!
//	// ���ڿ� ���� NULL�� �� ������ �ּ� ��ĭ �ʿ�!
//	char str_x[6] = "coding";	// X
//	char str_o[7] = "coding";	// O
//	printf("str_x : %s\n", str_x);	// ���� ������ �ջ�
//	printf("str_o : %s\n", str_o);	// ���� ���
//
//
//	char str[] = "coding";	// �̷��� �ʱ�ȭ �ϸ� ����
//	printf("str : %s\n", str);
//
//
//	// ���ڿ� �Է¹ޱ� (����)
//	// scanf_s�� ����ϱ� ���ؼ��� �ݵ�� �迭�� ũ�⸦ ����ؾ���
//	char name[256];
//	printf("�̸��� ������? ");
//	scanf_s("%s", name, sizeof(name));
//	printf("%s\n", name);
//
//	return 0;
//}