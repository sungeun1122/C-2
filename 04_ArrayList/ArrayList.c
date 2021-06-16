#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "ArrayList.h"

// ����Ʈ �ʱ�ȭ
void list_init(List *pList)
{
	pList->numData = 0;
	pList->curPosition = -1;  // for iteration
	memset(pList->arr, 0, sizeof(pList->arr));  // �迭�� ���� 0���� �ʱ�ȭ
	printf("����Ʈ �ʱ�ȭ\n");
}

// ����Ʈ ����
void list_destroy(List *pList)
{
	pList->numData = 0;
	printf("����Ʈ ����\n");
}

// ������ �߰�
int list_add(List *pList, Data data)
{
	if (pList->numData >= LIST_LEN)
	{
		printf("������ �߰� �Ұ�\n");
		return FAIL;
	}

	pList->arr[pList->numData] = data;   // ������ �߰�

	printf("[%d] ��° ������ %d �߰�\n", pList->numData, data);
	(pList->numData)++;  // ������ ���� ����
	return SUCCESS;
}

// n��° ������ ����
int list_remove(List *pList, int n)
{
	if (n >= pList->numData)
	{
		printf("[%d] ��° ������ ���� ����\n", n);
		return FAIL;
	}

	// �迭�̴ϱ�, �߰��� �����͸� �����ϸ� ���� �͵��� ��ܿ;� �Ѵ�.
	for (int i = n; i < pList->numData - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->numData--;  // ����Ʈ size ����

	printf("%d ��° ������ ����\n", n);

	return SUCCESS;
}

// n��° ������ ����
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) {
		printf("%d ��° ������ ���� ����\n", n);
		return FAIL;
	}

	printf("[%d] ��° ������ ���� %d --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;  // ����
	return SUCCESS;
}

// ������ ����
int list_length(List *pList)
{
	return pList->numData;
}

// ������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List *pList)
{
	pList->curPosition = -1;
}

// ������ ��ȸ, iteration ���� ������ ����?
Data list_next(List *pList)
{
	pList->curPosition++;
	Data result = pList->arr[pList->curPosition];
	return result;
}

// ������ ��ȸ, iteration ���� ������ �ֳ�?
int list_hasNext(List *pList)
{
	if (pList->curPosition + 1 < pList->numData)
		return SUCCESS;

	return FAIL;
}

// ������ ��ȸ : n��° ������ �� �б�
int list_get(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) return FAIL;

	*pData = pList->arr[n];  // n��° �����Ͱ��� pData �� ���� ���� Call By Reference

	return SUCCESS;
}


// ������ ���� : n��° ��ġ�� ������ ����
int list_insert(List *pList, int n, Data data)
{
	// �̹� ����Ʈ�� �� á���� insert �Ұ�
	if (pList->numData >= LIST_LEN)
	{
		printf("������ ���� �Ұ�\n");
		return FAIL;
	}

	// n ��ȿ���� ���� (insert �����Ѱ��� '�߰�' , '��')
	if (n > pList->numData)
	{
		printf("[%d] ��° ��ġ�� ���� �Ұ�\n", n);
		return FAIL;
	}

	// ������ n��° ���� ��ĭ�� �ڷ� �з����� �Ѵ�.
	// �� �ڿ�������!!! ���� n ���� �͵��� ��ĭ�� �������� ����
	for (int i = pList->numData; i - 1 >= n; i--)
	{
		pList->arr[i] = pList->arr[i - 1];
	}

	// n��°�� �� data ����
	pList->arr[n] = data;

	// ������ ���� ����
	pList->numData++;

	printf("[%d] ���� ������ %d ���� ����\n", n, data);

	return SUCCESS;
}





