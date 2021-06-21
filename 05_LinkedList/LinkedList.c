#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning
#include "LinkedList.h"

// ����Ʈ �ʱ�ȭ
void list_init(List *pList)
{
	// head �� dummy node ���
	pList->pHead = (Node*)malloc(sizeof(Node));
	pList->pHead->pNext = NULL;
	pList->pTail = pList->pHead; // ���ʿ��� tail �� head ����

	pList->numData = 0;

	printf("����Ʈ �ʱ�ȭ\n");
}

// ����Ʈ ����
void list_destroy(List *pList)
{
	list_init_iter(pList);
	Node *pPrev = NULL;  // ���� ��带 ����ų ������
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;  // pCurrent �� �̵��ϱ� ����  pCurrent ���� '���� ���'�� ���
		list_next(pList);  // pCurrent �̵�
		free(pPrev); 
	}

	memset(pList, 0, sizeof(Node));
	printf("����Ʈ �Ҹ�\n");
}

// ������ �߰�
int list_add(List *pList, Data data)
{
	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;

	// tail�� ����Ű�� node �� next �� ���ο� node �� ����
	pList->pTail->pNext = pNewNode;

	// tail �� ���ο� node �� �̵�
	pList->pTail = pNewNode;
	
	// ������ ���� ����
	(pList->numData)++;

	return TRUE;
}

// n��° ������ ����
int list_remove(List *pList, int n)
{
	if (n >= pList->numData) return FALSE;

	// n��° ��� �����Ϸ���
	// n��° �� �ƴ϶� n-1 ��° ��� ������ �˾ƾ� �Ѵ�
	// ��. ���� ���(previous node) ���� �˾ƾ� �Ѵ�.
	list_init_iter(pList);
	int i = 0;
	Node *pPrev = NULL;  // ���� ��带 ����ų ������
	while (list_hasNext(pList))
	{
		pPrev = pList->pCurrent;  // pCurrent �� �̵��ϱ� ����  pCurrent ���� '���� ���'�� ���
		list_next(pList);  // pCurrent �̵�
		if (i >= n) break;
		i++;
	}

	// �� while ���� ������ 
	// pCurrent �� n��° ��带, 
	// pPrev �� n-1��° ��带 ����Ű�� �ִ�

	// ���� �� �����ؾ� �Ѵ�.  ���� �ٲ�� �����ȴ�.

	// ��������: �ſ� �ܼ� (�迭�� ����)
	pPrev->pNext = pList->pCurrent->pNext;

	// ���� tail �� ������ ��忴�ٸ� tail ���� �����ؾ� �Ѵ�.
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev;  // tail �� ���� ���� �̵�.

	// n��° ��� ����. ���� �޸� �Ҵ� ����! ��!
	free(pList->pCurrent);

	pList->numData--;  // ������ ���� -1 ����

	return TRUE;
}

// n��° ������ ����
int list_set(List *pList, int n, Data data)
{
	if (n >= pList->numData) return FALSE;

	// head���� �����ؼ� n��° ��� ã��, iteration ���
	list_init_iter(pList);  // iteration ����
	int i = 0;   // ���� ���° ���?
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) break;  // n��° ��� ã��!
		i++;
	}
	// �� while ���� ������ pCurrent �� n��° ��带 ����Ű�� �ֽ�.

	printf("%d ��° ������ ���� %d --> %d\n", n, pList->pCurrent->data, data);

	pList->pCurrent->data = data;  // ������ ����
	return TRUE;
}

// ������ ����
int list_length(List *pList)
{
	return pList->numData;
}

// ������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List *pList)
{
	pList->pCurrent = pList->pHead;
}

// ������ ��ȸ, iteration ���� ������ ����?
Data list_next(List *pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // �켱 current �ѹ� ������ �̵�
	Data result = pList->pCurrent->data; // ������ ����
	return result;
}

// ������ ��ȸ, iteration ���� ������ �ֳ�?
int list_hasNext(List *pList)
{
	if (pList->pCurrent->pNext == NULL)  // '���� ���' ���� ���� üũ
		return FALSE;

	return TRUE;
}

// ������ ��ȸ : n��° ������ �� �б�
int list_get(List *pList, int n, Data *pData)
{
	if (n >= pList->numData) return FALSE;

	// head���� �����ؼ� n��° ��� ã��, iteration ���
	list_init_iter(pList);  // iteration ����
	int i = 0;   // ���� ���° ���?
	while (list_hasNext(pList))
	{
		list_next(pList);
		if (i >= n) break;  // n��° ��� ã��!
		i++;
	}

	// �Ű������� n��° ��� ������ �����
	*pData = pList->pCurrent->data;

	return TRUE;
}

// ������ ���� : n��° ��ġ�� ������ ����
int list_insert(List *pList, int n, Data data)
{
	// n�� ��ȿ���� ����,  >= �� �ƴ϶�  > ��!
	if (n > pList->numData) return FALSE;

	// ���ο� node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	pNewNode->data = data;


	// 1. ù��° ������ �̰ų� �� ���� �߰��ϴ� ���.  (add() �� ����)
	if (pList->numData == 0 || pList->numData == n)
	{
		// add() �� ����
		pList->pTail->pNext = pNewNode;
		pList->pTail = pNewNode;
	}
	else
	{  // 2. n��° ��忡 �����ϴ� ���
		list_init_iter(pList);
		int i = 0;
		Node *pPrev = NULL;  // ���� ��带 ����ų ������
		while (list_hasNext(pList))
		{
			pPrev = pList->pCurrent;  // pCurrent �� �̵��ϱ� ����  pCurrent ���� '���� ���'�� ���
			list_next(pList);  // pCurrent �̵�
			if (i >= n) break;
			i++;
		}

		// n��° => pCurrent
		// n-1��° => pPrev 
		pPrev->pNext = pNewNode;  // ���� ���� ���ο� ��带 ����Ű��
		pNewNode->pNext = pList->pCurrent; // ���ο� ���� ������ n��° ��带 ����Ű�� �ȴ�.
	}
	
	//printf("[%d] ��° ������ %d ����\n", n, data);

	// ������ ���� ����.
	pList->numData++;  // ������
	
	return TRUE;
}