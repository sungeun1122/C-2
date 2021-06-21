#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "ArrayList.h"

void printList(List *pList)
{
	list_init_iter(pList);  // iteration ����
	printf("[ ");
	while (list_hasNext(pList))
	{
		printf("%d,", list_next(pList));
	}
	printf("\b]\n");
}


int main()
{
	List myList;
	list_init(&myList);  // ����Ʈ ����

	printList(&myList);      // []
	list_add(&myList, 100);  // ������ �߰�
	printList(&myList);		// [100]
	list_add(&myList, 50);  // ������ �߰�
	printList(&myList);		// [100, 50]
	list_add(&myList, 100);
	printList(&myList);		// [100, 50, 100]
	list_add(&myList, 20);
	printList(&myList);		// [100, 50, 100, 20]
	list_add(&myList, 45);
	printList(&myList);		// ������ �߰� - ����
	list_add(&myList, 70);
	printList(&myList);  	// ������ �߰� - ����


	// ������ ����
	list_set(&myList, 0, 40);  // 0��° �����͸� 100 --> 40���� ����
	list_set(&myList, 1, 30);  
	list_set(&myList, 4, 30);  // ���� ����
	printList(&myList);       // [40, 30, 100, 20]

	// ������ ����
	printf("������ ������ %d\n", list_length(&myList));  // 4

	// n��° ������ ��ȸ
	Data data;
	if (list_get(&myList, 0, &data)) printf("0��° : %d\n", data);  // 40
	if (list_get(&myList, 6, &data)) printf("6��° : %d\n", data);  // ����
	if (list_get(&myList, 2, &data)) printf("2��° : %d\n", data);  // 100

	// ������ ����
	printf("������\n");
	printList(&myList);  // [40, 30, 100, 20]

	list_remove(&myList, 2);
	printList(&myList);  // [40, 30, 20]
	list_remove(&myList, 2);
	printList(&myList);  // [40, 30]
	printf("������ ������ %d\n", list_length(&myList));   // 2
	list_remove(&myList, 0);
	printList(&myList);  // [30]
	list_remove(&myList, 0);
	printList(&myList);  // []
	list_remove(&myList, 0);   // ����
	list_remove(&myList, 0);   // ����
	printf("������ ������ %d\n", list_length(&myList));  // 0


	// insert 
	printf("---------------------------\n");
	list_add(&myList, 10);
	list_add(&myList, 20);
	printList(&myList);    // [10, 20]
	list_insert(&myList, 1, 40);
	printList(&myList);    // [10, 40, 20]
	list_insert(&myList, 0, 5);
	printList(&myList);    // [5, 10, 40, 20]
	list_insert(&myList, 0, 5);  // ����
	printf("������ ������ %d\n", list_length(&myList));  // 4


	list_init(&myList);
	list_insert(&myList, 0, 5);   // insert �� list �� ���� �߰�(add) �����ϰ� ���۽�Ű��
	printList(&myList);    // [5]
	list_insert(&myList, 1, 25);
	printList(&myList);    // [5, 25]
	list_insert(&myList, 2, 45);
	printList(&myList);    // [5, 25, 45]


		
	list_destroy(&myList);  // ����Ʈ ����


	{
		printf("--------------------------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("�������ϸ� ����: ������ - �ƹ�Ű�� ��������\n");
		_getch();

		printf("%d �� insert...\n", test_size);

		// �������ϸ�
		start = clock();
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_insert(&myList, 0, i);  // 0��° insert!
		}
		end = clock();
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("insert ���: %ld ms ���\n", end - start);

		//----------------------------------------
		printf("�ƹ�Ű�� �����ø� ���� �׽�Ʈ �����մϴ�\n");
		_getch();
		printf("%d �� get...\n", test_size);

		// �������ϸ�
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_get(&myList, i, &data);
		}
		end = clock();
		printf("get ��� : %ld ms ���\n", end - start);

		//---------------------------------
		printf("�ƹ�Ű�� ������ ������ ���۵˴ϴ�: ������\n");
		_getch();
		printf("%d �� remove...\n", test_size);
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0);
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("remove ��� : %ld ms ���\n", end - start);


		printf("�ƹ�Ű�� ������ ����˴ϴ� : ����� ������\n");
		_getch();
		list_destroy(&myList);
	}


	
	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}