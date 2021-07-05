#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning
#include "Sort.h"

void printArr(int arr[], int n)
{
	printf("[ ");
	for (int i = 0; i < n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n"); 
}

// ������ �迭 1 ~ n ����
void genRandom(int arr[], int n)
{
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}

// �������� �迭 ����
void genIncSorted(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
}

// �������� �迭 ����
void genDecSorted(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = n - i;
}

// �迭����
void shuffleArr(int arr[], int n)
{
	srand(time(NULL));
	if (n > 1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			// i �� ������ i �������� j����� swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

// �����Լ� ���� ����
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle)
{
	clock_t start, end;
	start = clock();
	sort(arr, n); // ���� ����
	end = clock();
	printf("%s (size: %d) ������: %ld ms\n", szTitle, n, end - start);
}



void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;
	
	// cycle ȸ�� Ƚ��
	for (i = 0; i < n - 1; i++) 
	{
		//  ��Ƚ��
		for (j = 0; j < (n - i) - 1; j++)
		{
			// 1. ������ �ΰ� ��
			if (arr[j] > arr[j + 1])   // 2. ũ�Ⱑ �ݴ���  <<��>>
			{                          // �� ��ȯ (swap)
				temp = arr[j];         // <<�̵�>>  �� ����Ŭ�� �ִ� (n - i) - 1 �� �߻�
				arr[j] = arr[j + 1];   // <<�̵�>>
				arr[j + 1] = temp;     // <<�̵�>>
			}
		}

		// �߰����� ���
		//printArr(arr, n);

	}
}


// ��������
void SelectionSort(int arr[], int n)
{
	int i, j;
	int temp;
	int min_idx;

	// ����Ŭ
	for (i = 0; i < n - 1; i++) // i�� 0���� n - 2 ���� ����Ŭ ���� (n-1)���� ����Ŭ
	{

		// i��° ����(i + 1) ���� �����Ͽ� �������� i��° ���� ���� ���� ���� �ּڰ��� ã���Ŵ�.
		// �ּڰ��� ��ġ (min_idx) �� '����' �ϴ� ���� ��ǥ��!
		min_idx = i;

		// [i+1, .. n-1] �������� '���� ���� ���� ��ġ min_idx' �� ã�´�.
		for(j = i + 1; j < n; j++)  // �ּڰ� Ž��
		{
			if (arr[min_idx] > arr[j])  // ������ min_idx��° ������ �� ���� ���� �߰ߵǾ��ٸ�? <<��>>
				min_idx = j;            // min_idx �� �̹��� �߰��� �� ���� ������ '����' �ϱ�
		}

		// for���� ������
		// min_idx �� ���� i��° ������ ���� �߿��� ���� ���� ���� ����Ű�� �������̴�.
		// �׷���, i���� min_idx ���� ��ȯ�ϸ� �ȴ�.
		if (i != min_idx) {  // i ���� ���� ���� �߰ߵ��� �ʾҴٸ� pass
			temp = arr[i];         // <<�̵�>>  <-- 1 cycle �� ���ƾ� 1�� �߻�
			arr[i] = arr[min_idx]; // <<�̵�>>
			arr[min_idx] = temp;   // <<�̵�>>
		}

		// �߰��ܰ� ���
		//printArr(arr, n);
	}

}

// ��������
void InsertionSort(int arr[], int n)
{
	int insData;

	for(int i = 1; i < n; i++)  // i = 1 ���� ����!
	{
		insData = arr[i];  // i���� ������ ����(insData �� �ӽ� ����), ���߿� INSERT �� ��ġ �������� �� �ڸ��� '����'

		int j;
		for (j = i - 1; j >= 0; j--) // j �� i ���ʺ��� �������� �˻��� ��
		{
			if (arr[j] > insData) // �����Ϸ��� ������ insData ���� j��° �����Ͱ� ũ��  <<��>>
				arr[j + 1] = arr[j];  // j���� �����͸� �������� ��ĭ�� �̵�   <<�̵�>>
			else
				break;  // ���� �װ��� �ٷ� ���Ե� ��ġ,
		}

		// ������ j ��ġ�� �ٷ� �������� ����(INSERT) �� ��ġ
		arr[j + 1] = insData;  // ã�� ��ġ�� ���� ��� ����  << �̵�>>  1 cycle �� 1��

		// �߰����� ���
		//printArr(arr, n);
	}

}