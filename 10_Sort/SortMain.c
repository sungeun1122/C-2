#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "Sort.h"

int main()
{
	int length;

	printf("BubbleSort 동작\n");
	{
		int data[] = { 3, 2, 7, 5, 1 };
		length = sizeof(data) / sizeof(int);
		BubbleSort(data, length);  // -> {1, 2, 3, 5, 7}
		printArr(data, length);
	}
	{
		int data[] = { 11, 3, 28, 43, 9, 4 };
		length = sizeof(data) / sizeof(int);
		BubbleSort(data, length);
		printArr(data, length);
	}

	printf("\nSelectionSort 동작\n");
	{
		int data[] = { 29, 10, 14, 37, 13 };
		length = sizeof(data) / sizeof(int);
		SelectionSort(data, length);
		printArr(data, length);
	}
	{
		int data[] = { 11, 3, 28, 43, 9, 4 };
		length = sizeof(data) / sizeof(int);
		SelectionSort(data, length);
		printArr(data, length);
	}



	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}