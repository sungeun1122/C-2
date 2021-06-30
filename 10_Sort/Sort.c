#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

void printArr(int arr[], int n)
{
	printf("[ ");
	for (int i = 0; i < n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n"); 
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
			if (arr[j] > arr[j + 1])   // 2. ũ�Ⱑ �ݴ���
			{                          // �� ��ȯ (swap)
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
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
			if (arr[min_idx] > arr[j])  // ������ min_idx��° ������ �� ���� ���� �߰ߵǾ��ٸ�?
				min_idx = j;            // min_idx �� �̹��� �߰��� �� ���� ������ '����' �ϱ�
		}

		// for���� ������
		// min_idx �� ���� i��° ������ ���� �߿��� ���� ���� ���� ����Ű�� �������̴�.
		// �׷���, i���� min_idx ���� ��ȯ�ϸ� �ȴ�.
		if (i != min_idx) {  // i ���� ���� ���� �߰ߵ��� �ʾҴٸ� pass
			temp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = temp;
		}

		// �߰��ܰ� ���
		//printArr(arr, n);
	}

}

// ��������
void InsertionSort(int arr[], int n)
{

}