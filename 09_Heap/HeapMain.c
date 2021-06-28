#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "Heap.h"

int DataPriorityComp(HData ch1, HData ch2)
{
	//return ch2 - ch1;  // min-heap
	return ch1 - ch2;  // max-head
}


int main()
{
	Heap heap;
	heap_init(&heap, DataPriorityComp);

	heap_insert(&heap, 9);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);
	
	// MIN-HEAP 
	//      (9)
	//     ↙  ↘
	//   (20)   (30)

	// MAX-HEAP 
	//      (30)
	//     ↙  ↘
	//   (9)    (20)

	printf("%d \n", heap_delete(&heap));  // MAX-HEAP => 30,  MIN-HEAP => 9
	printf("%d \n", heap_delete(&heap));  //           20
	printf("%d \n", heap_delete(&heap));  //           10 


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}