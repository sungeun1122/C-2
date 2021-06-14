#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

#include "Wallet.h"

int main()
{
	Wallet myWallet;  // ���� ����

	wlt_init(&myWallet); // ���� �ʱ�ȭ
	wlt_put_coin(&myWallet, 2);  // ���� ���� : 500�� x 2��
	wlt_put_bill(&myWallet, 1);  // ���� ���� : 1000�� x 1��

	printf("�ܾ� %d\n", wlt_balance(&myWallet));  // �ܾ� : 2000��

	wlt_put_coin(&myWallet, 3);  // ���� ���� : 500�� x 3��
	wlt_put_bill(&myWallet, 4);  // ���� ���� : 1000�� x 4��

	printf("�ܾ� %d\n", wlt_balance(&myWallet));  // �ܾ� : 7500��

	wlt_take_coin(&myWallet, 4);  // ���� ����
	wlt_take_bill(&myWallet, 2);  // ���� ����
	printf("�ܾ� %d\n", wlt_balance(&myWallet));  // �ܾ� : 3500��

	wlt_take_coin(&myWallet, 2);  // ���� ����
	wlt_take_bill(&myWallet, 10);  // ���� ����

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}