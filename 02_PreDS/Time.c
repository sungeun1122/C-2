#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

/*
C, C++ ���� ���� �����ϱ�
���1:  time() ���
���2:  clock() ���

C ���� ���α׷� ���� ���� ��Ű��
_sleep() ���
*/

int main()
{
	// time() �Լ�
	{
		time_t start, end;
		printf("time() ��������\n");

		start = time(NULL);  // ���۽ð�, ����ð� ����

		// �����ϰ��� �ϴ� �����ڵ�
		for (int i = 0; i < 5; i++) {
			printf("%d ", i);
			_sleep(1000);
		}
		printf("\n");

		end = time(NULL);   // ����ð�

		double result = (double)(end - start);  // ����ð�
		printf("%f s\n", result);
	}

	// �ð����� : clock() ���
	{
		clock_t start, end;

		start = clock(); // ����, ����ð� ����

		// �����ϰ��� �ϴ� �����ڵ�
		for (int i = 0; i < 5; i++) {
			printf("%d ", i);
			_sleep(1000);
		}
		printf("\n");

		end = clock(); // ����
		long result = end - start;
		printf("%ld ms\n", result);
	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}