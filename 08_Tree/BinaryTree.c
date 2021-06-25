#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "BinaryTree.h"
#include "Queue.h"

// 트리 노드 생성
BTreeNode* btree_make_node(void)
{
	BTreeNode *pNewNode = (BTreeNode*)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->data = 0;

	return pNewNode;
}

// 노드 데이터 읽기
BTData btree_get_data(BTreeNode *bt)
{
	return bt->data;
}

// 노드 데이터 쓰기
void btree_set_data(BTreeNode *bt, BTData data)
{
	bt->data = data;
}

// 노드의 left sub tree 
BTreeNode* btree_get_left(BTreeNode *bt)
{
	return bt->pLeft;
}

// 노드의 right sub tree
BTreeNode* btree_get_right(BTreeNode *bt)
{
	return bt->pRight;
}

// bt의 left 에 sub tree 연결
void btree_make_left(BTreeNode *bt, BTreeNode *sub)
{
	if (bt->pLeft != NULL)
		btree_delete(bt->pLeft);

	bt->pLeft = sub;
}

// bt의 right 에 sub tree 연결
void btree_make_right(BTreeNode *bt, BTreeNode *sub)
{
	if (bt->pRight != NULL)
		btree_delete(bt->pRight);

	bt->pRight = sub;
}

// 현재 노드부터 삭제
void btree_delete(BTreeNode *bt)
{
	if (bt == NULL) return;

	// 삭제는 post order 방식(L -> R -> C) 순서로 지워야 한다

	// 자기 자신을 지우기 전에 left, right 부터 지워야 한다
	btree_delete(bt->pLeft); // L
	btree_delete(bt->pRight); // R

	printf("노드 삭제: %d \n", bt->data); 
	free(bt);  // C
}

// Traversing
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;  // 재귀종료

	// C -> L -> R
	action(bt->data);  // C
	btree_preorder_traverse(bt->pLeft, action); // L : 재귀호출
	btree_preorder_traverse(bt->pRight, action); // R : 재귀호출
}
void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;  // 재귀종료

	// L -> C -> R
	btree_inorder_traverse(bt->pLeft, action); // L : 재귀호출
	action(bt->data);  // C
	btree_inorder_traverse(bt->pRight, action); // R : 재귀호출
}

void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL) return;  // 재귀종료
	
	// L -> R -> C
	btree_postorder_traverse(bt->pLeft, action); // L : 재귀호출
	btree_postorder_traverse(bt->pRight, action); // R : 재귀호출
	action(bt->data);  // C
}


void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	// 큐 준비
	Queue q;
	queue_init(&q);

	// 일단 root 를 먼저 enq
	queue_enq(&q, (Data)bt);

	// while(큐 가 empty 될때까지)
	while(!queue_is_empty(&q))
	{
		// deq 하여 출력
		BTreeNode *btCurrent;
		queue_deq(&q, &btCurrent);
		action(btCurrent->data);

		// left 를 enq
		if (btCurrent->pLeft != NULL)
			queue_enq(&q, btCurrent->pLeft);

		// right 를 enq
		if (btCurrent->pRight != NULL)
			queue_enq(&q, btCurrent->pRight);
	}

	queue_destroy(&q);
}