#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "Stack.h"

int main()
{
	Stack stack;
	Data data;

	stack_init(&stack);  // Stack의 생성 및 초기화

	// 데이터 push 
	stack_push(&stack, 1);   //  1 ← (top)
	stack_push(&stack, 2);   //  1  2 ←
	stack_push(&stack, 3);   //  1  2  3 ←
	stack_push(&stack, 4);   //  1  2  3  4 ←
	stack_push(&stack, 5);   //  1  2  3  4  5 ←

	// 데이터 pop
	stack_pop(&stack, &data);
	printf("pop --> %d\n", data);  // 5
	stack_pop(&stack, &data);
	printf("pop --> %d\n", data);  // 4

	while (!stack_is_empty(&stack))  // 3 2 1
	{
		stack_pop(&stack, &data);
		printf("%d ", data);
	}
	printf("\n");

	stack_destroy(&stack);  // 스택제거

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}