#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
USERDATA* Reallocation(USERDATA* Head)
{

	USERDATA* Current = Head;
	FILE* pFile = NULL;
	char Name[100];
	char* pszSep = " ";
	char* pszToken = NULL;
	int a = 1;
	pFile = fopen("Contactbook.txt", "r");
	while (feof(pFile) == 0) {
		if (fgets(Name, 100, pFile) != EOF) {
			pszToken = strtok(Name, pszSep);
			while (pszToken != NULL) {
				puts(pszToken);
				pszToken = strtok(NULL, pszSep);
			}
			
			printf("%d\n", a);
		}
	}
	//while (Current != NULL)
	//{
	//	puts(Current);
	//	printf("[%p] ", Current);
	//	printf("�̸�: %s ", Current->szName);
	//	printf("��ȭ��ȣ: %s ", Current->szPhone);
	//	printf("ī�װ�: %d ", Current->category);
	//	printf("�����־���� ���� ����ü ������ : %p\n", Current->pNext);

	//	Current = Current->pNext;
	//}

	return Current;
}