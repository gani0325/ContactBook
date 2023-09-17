#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Find(USERDATA* Head, char* name)
{
	USERDATA* Current = Head;
	char FindTemp[15];
	char NameTemp[15];

	if ((Head) == NULL)
	{
		printf("추가할 이름을 입력하세요:");
		scanf("%s", &NameTemp);
		strcpy(name, NameTemp);

		return name;
	}
	else {
		printf("추가할 이름을 입력하세요:");
		scanf("%s", &NameTemp);
		strcpy(FindTemp, Current->szName);

		while (1)
		{
			if (*FindTemp == *NameTemp) {
				printf("중복된 이름입니다. 다시 입력해주세요!\n");
				Find(Current, name);
			}
			if (Current->pNext == NULL) {
				break;
			}
			Current = Current->pNext;
		}

		strcpy(name, NameTemp);
		return name;
	}
}