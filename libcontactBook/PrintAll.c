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
		printf("name: %s ", Current->szName);
		printf("number: %s ", Current->szPhone);
		printf("category: %d ", Current->category);
		printf("previous struct pointer : %p\n", Current->pNext);

		Current = Current->pNext;
	}

	return Current;
}
