#ifndef __HEAP_H__
#define __HEAP_H__

#define SUCCESS 1
#define FAIL 0

/* Heap �� ������ */
//#define HEAP_LEN 100

typedef int HData;

// d1 �� �켱������ ���ٸ� 0���� ū �� ����
// d2 �� �켱������ ���ٸ� 0���� ���� �� ����
// d1 �� d2 �� �켱������ ���ٸ� 0 �� ����
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	int numData;  // ��� �ִ� ������ ����
	HData *heapArr;  // �����޸𸮷� ����
	fnPriorityComp * comp;// �켱 ���� �� �Լ�
} Heap;



/* Heap �� ���� */
// �� �ʱ�ȭ
//void heap_init(Heap *ph, fnPriorityComp pc);
void heap_init(Heap *ph, int len);  // �� �ʱ�ȭ
void heap_destroy(Heap *ph);

// ���� ����ֳ�?
int heap_is_empty(Heap *ph);

// ���� ������ �߰� (INSERT)
void heap_insert(Heap *ph, HData data);

// ������ ���� (DELETE) �Ͽ� ����, ������ root���� �߻�
HData heap_delete(Heap *ph);

// ������
Heap *g_hp;
void HeapSort(int arr[], int n);


#endif