#ifndef __HEAP_H__
#define __HEAP_H__

#define SUCCESS 1
#define FAIL 0

/* Heap 의 데이터 */
//#define HEAP_LEN 100

typedef int HData;

// d1 의 우선순위가 높다면 0보다 큰 값 리턴
// d2 의 우선순위가 높다면 0보다 작은 값 리턴
// d1 과 d2 의 우선순위가 같다면 0 을 리턴
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	int numData;  // 담고 있는 데이터 개수
	HData *heapArr;  // 동적메모리로 구현
	fnPriorityComp * comp;// 우선 순위 비교 함수
} Heap;



/* Heap 의 동작 */
// 힙 초기화
//void heap_init(Heap *ph, fnPriorityComp pc);
void heap_init(Heap *ph, int len);  // 힙 초기화
void heap_destroy(Heap *ph);

// 힙이 비어있나?
int heap_is_empty(Heap *ph);

// 힙에 데이터 추가 (INSERT)
void heap_insert(Heap *ph, HData data);

// 힙에서 삭제 (DELETE) 하여 리턴, 삭제는 root에서 발생
HData heap_delete(Heap *ph);

// 힙정렬
Heap *g_hp;
void HeapSort(int arr[], int n);


#endif