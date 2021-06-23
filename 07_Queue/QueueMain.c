#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "Queue.h"

int main()
{
	// Queue ���� �� �ʱ�ȭ
	Queue q;
	Data data;
	queue_init(&q);

	// enqueue
	queue_enq(&q, 1);   // front <-- [1] <-- back
	queue_enq(&q, 2);   // front <-- [1 2] <-- back
	queue_enq(&q, 3);   // front <-- [1 2 3] <-- back
	queue_enq(&q, 4);   // front <-- [1 2 3 4] <-- back
	queue_enq(&q, 5);   // front <-- [1 2 3 4 5] <-- back

	queue_deq(&q, &data);
	printf("deq --> %d\n", data);  // 1
	queue_deq(&q, &data);
	printf("deq --> %d\n", data);  // 2

	while (!queue_is_empty(&q))
	{
		queue_deq(&q, &data);
		printf("%d ", data);    // 3 4 5
	}
	printf("\n");

		
	queue_destroy(&q);  // ť ����

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}










