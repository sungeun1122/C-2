#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "BinaryTree.h"
#include "Queue.h"

// Ʈ�� ��� ����
BTreeNode* btree_make_node(void)
{
	BTreeNode *pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->data = 0;

	return pNewNode;
}

// ��� ������ �б�
BTData btree_get_data(BTreeNode *bt)
{
	return bt->data;
}

// ��� ������ ����
void btree_set_data(BTreeNode *bt, BTData data)
{
	bt->data = data;
}

// ����� left sub tree 
BTreeNode* btree_get_left(BTreeNode *bt)
{
	return bt->pLeft;
}

// ����� right sub tree
BTreeNode* btree_get_right(BTreeNode *bt)
{
	return bt->pRight;
}

// bt�� left �� sub tree ����
void btree_make_left(BTreeNode *bt, BTreeNode *sub)
{
	if (bt->pLeft != NULL)
		btree_delete(bt->pLeft);

	bt->pLeft = sub;
}

// bt�� right �� sub tree ����
void btree_make_right(BTreeNode *bt, BTreeNode *sub)
{
	if (bt->pRight != NULL)
		btree_delete(bt->pRight);

	bt->pRight = sub;
}

// ���� ������ ����
void btree_delete(BTreeNode *bt)
{
	if (bt == NULL) return;

	// ������ post order ���(L -> R -> C) ������ ������ �Ѵ�

	// �ڱ� �ڽ��� ����� ���� left, right ���� ������ �Ѵ�
	btree_delete(bt->pLeft); // L
	btree_delete(bt->pRight); // R

	printf("��� ����: %d \n", bt->data); 
	free(bt);  // C
}

// Traversing
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;  // �������

	// C -> L -> R
	action(bt->data);  // C
	btree_preorder_traverse(bt->pLeft, action); // L : ���ȣ��
	btree_preorder_traverse(bt->pRight, action); // R : ���ȣ��
}
void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;  // �������

	// L -> C -> R
	btree_inorder_traverse(bt->pLeft, action); // L : ���ȣ��
	action(bt->data);  // C
	btree_inorder_traverse(bt->pRight, action); // R : ���ȣ��
}

void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;  // �������
	
	// L -> R -> C
	btree_postorder_traverse(bt->pLeft, action); // L : ���ȣ��
	btree_postorder_traverse(bt->pRight, action); // R : ���ȣ��
	action(bt->data);  // C
}


void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	// ť �غ�
	Queue q;
	queue_init(&q);

	// �ϴ� root �� ���� enq
	queue_enq(&q, (Data)bt);

	// while(ť �� empty �ɶ�����)
	while(!queue_is_empty(&q))
	{
		// deq �Ͽ� ���
		BTreeNode *btCurrent;
		queue_deq(&q, &btCurrent);
		action(btCurrent->data);

		// left �� enq
		if (btCurrent->pLeft != NULL)
			queue_enq(&q, btCurrent->pLeft);

		// right �� enq
		if (btCurrent->pRight != NULL)
			queue_enq(&q, btCurrent->pRight);
	}

	queue_destroy(&q);
}