#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "Stack.h"

int main()
{
	Stack stack;
	Data data;

	stack_init(&stack);  // Stack�� ���� �� �ʱ�ȭ

	// ������ push 
	stack_push(&stack, 1);   //  1 �� (top)
	stack_push(&stack, 2);   //  1  2 ��
	stack_push(&stack, 3);   //  1  2  3 ��
	stack_push(&stack, 4);   //  1  2  3  4 ��
	stack_push(&stack, 5);   //  1  2  3  4  5 ��

	// ������ pop
	stack_pop(&stack, &data);
	printf("pop --> %d\n", data);  // 5
	stack_pop(&stack, &data);
	printf("pop --> %d\n", data);  // 4

	while (!stack_is_empty(&stack))  // 3 2 1
	{
		stack_pop(&stack, &data);
		printf("%d ", data);
	}
	printf("\n");

	stack_destroy(&stack);  // ��������

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}