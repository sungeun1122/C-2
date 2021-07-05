#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "Heap.h"

//-------------------------------------
// 노드 인덱스 계산 매크로 (성능 UP)
#define GET_PARENT_IDX(idx) ((idx) >> 1)    // idx / 2
#define GET_LEFT_IDX(idx) ((idx) << 1)      // idx * 2
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1)  // idx * 2 + 1

// 비교함수 대신 매크로 (성능 UP)
#define COMP_ASC(d1, d2) ((d2) - (d1))   // 오름차순
#define COMP_DESC(d1, d2) ((d1) - (d2))   // 내림차순



// idx 의 자식들 중 우선 순위가 높은 자식의 index 값 리턴 --> delete 에 사용
int getHighPriority(Heap *ph, int idx)
{
	// 자식노드가 없다면 0 리턴
	if (GET_LEFT_IDX(idx) > ph->numData) return 0;

	// 왼쪽 자식 노드가 유일한(마지막) 자식 노드라면
	if (GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);

	// 자식이 둘 있는 경우, 우선순위 비교 함수 사용!
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
	{
		// right 가 우선순위가 높다면
		return GET_RIGHT_IDX(idx);
	}
	else
	{
		// left 가 우선순위가 높거나 같다면
		return GET_LEFT_IDX(idx);
	}

}



//--------------------------------------
// 힙 초기화
void heap_init(Heap *ph, int len)
{
	ph->numData = 0;   // 데이터(노드)개수
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1));  // 1-based 배열이니까! +1개 배열 필요

	g_hp = ph;   // 힙정렬에 필요
}

void heap_destroy(Heap *ph)
{
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}

// 힙이 비어있나?
int heap_is_empty(Heap *ph)
{
	if (ph->numData == 0) return SUCCESS;
	return FAIL;
}

// 힙에 데이터 추가 (INSERT)
void heap_insert(Heap *ph, HData data)
{
	// 새로 INSERT 되는 데이터는 맨 끝에서 시작
	int idx = ph->numData + 1;  // 배열 인덱스는 '1' 부터 시작한다.  전체 node 의 개수는 곧 numData 입니다.

	// 아래 while 문 수행하면서 새로 INSERT 된 data 가 위치할 idx 를 결정
	while (idx != 1)  // root (최상위) 에 도달할때까지
	{
		// 부모와 우선 순위 비교
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0) // 부모보다 우선순위 높다면
		{
			// 부모를 끌어내리기 -> idx
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];

			// idx -> 부모 index 로 이동
			idx = GET_PARENT_IDX(idx);
		}
		else {
			// 부모보다 우선순위가 같거나 작다면... 여기서 멈춤
			break;
		}
	}

	// idx가 결정된 그곳이 새로 INSERT 된 data가 들어갈 위치
	ph->heapArr[idx] = data;
	ph->numData++;
}

// 힙에서 삭제 (DELETE) 하여 리턴, 삭제는 root에서 발생
HData heap_delete(Heap *ph)
{
	HData rootData = ph->heapArr[1];  // 인덱스 1번이 루트 노드.  이를 제거하고 리턴한다

	// 마지막 노드가 자리잡을 위치 idx 를 결정해야 한다.
	// idx가 결정될때까지 마지막 노드의 data는 보관해 놓는다.
	HData lastElem = ph->heapArr[ph->numData];  // numData 번째가 마지막 노드다.

	int idx = 1;   // 마지막 노드가 일단 root 의 자리에 오른다.
	int childIdx;

	// 일단, 자식노드중 우선순위 높은거 선택 , getHighPriority 사용
	// 만약 자식이 하나도 없다면 0이 리턴되어 while 문 종료
	// 아래 while 문은 결국 idx 값을 결정하기 위함.
	while (childIdx = getHighPriority(ph, idx))
	{
		// 선택된 자식과, 아래에서 올라온 마지막 노드와 우선순위 비교.
		// 만약 자식의 우선순위가 같거나 낮다면 while 종료
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0) break;

		// 자식의 우선순위가 더 크다면,  그 자식이 부모의 자리로 교체
		ph->heapArr[idx] = ph->heapArr[childIdx];

		// 다음 비교를 위해 마지막 노드 idx를 좀전의 자식위치로 내리기
		idx = childIdx;
	}

	// while이 다 끝난후 idx 위치가 마지막 노드(laseElem)이 위치할 곳이다.
	ph->heapArr[idx] = lastElem;	
	ph->numData--;   // 데이터 개수 -1 감소
	return rootData;  // 최초에 저장해 놓았던 root data 리턴
}

void HeapSort(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		heap_insert(g_hp, arr[i]);

	for (i = 0; i < n; i++)
		arr[i] = heap_delete(g_hp);
}














