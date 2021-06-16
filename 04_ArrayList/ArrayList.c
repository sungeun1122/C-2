#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "ArrayList.h"

// 리스트 초기화
void list_init(List *pList)
{
	pList->numData = 0;
	pList->curPosition = -1;  // for iteration
	memset(pList->arr, 0, sizeof(pList->arr));  // 배열을 전부 0으로 초기화
	printf("리스트 초기화\n");
}

// 리스트 제거
void list_destroy(List *pList)
{
	pList->numData = 0;
	printf("리스트 제거\n");
}

// 데이터 추가
int list_add(List *pList, Data data)
{
	if (pList->numData >= LIST_LEN)
	{
		printf("데이터 추가 불가\n");
		return FAIL;
	}

	pList->arr[pList->numData] = data;   // 데이터 추가

	printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);
	(pList->numData)++;  // 데이터 개수 증가
	return SUCCESS;
}

// n번째 데이터 삭제
int list_remove(List *pList, int n);

// n번째 데이터 수정
int list_set(List *pList, int n, Data data);

// 데이터 개수
int list_length(List *pList);

// 데이터 조회, iteration 초기화
void list_init_iter(List *pList);

// 데이터 조회, iteration 다음 데이터 추출?
Data list_next(List *pList);

// 데이터 조회, iteration 다음 데이터 있나?
int list_hasNext(List *pList);

// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List *pList, int n, Data *pData);






