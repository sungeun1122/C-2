#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "QuickSort.h"

// �迭 �ΰ��� �ٲٱ�
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// �迭 ���� ���� �ɰ��� (�ɰ� index ����)
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];  // �ǹ��� ��ġ�� ���� ����! (��)
	int low = left + 1;  // low �� �ǹ� �����ʿ��� ���� (�ε���)
	int high = right;    // high �� right ���� ����. (�ε���)


	// TODO


	return high;  // �Ű��� �ǹ��� ��ġ����(�ε���) ����
}

// ��������� ������ ����
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);  // pivot ���ϰ�, �ѷ� �ɰ�
		QuickSort(arr, left, pivot - 1);  // pivot ���� ������ ������
		QuickSort(arr, pivot + 1, right);  // pivot ������ ������ ������
	}
}