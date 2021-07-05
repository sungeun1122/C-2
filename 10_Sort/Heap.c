#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "Heap.h"

//-------------------------------------
// ��� �ε��� ��� ��ũ�� (���� UP)
#define GET_PARENT_IDX(idx) ((idx) >> 1)    // idx / 2
#define GET_LEFT_IDX(idx) ((idx) << 1)      // idx * 2
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1)  // idx * 2 + 1

// ���Լ� ��� ��ũ�� (���� UP)
#define COMP_ASC(d1, d2) ((d2) - (d1))   // ��������
#define COMP_DESC(d1, d2) ((d1) - (d2))   // ��������



// idx �� �ڽĵ� �� �켱 ������ ���� �ڽ��� index �� ���� --> delete �� ���
int getHighPriority(Heap *ph, int idx)
{
	// �ڽĳ�尡 ���ٸ� 0 ����
	if (GET_LEFT_IDX(idx) > ph->numData) return 0;

	// ���� �ڽ� ��尡 ������(������) �ڽ� �����
	if (GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);

	// �ڽ��� �� �ִ� ���, �켱���� �� �Լ� ���!
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
	{
		// right �� �켱������ ���ٸ�
		return GET_RIGHT_IDX(idx);
	}
	else
	{
		// left �� �켱������ ���ų� ���ٸ�
		return GET_LEFT_IDX(idx);
	}

}



//--------------------------------------
// �� �ʱ�ȭ
void heap_init(Heap *ph, int len)
{
	ph->numData = 0;   // ������(���)����
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1));  // 1-based �迭�̴ϱ�! +1�� �迭 �ʿ�

	g_hp = ph;   // �����Ŀ� �ʿ�
}

void heap_destroy(Heap *ph)
{
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}

// ���� ����ֳ�?
int heap_is_empty(Heap *ph)
{
	if (ph->numData == 0) return SUCCESS;
	return FAIL;
}

// ���� ������ �߰� (INSERT)
void heap_insert(Heap *ph, HData data)
{
	// ���� INSERT �Ǵ� �����ʹ� �� ������ ����
	int idx = ph->numData + 1;  // �迭 �ε����� '1' ���� �����Ѵ�.  ��ü node �� ������ �� numData �Դϴ�.

	// �Ʒ� while �� �����ϸ鼭 ���� INSERT �� data �� ��ġ�� idx �� ����
	while (idx != 1)  // root (�ֻ���) �� �����Ҷ�����
	{
		// �θ�� �켱 ���� ��
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0) // �θ𺸴� �켱���� ���ٸ�
		{
			// �θ� ������� -> idx
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];

			// idx -> �θ� index �� �̵�
			idx = GET_PARENT_IDX(idx);
		}
		else {
			// �θ𺸴� �켱������ ���ų� �۴ٸ�... ���⼭ ����
			break;
		}
	}

	// idx�� ������ �װ��� ���� INSERT �� data�� �� ��ġ
	ph->heapArr[idx] = data;
	ph->numData++;
}

// ������ ���� (DELETE) �Ͽ� ����, ������ root���� �߻�
HData heap_delete(Heap *ph)
{
	HData rootData = ph->heapArr[1];  // �ε��� 1���� ��Ʈ ���.  �̸� �����ϰ� �����Ѵ�

	// ������ ��尡 �ڸ����� ��ġ idx �� �����ؾ� �Ѵ�.
	// idx�� �����ɶ����� ������ ����� data�� ������ ���´�.
	HData lastElem = ph->heapArr[ph->numData];  // numData ��°�� ������ ����.

	int idx = 1;   // ������ ��尡 �ϴ� root �� �ڸ��� ������.
	int childIdx;

	// �ϴ�, �ڽĳ���� �켱���� ������ ���� , getHighPriority ���
	// ���� �ڽ��� �ϳ��� ���ٸ� 0�� ���ϵǾ� while �� ����
	// �Ʒ� while ���� �ᱹ idx ���� �����ϱ� ����.
	while (childIdx = getHighPriority(ph, idx))
	{
		// ���õ� �ڽİ�, �Ʒ����� �ö�� ������ ���� �켱���� ��.
		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0) break;

		// �ڽ��� �켱������ �� ũ�ٸ�,  �� �ڽ��� �θ��� �ڸ��� ��ü
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// ���� �񱳸� ���� ������ ��� idx�� ������ �ڽ���ġ�� ������
		idx = childIdx;
	}

	// while�� �� ������ idx ��ġ�� ������ ���(laseElem)�� ��ġ�� ���̴�.
	ph->heapArr[idx] = lastElem;	
	ph->numData--;   // ������ ���� -1 ����
	return rootData;  // ���ʿ� ������ ���Ҵ� root data ����
}

void HeapSort(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		heap_insert(g_hp, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = heap_delete(g_hp);
}














