#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "Sort.h"

int main()
{
	int length;

	printf("BubbleSort ����\n");
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

	printf("\nSelectionSort ����\n");
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



	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}