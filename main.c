#include "pch.h"
#pragma warning(disable :4996)
#include <stdio.h>
#include <malloc.h>

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];
	int category;
	struct USERDATA* pNext;
} USERDATA;

void main() {
	char* menu = (char*)malloc(sizeof(char) + 1); // size 4 �����Ҵ�
	char temp = "";

	while (temp != 'X') {
		temp = MainMenu(menu);
		printf("������1");
		if (temp == 'A') {
			char* UserData = malloc(sizeof(UserData));
			memset(UserData, 0, sizeof(UserData));
			Add(UserData);
		}
		else if (temp == 'P') {
			printf("������2");
			PrintAll();
		}
	}

	
}
