#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#define MAX_LENGTH 4

#define TRUE 1
#define FALSE 0

typedef struct _IterArray
{
	int arr[MAX_LENGTH];
	int curPosition;   // iterator 구현을 위한 값
} IterArray;

// iterator 초기화
void iter_init(IterArray *p)
{
	printf("Iterator 초기화\n");
	p->curPosition = -1;  
}

// 다음에 추출할 데이터 있나?
int iter_hasNext(IterArray *p)
{
	if (p->curPosition + 1 < MAX_LENGTH)
	{
		return TRUE;
	}
	else
	{
		printf("더 이상 추출할 데이터가 없습니다\n");
		return FALSE;
	}
}

// 다음 데이터 추출
int iter_next(IterArray *p)
{
	p->curPosition++;  // 우선! curPosition 이 next 로 +1 증가
	return p->arr[p->curPosition];  // curPosition 이 가리키는 곳의 값 추출
}

int main()
{
	IterArray data = { {10, 20, 30, 40}, -1 };
	iter_init(&data);

	while (iter_hasNext(&data)) // 더 추출할 데이터가 있나?
	{
		printf("%d ", iter_next(&data));  // 추출
	}
	printf("\n");


	// 다시 iterator 를 돌리려 하면...
	while (iter_hasNext(&data)) 
	{
		printf("%d ", iter_next(&data));  
	}
	printf("\n");

	// 다시 iterator 를 돌리려면 새로이 초기화 하여 동작시켜야 한다
	iter_init(&data);
	while (iter_hasNext(&data))
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}

/* 거의 대부분의 현대 언어들에선 Iteration(반복자) 지원함.
*
*	Python 의 iterable객체
*		ex) for a in b:  <-- b 는 'iterable' 해야 한다.
*
*	Java
*		Enhanced-for. ex) for(int n : list)
*		Collection 의 Iterator 객체
*
*	JavaScript
*		for ~ in
*		for ~ of
*		forEach
*	C++
*		iterator
*/