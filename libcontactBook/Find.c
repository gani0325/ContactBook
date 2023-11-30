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
		printf("Add name:");
		scanf("%s", NameTemp);
		strcpy(name, NameTemp);

		return name;
	}
	else {
		printf("Add name:");
		scanf("%s", NameTemp);
		strcpy(FindTemp, Current->szName);

		while (1)
		{
			if (*FindTemp == *NameTemp) {
				printf("Duplicated name. Enter again.\n");
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