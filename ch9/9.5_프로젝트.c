#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	char* name;
	char* character;
	int age;
	int level;
} CAT;

CAT cats[5];
int collection[5] = { 0, 0, 0, 0, 0 };	// 0 = �� ����, 1 = ����̰� �� ����

void initCats();
void printCat(int selected);
int checkCollection();
int main(void) {
	srand((unsigned int)time(NULL)); // ���� �ʱ�ȭ
	initCats();
	while (1) {
		printf("��� ����̰� ���ñ�?\nEnter�� ���� Ȯ���ϱ�!");
		getchar();	// Enter �Է¹ޱ�
		int selected = rand() % 5;
		printCat(selected);
		collection[selected] = 1;	// 0 = �� ����, 1 = ����̰� �� ����
		int collectAll = checkCollection();
	}
	return 0;
}

void initCats() {
	cats[0].name = "������";
	cats[0].age = 5;
	cats[0].character = "�¼���";
	cats[0].level = 1;
	cats[1].name = "�Ϳ��";
	cats[1].age = 2;
	cats[1].character = "��ĥ��";
	cats[1].level = 2;
	cats[2].name = "������";
	cats[2].age = 8;
	cats[2].character = "���̸���";
	cats[2].level = 3;
	cats[3].name = "�����";
	cats[3].age = 2;
	cats[3].character = "�ò�����";
	cats[3].level = 4;
	cats[4].name = "�ų���";
	cats[4].age = 1;
	cats[4].character = "��Ž����";
	cats[4].level = 5;
}

// ���� ����� ��� �Լ�
void printCat(int selected) {
	printf("\n\n === � ����̰� ��������? === \n\n");
	printf(" �̸� : %s\n", cats[selected].name);
	printf(" ���� : %d\n", cats[selected].age);
	printf(" Ư¡ : %s\n", cats[selected].character);
	//printf(" ���� : %d\n", cats[selected].level);
	printf(" ���� : ");
	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "��");	// ������ ���� ��� �� ��ȣ�� ���
	}
	printf("\n\n");
}


// ���� ����� Ȯ���ϴ� �Լ�
int checkCollection() {
	int collectAll = 1;	// ����Ʈ : ����̸� ��� ���� ����
	printf("\n\n ==== ����� ���� ��� ==== \n\n");
	for (int i = 0; i < 5; i++) {
		if (collection[i] == 0) {
			printf("%10s", "(�� ����)");
			collectAll = 0;	// ����̸� ���� ������ ���� ����
		}
		else {
			printf("%10s", cats[i].name);
		}
	}
	printf("\n===================\n\n");

	if (collectAll) {
		printf("\n\n �����մϴ�! ��� ����̸� ��ҽ��ϴ�! \n\n");
	}

	return collectAll;
}