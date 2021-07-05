#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "QuickSort.h"

// 배열 두개값 바꾸기
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// 배열 정렬 영역 쪼개기 (쪼갤 index 리턴)
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];  // 피벗의 위치는 가장 왼쪽! (값)
	int low = left + 1;  // low 는 피벗 오른쪽에서 시작 (인덱스)
	int high = right;    // high 는 right 부터 시작. (인덱스)


	// TODO


	return high;  // 옮겨진 피벗의 위치정보(인덱스) 리턴
}

// 재귀적으로 퀵정렬 수행
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);  // pivot 정하고, 둘로 쪼갬
		QuickSort(arr, left, pivot - 1);  // pivot 왼쪽 영역을 퀵정렬
		QuickSort(arr, pivot + 1, right);  // pivot 오른쪽 영역을 퀵정렬
	}
}