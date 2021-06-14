#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. �����޸�, ����, ���ڿ� ��ȯ
#include <string.h> // strcpy .. ���ڿ� �Լ�.  memcpy.. �޸𸮺� �Լ�
#include <conio.h>  // _getch, putch .. MS ��� C��ǥ�� �Լ�
#include <time.h>   // clock .. �ð� ��¥ �Լ�
#pragma warning(disable:4996)  // scanf() �� ���� C�Լ��� ���۹���.
#pragma warning(disable:4477)  // unsigned <--> signed ���� warning

/*
	����ü (struct)
	�������� �����͵� (���) �� ������ ����� ���� �ڷ���


	�л��� ������
	-�й� : char[]
	-�̸� : char[]
	-���� : unsigned char  (0 ~ 255)
	-�г� : unsigned char
	-���� : 'M', 'F'  char
	-Ű : 173.4  float
	...
*/

struct point {
	int x;  // ������� (member variable)
	int y;  // �������
};

struct person {
	char name[20]; // �̸�
	int age; // ����
	double weight; // ������
};

typedef struct person PS;

typedef struct _person {
	char name[20];
	int age;
	double weight;
} Person;




int main()
{
	struct point p1;

	// ��������� ( . ) ����Ͽ� ����ü ��� ���.
	p1.x = 100;
	p1.y = 200;

	printf("p1 =>(%d, %d)\n", p1.x, p1.y);

	struct person p2;
	p2.age = 32;
	p2.weight = 54.7;
	strcpy(p2.name, "ȫ�浿");

	printf("�̸�: %s, ����: %d, ������: %.1f\n", p2.name, p2.age, p2.weight);


	PS p3;
	Person p4;
	Person p5 = {"��Ű", 100, 87.567};  // ����ü ����� ���ÿ� �ʱ�ȭ

	printf("�̸�: %s, ����: %d, ������: %.1f\n", p5.name, p5.age, p5.weight);

	// ����ü�� ���� ������
	Person *ptr = &p5;

	// *ptr => p5
	printf("�̸�: %s, ����: %d, ������: %.1f\n", (*ptr).name, (*ptr).age, (*ptr).weight);
	printf("�̸�: %s, ����: %d, ������: %.1f\n", ptr->name, ptr->age, ptr->weight);




	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷� ����˴ϴ�\n");
	_getch();
	return 0;
}