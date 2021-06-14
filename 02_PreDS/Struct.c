#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

/*
	구조체 (struct)
	여러개의 데이터들 (멤버) 로 구성된 사용자 정의 자료형


	학생의 데이터
	-학번 : char[]
	-이름 : char[]
	-나이 : unsigned char  (0 ~ 255)
	-학년 : unsigned char
	-성별 : 'M', 'F'  char
	-키 : 173.4  float
	...
*/

struct point {
	int x;  // 멤버변수 (member variable)
	int y;  // 멤버변수
};

struct person {
	char name[20]; // 이름
	int age; // 나이
	double weight; // 몸무게
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

	// 멤버연산자 ( . ) 사용하여 구조체 멤버 사용.
	p1.x = 100;
	p1.y = 200;

	printf("p1 =>(%d, %d)\n", p1.x, p1.y);

	struct person p2;
	p2.age = 32;
	p2.weight = 54.7;
	strcpy(p2.name, "홍길동");

	printf("이름: %s, 나이: %d, 몸무게: %.1f\n", p2.name, p2.age, p2.weight);


	PS p3;
	Person p4;
	Person p5 = {"로키", 100, 87.567};  // 구조체 선언과 동시에 초기화

	printf("이름: %s, 나이: %d, 몸무게: %.1f\n", p5.name, p5.age, p5.weight);

	// 구조체에 대한 포인터
	Person *ptr = &p5;

	// *ptr => p5
	printf("이름: %s, 나이: %d, 몸무게: %.1f\n", (*ptr).name, (*ptr).age, (*ptr).weight);
	printf("이름: %s, 나이: %d, 몸무게: %.1f\n", ptr->name, ptr->age, ptr->weight);




	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}