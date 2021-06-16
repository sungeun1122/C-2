#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "ArrayList.h"


int main()
{
	List myList;
	list_init(&myList);  // 리스트 생성

	list_add(&myList, 100);  // 데이터 추가
								// [100]
	list_add(&myList, 50);  // 데이터 추가
								// [100, 50]
	list_add(&myList, 100);
							// [100, 50, 100]
	list_add(&myList, 20);
							// [100, 50, 100, 20]
	list_add(&myList, 45);
							// 데이터 추가 - 실패
	list_add(&myList, 70);
							// 데이터 추가 - 실패


	list_destroy(&myList);  // 리스트 제거
	
	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}