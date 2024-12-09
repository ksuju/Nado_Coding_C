//#include <stdio.h>
//
//int array(void) {
//
//	// 배열 선언하기
//	// 자료형 배열명 [배열크기];
//	// 배열크기에는 항상 상수만 넣을 수 있다!
//	// 배열을 선언하면 항상 초기화 해야함
//	int subway_array[3];
//
//	subway_array[0] = 10;
//	subway_array[1] = 20;
//	subway_array[2] = 30;
//	
//	// 배열 길이 구하기 ***
//	// 자바와는 다름! length 메서드가 없음!
//	// sizeof(int 배열) = int 자료형의 크기 4 * 배열의 길이임 (배열 전체의 바이트 크기를 반환)
//	// 따라서 아래와 같이 연산을 해줘야 정확한 길이를 알 수 있음
//	int array_length = sizeof(subway_array) / sizeof(int);
//
//	for (int i = 0; i < array_length; i++) {
//		printf("지하철 %d호차에 %d명이 타고 있습니다.\n", i + 1, subway_array[i]);
//	}
//
//
//	// 일부값 초기화
//	// 크기가 10인 배열에 3개만 초기화 할 경우? 1, 2, 3, 0, 0 ~~~ 이렇게 초기화됨
//	int arr[10] = { 1, 2, 3 };
//
//	int arr_length = sizeof(arr) / sizeof(int);
//
//	for (int i = 0; i < arr_length; i++) {
//		printf("%d\n", arr[i]);
//	}
//
//	// 배열 크기란을 비울 경우?
//	// 초기화한 배열의 크기만큼 배열이 생성됨
//	// arr2 의 배열 길이는 2
//	int arr2[] = { 1, 2 };
//
//
//	// 실수형 배열 초기화
//	// 방법 같음
//	float floatArr[] = { 1.0f, 2.0f, 3.0f };
//	int floatArr_length = sizeof(floatArr) / sizeof(float);	// float의 크기로 나눔 (자료형에 맞게 수정)
//	for (int i = 0; i < floatArr_length; i++) {
//		printf("%.2f\n", floatArr[i]);
//	}
//
//
//	// 배열에 문자열 저장하기
//	// 배열 크기와 글자수가 같으면 글자가 깨짐!
//	// 문자열 끝에 NULL이 들어갈 공간이 최소 한칸 필요!
//	char str_x[6] = "coding";	// X
//	char str_o[7] = "coding";	// O
//	printf("str_x : %s\n", str_x);	// 문자 데이터 손상
//	printf("str_o : %s\n", str_o);	// 정상 출력
//
//
//	char str[] = "coding";	// 이렇게 초기화 하면 편함
//	printf("str : %s\n", str);
//
//
//	// 문자열 입력받기 (복습)
//	// scanf_s를 사용하기 위해서는 반드시 배열의 크기를 명시해야함
//	char name[256];
//	printf("이름이 뭐예요? ");
//	scanf_s("%s", name, sizeof(name));
//	printf("%s\n", name);
//
//	return 0;
//}