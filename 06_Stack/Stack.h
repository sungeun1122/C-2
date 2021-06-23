#ifndef __STACK_H__
#define __STACK_H__

#define SUCCESS 1
#define FAIL 0

/* 스택의 데이터 */
typedef int Data;   

typedef struct _node
{
	Data data;
	struct _node *pNext;
} Node;

typedef struct _listStack
{
	Node *pTop;
} ListStack;

typedef ListStack Stack;

/* 스택의 동작 */
// 스택 초기화
void stack_init(Stack *pStack);

// 스택 제거
void stack_destroy(Stack *pStack);

// 스택 비었는지 확인
int stack_is_empty(Stack *pStack);

// push , top에 데이터 추가
int stack_push(Stack *pStack, Data data);

// pop,  top의 데이터 꺼내기
int stack_pop(Stack *pStack, Data *pData);

// peek, top의 데이터 미리보기
int stack_peek(Stack *pStack, Data *pData);

#endif














