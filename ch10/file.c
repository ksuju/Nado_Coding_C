#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000	// 코드 내에서 MAX라는 값이 사용되면 숫자 10000으로 치환, 배열을 선언할 때 사용함

int main(void) {
	// fputs() 함수로 파일 쓰기
	// 1. fopen() 함수를 통해 파일에 대한 정보를 담는다.
	// FILE * 포인터명 = fopen(파일명, 파일모드);
	
	//FILE* file = fopen("C:\\test\\test1.txt", "wb");	// 쓰기 전용
	//if (file == NULL) {
	//	printf("파일 열기 실패\n");
	//	return 1;
	//}
	//fputs("fputs() 함수로 글을 써 보자\n", file);
	//fputs("잘 써지니?\n", file);
	//fputs("잘 써지네?\n", file);

	//fclose(file);	// fopen() 함수로 작업하고 나면 파일을 반드시 닫아야 함!


	// 2. fgets() 함수로 파일 읽기
	//char line[MAX] = { 0 };
	//FILE* file = fopen("C:\\test\\test1.txt", "rb");	// 읽기 전용
	//if (file == NULL) {
	//	printf("파일 열기 실패\n");
	//	return 1;
	//}
	//while (fgets(line, MAX, file) != NULL) {
	//	printf("%s", line);
	//}
	//fclose(file);



	// 3. 형식을 지정해 파일 입출력하기 (fprintf, fscanf)
	// fprintf (파일포인터, "서식지정자", 값);
	// fscanf (파일포인터, "서식지정자", &변수명);

	// 3-1 : fprintf 함수로 파일 쓰기
	//FILE * file = fopen("C:\\test\\test2.txt", "wb");	// 파일 생성, 파일 포인터 얻기
	//
	//if (file == NULL) {
	//	printf("파일 열기 실패\n");
	//	return 1;
	//}

	//fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호", 1, 2, 3, 4, 5, 6);
	//fprintf(file, "%s %d\n", "보너스번호", 7);


	// 3-2 : fscanf()함수로 파일 읽기
	char str1[MAX];
	char str2[MAX];
	int num[6] = {0, 0, 0, 0, 0, 0};
	int bonus = 0;

	FILE * file = fopen("C:\\test\\test2.txt", "rb");
	if (file == NULL) {
		printf("파일 열기 실패\n");
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