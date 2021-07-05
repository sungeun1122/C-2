#ifndef __SORT_H__
#define __SORT_H__

void printArr(int arr[], int n);

// ������ �迭 1 ~ n ����
void genRandom(int arr[], int n);

// �������� �迭 ����
void genIncSorted(int arr[], int n);

// �������� �迭 ����
void genDecSorted(int arr[], int n);

// �迭����
void shuffleArr(int arr[], int n);

// �����Լ� ���� ����
typedef void fnSort(int arr[], int n);
void chkTimeLap(fnSort sort, int arr[], int n, char *szTitle);

//-------------------------------------------------
void BubbleSort(int arr[], int n);  // ��������
void SelectionSort(int arr[], int n);  // ��������
void InsertionSort(int arr[], int n);  // ��������





#endif