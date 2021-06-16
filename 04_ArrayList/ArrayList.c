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
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
	{
		printf("[%d] 번째 데이터 삭제 실패\n", n);
		return FAIL;
	}

	// 배열이니까, 중간의 데이터를 삭제하면 뒤의 것들을 당겨와야 한다.
	for (int i = n; i < pList->numData - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->numData--;  // 리스트 size 감소

	printf("%d 번째 데이터 삭제\n", n);

	return SUCCESS;
}

// n번째 데이터 수정
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) {
		printf("%d 번째 데이터 수정 실패\n", n);
		return FAIL;
	}

	printf("[%d] 번째 데이터 수정 %d --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;  // 수정
	return SUCCESS;
}

// 데이터 개수
int list_length(List *pList)
{
	return pList->numData;
}

// 데이터 조회, iteration 초기화
void list_init_iter(List *pList)
{
	pList->curPosition = -1;
}

// 데이터 조회, iteration 다음 데이터 추출?
Data list_next(List *pList)
{
	pList->curPosition++;
	Data result = pList->arr[pList->curPosition];
	return result;
}

// 데이터 조회, iteration 다음 데이터 있나?
int list_hasNext(List *pList)
{
	if (pList->curPosition + 1 < pList->numData)
		return SUCCESS;

	return FAIL;
}

// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) return FAIL;

	*pData = pList->arr[n];  // n번째 데이터값을 pData 를 통해 전달 Call By Reference

	return SUCCESS;
}


// 데이터 삽입 : n번째 위치에 데이터 삽입
int list_insert(List *pList, int n, Data data)
{
	// 이미 리스트가 다 찼으면 insert 불가
	if (pList->numData >= LIST_LEN)
	{
		printf("데이터 삽입 불가\n");
		return FAIL;
	}

	// n 유효범위 검증 (insert 가능한곳은 '중간' , '끝')
	if (n > pList->numData)
	{
		printf("[%d] 번째 위치에 삽입 불가\n", n);
		return FAIL;
	}

	// 기존의 n번째 부터 한칸씩 뒤로 밀려나야 한다.
	// 맨 뒤에서부터!!! 부터 n 앞의 것들은 한칸씩 우측으로 복사
	for (int i = pList->numData; i - 1 >= n; i--)
	{
		pList->arr[i] = pList->arr[i - 1];
	}

	// n번째에 새 data 삽입
	pList->arr[n] = data;

	// 데이터 개수 증가
	pList->numData++;

	printf("[%d] 번재 데이터 %d 삽입 성공\n", n, data);

	return SUCCESS;
}





