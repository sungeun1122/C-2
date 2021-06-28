#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "Heap.h"

//-------------------------------------
// �θ��� �ε���
int getParentIdx(int idx)
{
	return idx / 2;
}

// left �ڽĳ�� �ε���
int getLeftIdx(int idx)
{
	return idx * 2;
}

// right �ڽ� ��� �ε���
int getRightIdx(int idx)
{
	return idx * 2 + 1;
}

// idx �� �ڽĵ� �� �켱 ������ ���� �ڽ��� index �� ���� --> delete �� ���
int getHighPriority(Heap *ph, int idx)
{
	// �ڽĳ�尡 ���ٸ� 0 ����
	if (getLeftIdx(idx) > ph->numData) return 0;

	// ���� �ڽ� ��尡 ������(������) �ڽ� �����
	if (getLeftIdx(idx) == ph->numData) return getLeftIdx(idx);

	// �ڽ��� �� �ִ� ���, �켱���� �� �Լ� ���!
	if (ph->comp(ph->heapArr[getLeftIdx(idx)], ph->heapArr[getRightIdx(idx)]) < 0)
	{
		// right �� �켱������ ���ٸ�
		return getRightIdx(idx);
	}
	else
	{
		// left �� �켱������ ���ų� ���ٸ�
		return getLeftIdx(idx);
	}

}



//--------------------------------------
// �� �ʱ�ȭ
void heap_init(Heap *ph, fnPriorityComp pc)
{
	ph->numData = 0;   // ������(���)����
	ph->comp = pc;    // ���Լ�
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
		if (ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0) // �θ𺸴� �켱���� ���ٸ�
		{
			// �θ� ������� -> idx
			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];

			// idx -> �θ� index �� �̵�
			idx = getParentIdx(idx);
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
	while (/* TODO */)
	{
		// ���õ� �ڽİ�, �Ʒ����� �ö�� ������ ���� �켱���� ��.
		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����
		// TODO

		// �ڽ��� �켱������ �� ũ�ٸ�,  �� �ڽ��� �θ��� �ڸ��� ��ü
		// TODO

		// ���� �񱳸� ���� ������ ��� idx�� ������ �ڽ���ġ�� ������
		// TODO
	}

	// while�� �� ������ idx ��ġ�� ������ ���(laseElem)�� ��ġ�� ���̴�.
	ph->heapArr[idx] = lastElem;	
	ph->numData--;   // ������ ���� -1 ����
	return rootData;  // ���ʿ� ������ ���Ҵ� root data ����
}
















