#include <stdio.h>

// ����ü�� main�Լ� �� ���� ��ġ�� ������!
struct GameInfo {	// ����ü ����
	char* name;	// ����ü �����
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame;	// ����ü�� ����� ����ü ������ ����
};

int stst(void) {
	char* name = "��������";
	int year = 2022;
	int price = 50;
	char* company = "����ȸ��";

	char* name2 = "�Ե�����";
	int year2 = 2022;
	int price2 = 50;
	char* company2 = "�Ե�ȸ��";


	// ����ü ���� �����ϱ� > struct ����ü�� ������;
	struct GameInfo gameInfo1;	// ����ü ����

	// ����ü ��� ����
	gameInfo1.name = "����ü����";
	gameInfo1.year = 2024;
	gameInfo1.price = 100;
	gameInfo1.company = "����ü����ȸ��";

	// ����ü ��� ��� (����� Ÿ�Կ� �°� ���)
	printf(" ================= ���� ��� ���� ================= \n");
	printf("���� �̸� : %s\n", gameInfo1.name);
	printf("�߸� �⵵ : %d\n", gameInfo1.year);
	printf("���� ���� : %d\n", gameInfo1.price);
	printf("���� ȸ�� : %s\n", gameInfo1.company);

	// ����ü ��� �� ���ϰ� �����ϱ�
	struct GameInfo gameInfo2 = { "���Ѱ���", 2030, 3000, "���Ѱ���ȸ��" };
	printf("\n\n ================= ���� ��� ���� ================= \n");
	printf("���� �̸� : %s\n", gameInfo2.name);
	printf("�߸� �⵵ : %d\n", gameInfo2.year);
	printf("���� ���� : %d\n", gameInfo2.price);
	printf("���� ȸ�� : %s\n", gameInfo2.company);

	// ����ü �迭 �����
	// struct ����ü�� �迭��[�迭ũ��];

	struct GameInfo gameArray[2] = {
		{"�迭����", 2023, 10, "�迭����ȸ��"},
		{"�迭������", 2024, 100, "�迭����ȸ����"},
	};

	printf("\n\n ================= ���� ��� ���� ================= \n");
	printf("���� �̸� : %s\n", gameArray[0].name);
	printf("�߸� �⵵ : %d\n", gameArray[0].year);
	printf("���� ���� : %d\n", gameArray[0].price);
	printf("���� ȸ�� : %s\n", gameArray[0].company);


	// ����ü ������ ����ϱ� > ����ü ������ : ����ü ������ �ּҸ� ����Ű�� ����
	// struct ����ü�� * ������;

	struct GameInfo * gamePtr;	// ����ü ������ ���� ����
	gamePtr = &gameInfo1;
	printf("\n\n ================= ���� ��� ���� ================= \n");
	printf("���� �̸� : %s\n", (*gamePtr).name);
	printf("�߸� �⵵ : %d\n", (*gamePtr).year);
	printf("���� ���� : %d\n", gamePtr -> price);	// ȭ��ǥ, ������� ���� �����ڸ� ����ϸ� �������� �� ����
	printf("���� ȸ�� : %s\n", gamePtr -> company);


	// ����ü ���� ����ü
	struct GameInfo game1 = {"��մ°���", 2025, 13000, "��մ°���ȸ��"};
	struct GameInfo game2 = { "��..����", 2022, 3000, "�׳ɰ���ȸ��" };
	game1.friendGame = &game2;
	// friendGame�� GameInfo ����ü �ȿ� ����� �����ϴ� ����ü ������
	printf("\n\n ================= ���� ��� ���� ================= \n");
	printf("���� �̸� : %s\n", game1.friendGame -> name);
	printf("�߸� �⵵ : %d\n", game1.friendGame -> year);
	printf("���� ���� : %d\n", game1.friendGame -> price);
	printf("���� ȸ�� : %s\n", game1.friendGame -> company);

	return 0;
}