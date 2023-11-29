#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Search(USERDATA* Head)
{
	SearchUI();

	USERDATA* Current = Head;
	char compareName[32];
	scanf("%s", compareName);
	//Current->pNext가 볼 포인터가 있고 구조체이름과 검색할 이름이 같지 않으면, Current주소는 다음 구조체로 넘어간다
	
	while (strcmp(Current->szName, compareName) != 0 && Current->pNext != NULL)
	{
		Current = Current->pNext;
	}
	//구조체 이름과 검색할 이름이 같으면 출력한다.
	if (strcmp(Current->szName, compareName) == 0) {
		printf("%s\n", Current->szName);
		printf("%s\n", Current->szPhone);
		printf("%d\n", Current->category);
	}
}