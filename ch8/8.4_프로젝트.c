#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int arrayAnimal[4][5] = { 0 };	// ���� �̸��� ��ġ�� ī�� ������ �迭
char* strAnimal[10];	// ���� �̸� �迭
int checkAnimal[4][5];	// ī�� �޸�, �ո� Ȯ�� �迭 ����

void initAnimalArray();	// �迭 �ʱ�ȭ �Լ�
void initAnimalName();	// ���� �̸� �迭 �ʱ�ȭ �Լ�
void shuffleAnimal();	// ī�� ���� �Լ�
int getEmptyPosition();	// �� ���� ã�� �Լ�
int conv_pos_x(int x);	// x��ǥ ��ȯ �Լ�
int conv_pos_y(int y);	// y��ǥ ��ȯ �Լ�
void printAnimals();	// ī�� ���� ��� �Լ�
void printQuestion();	// ���� ��� �Լ�
int foundAllAnimals();	// ���� ���� �Լ�

int main(void) {
	srand((unsigned int)time(NULL)); // ���� �ʱ�ȭ
	initAnimalArray();
	initAnimalName();
	shuffleAnimal();
	int failCount = 0;	// �� ���� Ƚ���� ������ ���� ����, �ʱ�ȭ

	while (1) {
		int select1 = 0;
		int select2 = 0;
		printAnimals();	// ī�� ���� ���
		printQuestion();	// ���� ���
		printf("\n������ ī�� 2���� ������. (��: 12 4) -> ");
		scanf_s("%d %d", &select1, &select2);
		
		if (select1 == select2) {	// ���� ī�� ���� �� ��ȿ
			continue;
		}

		// �Է¹��� ī�� ��ȣ�� x, y ��ǥ�� ��ȯ
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);
		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// �� ī�尡 ���� �����̰� �޸��� ���
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0
			&& (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y]))) {
			printf("\n\n����! %s �߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);

			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		else {	// �� ī�尡 ���� �����̰ų� �ո��� ���
			printf("\n\n��! ���� �ٸ� ���� ī��ų� �̹� ������ ī���Դϴ�. \n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);

			printf("\n");
			failCount++;	// ���� Ƚ�� 1 ����
		}

		// ���� ����
		if (foundAllAnimals() == 1) {
			printf("\n\n ��� ������ ã�ҽ��ϴ�! \n");
			printf("�� %d�� �����߽��ϴ�.\n", failCount);
			break;
		}
	}
	return 0;
}


// �迭 �ʱ�ȭ �Լ�
void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;	//	-1 : ī�� ���� (�޸�)
		}
	}
}

// ���� �̸� �迭 �ʱ�ȭ �Լ�
void initAnimalName() {
	strAnimal[0] = "����";
	strAnimal[1] = "��";
	strAnimal[2] = "ȣ����";
	strAnimal[3] = "�䳢";
	strAnimal[4] = "��";
	strAnimal[5] = "��";
	strAnimal[6] = "��";
	strAnimal[7] = "������";
	strAnimal[8] = "��";
	strAnimal[9] = "��";
}

// ī�� ����
void shuffleAnimal() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// �� ���� ã�� �Լ�
int getEmptyPosition() {
	while (1) {
		int randPos = rand() % 20;
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1) {	// �ش� ��ġ�� ����ִ��� Ȯ��!
			return randPos;	// ã�� ������ ����ִٸ�, ī�� ��ȣ ��ȯ��
		}
	}

	return 0;	// �� ������ ���ٸ� 0 ��ȯ
}


// x��ǥ ��ȯ �Լ�
int conv_pos_x(int x) {
	return x / 5;
}


// y��ǥ ��ȯ �Լ�
int conv_pos_y(int y) {
	return y % 5;
}


// ī�� ���� ��� �Լ�
void printAnimals() {
	printf("====== ������ ��ġ��? ======\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");	// �������� ���� �ٹٲ�
	}
	printf("\n==================================\n");	// ���м� ���
}


//  ���� ��� �Լ�
void printQuestion() {
	printf("\n(����)\n\n");
	int seq = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] != 0) {	// ī�尡 �ո��� ���
				printf("%8s", strAnimal[arrayAnimal[i][j]]);	// ���� �̸� ���	
			}
			else {	// ī�尡 �޸��̸�?
				printf("%8d", seq);	// ī�� ��ȣ ���
			}
			seq++;
		}
		printf("\n");
	}
}


// ���� ���� �Լ�
int foundAllAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;	// ������ ���� ī�尡 ����
			}
		}
	}
	return 1;	// ��� ī�� ������
}