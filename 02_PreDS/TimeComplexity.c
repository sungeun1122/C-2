#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

typedef void fnAction(int);  // ������ �Լ� Ÿ��

void chkTime(char *szTitle, fnAction action, int dataSize) 
{
	clock_t start, end;
	long result;

	printf("%s : size[%d] ��������\n", szTitle, dataSize);
	start = clock();  // �ð� ���� ����

	action(dataSize);

	end = clock();  // �ð� ���� ��
	result = end - start;
	printf("%s : size[%d] ����ð� %ld ms\n", szTitle, dataSize, result);
}



void func1(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) { 
		sum++; 
	}
}

void func2(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum++;
		}
	}
}

void func3(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				sum++;
			}
		}
	}
}


int main()
{
	int size;
	{
		size = 10000000;
		chkTime("O(n)", func1, size);
		chkTime("O(n)", func1, size * 2);
		chkTime("O(n)", func1, size * 4);
	}

	{
		size = 10000;
		chkTime("O(n^2)", func2, size);
		chkTime("O(n^2)", func2, size * 2);
		chkTime("O(n^2)", func2, size * 4);
	}

	{
		size = 500;
		chkTime("O(n^3)", func3, size);
		chkTime("O(n^3)", func3, size * 2);
		chkTime("O(n^3)", func3, size * 4);
	}


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}