#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

/*
*	malloc(), free()
*   calloc(), realloc()
*
*   memcpy(), memset()
*/

int main()
{
	// 동적 메모리 할당 : Dynamic memory allocation
	{
		int len = 1000000;
		int *arr = (int*)malloc(len); // malloc(byte_size) 메모리블럭을할당 받고, 주소를 리턴
		
		printf("arr[0] : %d\n", arr[0]);

		// 메모리 할당 받았으면 초기화 시켜주는것이 좋다.
		memset(arr, 0, len);  // arr번지부터 len 만큼의 메모리 영역을 0으로 초기화
	
		printf("arr[0] : %d\n", arr[0]);

		// 동적메모리는 사용한 후에 반드시 free (할당해제, 반납) 해야 함.
		free(arr);
	}

	// free(arr);  블럭안에서 사용하던 동적할당된 포인터는 잊어버리면 끝장이다.

	// ★★ 메모리 누수 Memory Leak 발생 주의!!!! ★★

	printf("\n");
	{
		// realloc()  : re-allocation(). 메모리 재할당

		// 기존에 메모리 할당된 것들을 새로이 공간할당 받아서 내용복사
		// 동적 메모리에 사용된 배열 확장등에 좋다.

		int *arr1 = (int*)malloc(sizeof(int) * 3);
		arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;
		//arr1[3] = 40; <-- 위험!

		printf("%d %d %d\n", arr1[0], arr1[1], arr1[2]);

		// 동적메모리 재할당 (확장, 축소)
		//  기존의 arr1 에 할당된 공간은 해제 됩니다. (따로 free() 시키지 않아도 됨)
		arr1 = (int*)realloc(arr1, sizeof(int) * 5);

		arr1[3] = 40;
		
		printf("%d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3]);

		free(arr1);
	}

	printf("\n메모리 프로파일링 시작 - 아무키나 누르면 시작합니다\n");
	_getch();
	{
		int len = 1000000;
		int *arr;

		// 메모리 누수 주의
		for (int i = 0; i < 10; i++) {
			arr = (int*)malloc(sizeof(int) * len);
			
			_sleep(5000);  // delay주기 ms단위
			free(arr);
			_sleep(5000);
		}

		//free(arr);  // 응?
	}




	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}