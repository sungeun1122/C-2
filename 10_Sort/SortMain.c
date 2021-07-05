#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning


#define DATA_SIZE 80000

#include "Sort.h"
#include "Heap.h"


int main()
{
	int length;

	//printf("BubbleSort ����\n");
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

	//printf("\nSelectionSort ����\n");
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

	//printf("\nInsertionSort ����\n");
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

	//{ // ����� �Լ� ���� Ȯ��
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
	//	genRandom(srcArr, DATA_SIZE);  // ���� ����
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "��������");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "��������");
	//}


	//--------------------------------------------------------
	//printf("\nWORST vs. BEST case\n");
	//{
	//	int srcArr[DATA_SIZE];
	//	//genRandom(srcArr, DATA_SIZE);  // 1. ����
	//	//genIncSorted(srcArr, DATA_SIZE);  // 2. �������� �̹� ���ĵ� �迭
	//	genDecSorted(srcArr, DATA_SIZE);  // 3. ��������, �����ĵ� �迭
	//	int workArr[DATA_SIZE];

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(BubbleSort, workArr, DATA_SIZE, "��������");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(SelectionSort, workArr, DATA_SIZE, "���ÿ�����");

	//	memcpy(workArr, srcArr, sizeof(int) * DATA_SIZE);
	//	chkTimeLap(InsertionSort, workArr, DATA_SIZE, "���Կ�����");
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

		//printArr(workArr, DATA_SIZE); // ������

		chkTimeLap(HeapSort, workArr, DATA_SIZE, "������");

		//printArr(workArr, DATA_SIZE); // ������

		heap_destroy(&hp);
	}


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}

/*
�������� (size: 20000) ������: 829 ms
�������� (size: 20000) ������: 383 ms
�������� (size: 20000) ������: 178 ms

�������� (size: 40000) ������: 3424 ms
�������� (size: 40000) ������: 1520 ms
�������� (size: 40000) ������: 650 ms

�������� (size: 80000) ������: 12992 ms
�������� (size: 80000) ������: 6117 ms
�������� (size: 80000) ������: 1964 ms

--------------------------------------
WORST vs. BEST case
������ (size: 20000) ������: 834 ms
���÷��� (size: 20000) ������: 378 ms
���Է��� (size: 20000) ������: 174 ms

������� (size: 20000) ������: 439 ms
���ÿ��� (size: 20000) ������: 387 ms
���Կ��� (size: 20000) ������: 0 ms

�������� (size: 20000) ������: 607 ms
���ÿ����� (size: 20000) ������: 346 ms
���Կ����� (size: 20000) ������: 396 ms

HeapSort
������ (size: 20000) ������: 6 ms
������ (size: 40000) ������: 13 ms
������ (size: 80000) ������: 26 ms

*/