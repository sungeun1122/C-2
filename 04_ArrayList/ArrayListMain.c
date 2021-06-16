#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "ArrayList.h"

void printList(List *pList)
{
	list_init_iter(pList);  // iteration 시작
	printf("[ ");
	while (list_hasNext(pList))
	{
		printf("%d,", list_next(pList));
	}
	printf("\b]\n");
}


int main()
{
	List myList;
	list_init(&myList);  // 리스트 생성

	printList(&myList);      // []
	list_add(&myList, 100);  // 데이터 추가
	printList(&myList);		// [100]
	list_add(&myList, 50);  // 데이터 추가
	printList(&myList);		// [100, 50]
	list_add(&myList, 100);
	printList(&myList);		// [100, 50, 100]
	list_add(&myList, 20);
	printList(&myList);		// [100, 50, 100, 20]
	list_add(&myList, 45);
	printList(&myList);		// 데이터 추가 - 실패
	list_add(&myList, 70);
	printList(&myList);  	// 데이터 추가 - 실패


	// 데이터 수정
	list_set(&myList, 0, 40);  // 0번째 데이터를 100 --> 40으로 수정
	list_set(&myList, 1, 30);  
	list_set(&myList, 4, 30);  // 수정 실패
	printList(&myList);       // [40, 30, 100, 20]

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList));  // 4

	// n번째 데이터 조회
	Data data;
	if (list_get(&myList, 0, &data)) printf("0번째 : %d\n", data);  // 40
	if (list_get(&myList, 6, &data)) printf("6번째 : %d\n", data);  // 실패
	if (list_get(&myList, 2, &data)) printf("2번째 : %d\n", data);  // 100

	// 데이터 삭제
	printf("삭제전\n");
	printList(&myList);  // [40, 30, 100, 20]

	list_remove(&myList, 2);
	printList(&myList);  // [40, 30, 20]
	list_remove(&myList, 2);
	printList(&myList);  // [40, 30]
	printf("데이터 개수는 %d\n", list_length(&myList));   // 2
	list_remove(&myList, 0);
	printList(&myList);  // [30]
	list_remove(&myList, 0);
	printList(&myList);  // []
	list_remove(&myList, 0);   // 실패
	list_remove(&myList, 0);   // 실패
	printf("데이터 개수는 %d\n", list_length(&myList));  // 0


	// insert 
	printf("---------------------------\n");
	list_add(&myList, 10);
	list_add(&myList, 20);
	printList(&myList);    // [10, 20]
	list_insert(&myList, 1, 40);
	printList(&myList);    // [10, 40, 20]
	list_insert(&myList, 0, 5);
	printList(&myList);    // [5, 10, 40, 20]
	list_insert(&myList, 0, 5);  // 실패
	printf("데이터 개수는 %d\n", list_length(&myList));  // 4


	list_init(&myList);
	list_insert(&myList, 0, 5);   // insert 는 list 의 끝에 추가(add) 가능하게 동작시키기
	printList(&myList);    // [5]
	list_insert(&myList, 1, 25);
	printList(&myList);    // [5, 25]
	list_insert(&myList, 2, 45);
	printList(&myList);    // [5, 25, 45]


		
	list_destroy(&myList);  // 리스트 제거
	
	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}