#ifndef __WALLET_H__
#define __WALLET_H__

/*
	Wallet �� �߻��ڷ���(ADT)
*/

#define SUCCESS 1
#define FAIL 0


// ������ ������
typedef struct _wallet
{
	int coin500;   // 500��¥�� ���� ����
	int bill1000;  // 1000��¥�� ���� ����
} Wallet;


// ������ ����

void wlt_init(Wallet *p); // ������ �ʱ�ȭ
void wlt_put_coin(Wallet *p, int coinNum); // ���� ����
int wlt_take_coin(Wallet *p, int coinNum);// ���� ����
void wlt_put_bill(Wallet *p, int billNum); // ���� ����
int wlt_take_bill(Wallet *p, int billNum); // ���� ����
int wlt_balance(Wallet *p); // ������ �ܾ� Ȯ��

#endif











