#ifndef __SORT_H__
#define __SORT_H__

void printArr(int arr[], int n);

// 무작위 배열 1 ~ n 범위
void genRandom(int arr[], int n);

// 오름차순 배열 생성
void genIncSorted(int arr[], int n);

// 내림차순 배열 생성
void genDecSorted(int arr[], int n);

// 배열섞기
void shuffleArr(int arr[], int n);

// 정렬함수 성능 측정
typedef void fnSort(int arr[], int n);
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle);

//-------------------------------------------------
void BubbleSort(int arr[], int n);  // 버블정렬
void SelectionSort(int arr[], int n);  // 선택정렬
void InsertionSort(int arr[], int n);  // 삽입정렬





#endif