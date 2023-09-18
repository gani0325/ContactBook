#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

USERDATA* PrintAll(USERDATA* Head)
{

	USERDATA* Current = Head;

	while (Current != NULL)
	{
		printf("[%p] ", Current);
		printf("이름: %s ", Current->szName);
		printf("전화번호: %s ", Current->szPhone);
		printf("카테고리: %d ", Current->category);
		printf("이전 구조체 포인터 : %p\n", Current->pNext);

		Current = Current->pNext;
	}

	return Current;
}
