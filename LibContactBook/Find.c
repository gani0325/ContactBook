#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Find(USERDATA* Head, char* name)
{
	USERDATA* Current = Head;
	char FindTemp[15];
	char NameTemp[15] = malloc(sizeof(char) * 15);
	*NameTemp = ' ';

	while (Current->pNext != NULL)
	{
		printf("�߰��� �̸��� �Է��ϼ���:");
		scanf("%s", NameTemp);

		strcpy(FindTemp, Current->szName);
		if (*FindTemp == *NameTemp) {
			printf("�ߺ��� �̸��Դϴ�. �ٽ� �Է����ּ���!");
		}
		Current = Current->pNext;
	}
	*name = NameTemp;
	return name;
}