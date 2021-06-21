#ifndef __LINKED_LIST_H__
#define __LINKED_LISt_H__


#define TRUE 1
#define FALSE 0

/* List 의 데이터 */
typedef int Data;

// 노드 타입 정의
typedef struct _node
{
	Data data; // 노드 데이터
	struct _node *pNext;// 다음 노드 포인터
} Node;

// Linked List  타입 정의
typedef struct _linkedList
{
	Node *pHead;   // 시작노드
	Node *pTail;   // 끝 노드

	Node *pCurrent; // iteration 용
	int numData;   // 노드의 개수
} LinkedList;

typedef LinkedList List;


/* List 의 동작 */

// 리스트 초기화
void list_init(List *pList);

// 리스트 제거
void list_destroy(List *pList);

// 데이터 추가
int list_add(List *pList, Data data);

// n번째 데이터 삭제
int list_remove(List *pList, int n);

// n번째 데이터 수정
int list_set(List *pList, int n, Data data);

// 데이터 개수
int list_length(List *pList);

// 데이터 조회, iteration 초기화
void list_init_iter(List *pList);

// 데이터 조회, iteration 다음 데이터 추출?
Data list_next(List *pList);

// 데이터 조회, iteration 다음 데이터 있나?
int list_hasNext(List *pList);

// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List *pList, int n, Data *pData);

// 데이터 삽입 : n번째 위치에 데이터 삽입
int list_insert(List *pList, int n, Data data);



#endif