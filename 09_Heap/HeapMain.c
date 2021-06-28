#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "Heap.h"

int DataPriorityComp(HData ch1, HData ch2)
{
	//return ch2 - ch1;  // min-heap
	return ch1 - ch2;  // max-head
}


int main()
{
	Heap heap;
	heap_init(&heap, DataPriorityComp);

	heap_insert(&heap, 9);
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);
	
	// MIN-HEAP 
	//      (9)
	//     ��  ��
	//   (20)   (30)

	// MAX-HEAP 
	//      (30)
	//     ��  ��
	//   (9)    (20)

	printf("%d \n", heap_delete(&heap));  // MAX-HEAP => 30,  MIN-HEAP => 9
	printf("%d \n", heap_delete(&heap));  //           20
	printf("%d \n", heap_delete(&heap));  //           10 


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}