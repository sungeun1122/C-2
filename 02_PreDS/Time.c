#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

/*
C, C++ 에서 시작 측정하기
방법1:  time() 사용
방법2:  clock() 사용

C 에서 프로그램 실행 지연 시키기
_sleep() 사용
*/

int main()
{
	// time() 함수
	{
		time_t start, end;
		printf("time() 측정시작\n");

		start = time(NULL);  // 시작시간, 현재시간 측정

		// 측정하고자 하는 수행코드
		for (int i = 0; i < 5; i++) {
			printf("%d ", i);
			_sleep(1000);
		}
		printf("\n");

		end = time(NULL);   // 종료시간

		double result = (double)(end - start);  // 경과시간
		printf("%f s\n", result);
	}

	// 시간측정 : clock() 사용
	{
		clock_t start, end;

		start = clock(); // 시작, 현재시간 측정

		// 측정하고자 하는 수행코드
		for (int i = 0; i < 5; i++) {
			printf("%d ", i);
			_sleep(1000);
		}
		printf("\n");

		end = clock(); // 종료
		long result = end - start;
		printf("%ld ms\n", result);
	}

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}