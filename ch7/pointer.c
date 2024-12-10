#include <stdio.h>

static void swap(int a, int b);	// 실습1-1.
static void swap_address(int* a, int* b);	// 실습1-2.

static void changeArray(int* arr);	// 실습 2
int main(void) {
	int 철수 = 1;
	int 영희 = 2;
	int 민수 = 3;

	printf("철수네 주소 : %p, 암호 : %d\n", &철수, 철수);


	// 포인터 변수 : 메모리의 주소값을 저장하는 변수
	// 자료형 * 변수명; (일반적으로 띄어쓰지만 붙여써도 괜찮음)

	int * 미션맨; // 포인터변수 미션맨
	미션맨 = &철수;	// 변수의 메모리 주소는 변수명 앞에 &를 붙이면 확인 가능

	// 미션맨 = 변수가 가리키는 주소 (철수의 주소)
	// *미션맨 = 변수의 값 (철수의 값)
	printf("미션맨이 방문한 곳의 주소 : %p, 암호 : %d\n", 미션맨, *미션맨);

	// 포인터로 다른 변수의 값 바꾸기
	*미션맨 = *미션맨 * 3;
	printf("미션맨이 암호를 바꾼 곳의 주소 : %p, 암호 : %d\n", 미션맨, *미션맨);

	// 새로운 포인터 변수, 포인터변수 2개는 같은 주소! 즉 하나의 메모리 공간을 가리킬 수 있음!
	int* 스파이 = 미션맨;
	printf("스파이가 알아낸 미션맨의 주소 : %p, 암호 : %d\n", 스파이, *스파이);


	// 포인터로 배열에 접근하기
	int arr[3] = { 5, 10, 15 };	// 일반 배열
	for (int i = 0; i < 3; i++) {
		printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
	}

	int* ptr = arr;	// 포인터 변수에 배열 넣음
	for (int i = 0; i < 3; i++) {
		printf("포인터 변수 ptr[%d]의 값 : %d\n", i, ptr[i]);
	}

	ptr[0] = 100;	// 포인터 변수의 값을 바꾸면, 포인터 변수가 가리키는 배열의 값 또한 바뀐다!
	for (int i = 0; i < 3; i++) {
		printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
	}
	for (int i = 0; i < 3; i++) {
		printf("(방법 1)포인터 변수 ptr[%d]의 값 : %d\n", i, ptr[i]);
		printf("(방법 2)포인터 변수 ptr[%d]의 값 : %d\n", i, *(ptr + i));
	}

	// 실습 1 시작
	int a = 10;
	int b = 20;

	swap(a, b);

	printf("swap() 함수 이후 a의 값, 값에 의한 호출 : %d, b의 값 : %d\n\n", a, b);

	// a와 b의 변수 주소를 매개변수로
	swap_address(&a, &b);

	printf("swap_address() 함수 이후 a의 값, 참조에 의한 호출 : %d, b의 값 : %d\n\n\n\n\n", a, b);
	// 실습 1 끝


	// 실습 2 시작
	int arr2[3] = { 10, 20, 30 };
	changeArray(arr2);
	
	for (int i = 0; i < 3; i++) {
		printf("arr배열의 값 : %d\n", arr2[i]);
	}
	// 실습 2 끝

	return 0;
}

// 실습 1. 포인터로 두 변수의 값 교환하기
	// 실습 1-1. 일반 변수를 매개변수로
static void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	printf("\n\n\n일반 swap() 함수 안 => a : %d, b: %d\n\n", a, b);
}
// 1-1 에서는 단순 값만 매개변수로 넘겨줌, 즉 swap 함수 안에서 값이 변경되더라도 main함수의 출력에는 영향 X

	// 실습 1-2. 포인터 변수를 매개변수로 (a와 b의 변수 주소를 받음)
static void swap_address(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("포인터 swap_address() 함수 안 => a : %d, b: %d\n\n", *a, *b);
}
// 1-2 에서는 객체 주소 자체를 매개변수로 넘겨줌, 즉 swap_address()와 main 함수의 a라는 객체의 주소가 같음!
// 주소가 같기 때문에 swap_address() 함수에서 값이 변경되면, main 함수에서의 값 또한 변경됨!


// 자바의 얕은복사와 깊은복사의 차이랑 비슷



// 실습 2 : 포인터로 배열의 값 바꾸기
static void changeArray(int* arr) {
	arr[2] = 50;
};