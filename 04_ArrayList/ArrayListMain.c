#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "ArrayList.h"


int main()
{
	List myList;
	list_init(&myList);  // ����Ʈ ����

	list_add(&myList, 100);  // ������ �߰�
								// [100]
	list_add(&myList, 50);  // ������ �߰�
								// [100, 50]
	list_add(&myList, 100);
							// [100, 50, 100]
	list_add(&myList, 20);
							// [100, 50, 100, 20]
	list_add(&myList, 45);
							// ������ �߰� - ����
	list_add(&myList, 70);
							// ������ �߰� - ����


	list_destroy(&myList);  // ����Ʈ ����
	
	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}