#ifndef __QUEUE_H__
#define __QUEUE_H__

#define SUCCESS	1
#define FAIL	0

/* ť�� ������ */
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *pNext;
} Node;

typedef struct _queue
{
	Node *pFront;
	Node *pBack;
} ListQueue;
typedef ListQueue Queue;

/* ť�� ���� */
// ť �ʱ�ȭ
void queue_init(Queue *pq);

// ť ����
void queue_destroy(Queue *pq);

// ť�� ����ִ���?
int queue_is_empty(Queue *pq);

// enqueue, ������ �߰� (back �� �߰�)
int queue_enq(Queue *pq, Data data);

// dequeue, ������ ������ (front ���� ����)
int queue_deq(Queue *pq, Data *pData);

// peek, ������ �鿩�� ���� (front)
int queue_peek(Queue *pq, Data *pData);


#endif
