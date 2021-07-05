#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning
#include "Sort.h"

void printArr(int arr[], int n)
{
	printf("[ ");
	for (int i = 0; i < n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n"); 
}

// 무작위 배열 1 ~ n 범위
void genRandom(int arr[], int n)
{
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}

// 오름차순 배열 생성
void genIncSorted(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
}

// 내림차순 배열 생성
void genDecSorted(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = n - i;
}

// 배열섞기
void shuffleArr(int arr[], int n)
{
	srand(time(NULL));
	if (n > 1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			// i 와 임의의 i 오른쪽의 j번재와 swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

// 정렬함수 성능 측정
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle)
{
	clock_t start, end;
	start = clock();
	sort(arr, n); // 정렬 수행
	end = clock();
	printf("%s (size: %d) 수행결과: %ld ms\n", szTitle, n, end - start);
}



void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;
	
	// cycle 회전 횟수
	for (i = 0; i < n - 1; i++) 
	{
		//  비교횟수
		for (j = 0; j < (n - i) - 1; j++)
		{
			// 1. 인접한 두개 비교
			if (arr[j] > arr[j + 1])   // 2. 크기가 반대라면  <<비교>>
			{                          // 값 교환 (swap)
				temp = arr[j];         // <<이동>>  한 사이클당 최대 (n - i) - 1 번 발생
				arr[j] = arr[j + 1];   // <<이동>>
				arr[j + 1] = temp;     // <<이동>>
			}
		}

		// 중간과정 출력
		//printArr(arr, n);

	}
}


// 선택정렬
void SelectionSort(int arr[], int n)
{
	int i, j;
	int temp;
	int min_idx;

	// 사이클
	for (i = 0; i < n - 1; i++) // i는 0부터 n - 2 까지 사이클 진행 (n-1)번의 사이클
	{

		// i번째 우측(i + 1) 부터 시작하여 우측에서 i번째 보다 작은 것중 가장 최솟값을 찾을거다.
		// 최솟값의 위치 (min_idx) 를 '선택' 하는 것이 목표다!
		min_idx = i;

		// [i+1, .. n-1] 범위에서 '가장 작은 값의 위치 min_idx' 를 찾는다.
		for(j = i + 1; j < n; j++)  // 최솟값 탐색
		{
			if (arr[min_idx] > arr[j])  // 기존의 min_idx번째 값보다 더 작은 값이 발견되었다면? <<비교>>
				min_idx = j;            // min_idx 를 이번에 발견한 더 작은 값으로 '선택' 하기
		}

		// for문이 끝나면
		// min_idx 의 값은 i번째 이후의 원소 중에서 가장 작은 값을 가리키고 있을것이다.
		// 그러면, i값과 min_idx 값을 교환하면 된다.
		if (i != min_idx) {  // i 보다 작은 값이 발견되지 않았다면 pass
			temp = arr[i];         // <<이동>>  <-- 1 cycle 당 많아야 1번 발생
			arr[i] = arr[min_idx]; // <<이동>>
			arr[min_idx] = temp;   // <<이동>>
		}

		// 중간단계 출력
		//printArr(arr, n);
	}

}

// 삽입정렬
void InsertionSort(int arr[], int n)
{
	int insData;

	for(int i = 1; i < n; i++)  // i = 1 부터 시작!
	{
		insData = arr[i];  // i번재 데이터 선택(insData 에 임시 저장), 나중에 INSERT 될 위치 정해지면 그 자리에 '삽입'

		int j;
		for (j = i - 1; j >= 0; j--) // j 를 i 왼쪽부터 왼쪽으로 검색해 감
		{
			if (arr[j] > insData) // 삽입하려는 데이터 insData 보다 j번째 데이터가 크면  <<비교>>
				arr[j + 1] = arr[j];  // j번재 데이터를 우측으로 한칸씩 이동   <<이동>>
			else
				break;  // 멈춘 그곳이 바로 삽입될 위치,
		}

		// 결정된 j 위치의 바로 오른쪽이 삽입(INSERT) 될 위치
		arr[j + 1] = insData;  // 찾은 위치에 정렬 대상 삽입  << 이동>>  1 cycle 당 1번

		// 중간과정 출력
		//printArr(arr, n);
	}

}