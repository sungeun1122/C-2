#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

/*
*	ArrayList �� ADT
*
*	ArrayList ��
*	���� : n��° ��ȸ ������
*	���� : ����, ���� ������.
*
*	���� : �뷮
*/

#define SUCCESS 1
#define FAIL 0

/* ArrayList �� ������ */
//#define LIST_LEN 4
#define LIST_LEN 30000   // �������ϸ�

typedef int Data;

typedef struct _ArrayList
{
	Data arr[LIST_LEN]; // ������(��)
	int numData;		// ����Ʈ ���� ������ ����
	int curPosition;	// iteration
} ArrayList;

typedef ArrayList List;


/* ArrayList �� ���� */
// ����Ʈ �ʱ�ȭ
void list_init(List *pList);

// ����Ʈ ����
void list_destroy(List *pList);

// ������ �߰�
int list_add(List *pList, Data data);

// n��° ������ ����
int list_remove(List *pList, int n); 

// n��° ������ ����
int list_set(List *pList, int n, Data data);

// ������ ����
int list_length(List *pList);

// ������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List *pList);

// ������ ��ȸ, iteration ���� ������ ����?
Data list_next(List *pList);

// ������ ��ȸ, iteration ���� ������ �ֳ�?
int list_hasNext(List *pList);

// ������ ��ȸ : n��° ������ �� �б�
int list_get(List *pList, int n, Data *pData);

// ������ ���� : n��° ��ġ�� ������ ����
int list_insert(List *pList, int n, Data data);

#endif
