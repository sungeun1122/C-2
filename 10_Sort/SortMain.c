#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning


#define DATA_SIZE 80000

#include "Sort.h"
#include "Heap.h"


int main()
{
	int length;

	//printf("BubbleSort 동작\n");
	//{
	//	int data[] = { 3, 2, 7, 5, 1 };
	//	length = sizeof(data) / sizeof(int);
	//	BubbleSort(data, length);  // -> {1, 2, 3, 5, 7}
	//	printArr(data, length);
	//}
	//{
	//	int data[] = { 11, 3, 28, 43, 9, 4 };
	//	length = sizeof(data) / sizeof(int);
	//	BubbleSort(data, length);
	//	printArr(data, length);
	//}

	//printf("\nSelectionSort 동작\n");
	//{
	//	int data[] = { 29, 10, 14, 37, 13 };
	//	length = sizeof(data) / sizeof(int);
	//	SelectionSort(data, length);
	//	printArr(data, length);
	//}
	//{
	//	int data[] = { 11, 3, 28, 43, 9, 4 };
	//	length = sizeof(data) / sizeof(int);
	//	SelectionSort(data, length);
	//	printArr(data, length);
	//}

	//printf("\nInsertionSort 동작\n");
	//{
	//	int data[] = { 29, 10, 14, 37, 13 };
	//	length = sizeof(data) / sizeof(int);
	//	InsertionSort(data, length);
	//	printArr(data, length);
	//}
	//{
	//	int data[] = { 28, 3, 11, 43, 9, 4 };
	//	length = sizeof(data) / sizeof(int);
	//	InsertionSort(data, length);
	//	printArr(data, length);
	//}

	//{
	//	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//	for (int i = 0; i < 5; i++) {
	//		shuffleArr(data, 9);
	//		printArr(data, 9);
	//	}
	//}

	//{ // 도우미 함수 동작 확인
	//  	int srcArr[DATA_SIZE];
	//  	genRandom(srcArr, DATA_SIZE);
	//  	printArr(srcArr, DATA_SIZE);
	//  	genIncSorted(srcArr, DATA_SIZE);
	//  	printArr(srcArr, DATA_SIZE);
	//  	genDecSorted(srcArr, DATA_SIZE);
	//  	printArr(srcArr, DATA_SIZE);
	//}

	//------------------------------------------------
	//printf("\nTime Complexity\n");
	//{
	//	int srcArr[DATA_SIZE];
	//	genRandom(srcArr, DATA_SIZE);  // 랜덤 생성
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입정렬");
	//}


	//--------------------------------------------------------
	//printf("\nWORST vs. BEST case\n");
	//{
	//	int srcArr[DATA_SIZE];
	//	//genRandom(srcArr, DATA_SIZE);  // 1. 랜덤
	//	//genIncSorted(srcArr, DATA_SIZE);  // 2. 오름차순 이미 정렬될 배열
	//	genDecSorted(srcArr, DATA_SIZE);  // 3. 내림차순, 역정렬된 배열
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "버블역정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "선택역정렬");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "삽입역정렬");
	//	
	//}

	//------------------------------------------------------
	printf("\nHeapSort\n");
	{
		int srcArr[DATA_SIZE];
		genRandom(srcArr, DATA_SIZE);

		int workArr[DATA_SIZE];
		memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);

		Heap hp;
		heap_init(&hp, DATA_SIZE);

		//printArr(workArr, DATA_SIZE); // 정렬전

		chkTimeLap(HeapSort, workArr, DATA_SIZE, "힙정렬");

		//printArr(workArr, DATA_SIZE); // 정렬후

		heap_destroy(&hp);
	}


	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}

/*
버블정렬 (size: 20000) 수행결과: 829 ms
선택정렬 (size: 20000) 수행결과: 383 ms
삽입정렬 (size: 20000) 수행결과: 178 ms

버블정렬 (size: 40000) 수행결과: 3424 ms
선택정렬 (size: 40000) 수행결과: 1520 ms
삽입정렬 (size: 40000) 수행결과: 650 ms

버블정렬 (size: 80000) 수행결과: 12992 ms
선택정렬 (size: 80000) 수행결과: 6117 ms
삽입정렬 (size: 80000) 수행결과: 1964 ms

--------------------------------------
WORST vs. BEST case
버블랜덤 (size: 20000) 수행결과: 834 ms
선택랜덤 (size: 20000) 수행결과: 378 ms
삽입랜덤 (size: 20000) 수행결과: 174 ms

버블오름 (size: 20000) 수행결과: 439 ms
선택오름 (size: 20000) 수행결과: 387 ms
삽입오름 (size: 20000) 수행결과: 0 ms

버블역정렬 (size: 20000) 수행결과: 607 ms
선택역정렬 (size: 20000) 수행결과: 346 ms
삽입역정렬 (size: 20000) 수행결과: 396 ms

HeapSort
힙정렬 (size: 20000) 수행결과: 6 ms
힙정렬 (size: 40000) 수행결과: 13 ms
힙정렬 (size: 80000) 수행결과: 26 ms

*/