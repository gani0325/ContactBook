#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct _USERDATA
{
	char szName[32];
	char szPhone[32];
	int category;
	struct _USERDATA* pNext;
}USERDATA;
void Add(char* UserData) {
	USERDATA* ContactBook;
	// ����(n) ������
	ContactBook = UserData;
	// �ӽ������� ������ (n-1)������
	static USERDATA* pTmp;
	//printf("UserData ������: %p, pNext�� ������ :%p", &UserData, ContactBook.pNext);
	printf("�߰��� �̸��� �Է��ϼ���:");
	scanf("%s", ContactBook->szName);
	printf("�̸��� �´� ��ȭ��ȣ�� �Է��ϼ���(010-0000-0000):");
	scanf("%s", ContactBook->szPhone);
	printf("ī�װ��� �´� ���ڸ� �Է��ϼ���. ģ��[0], ����[1], ����[2], ��Ÿ[3]:");
	scanf("%d", &ContactBook->category);

	if (pTmp == NULL) {
		pTmp = UserData;
		ContactBook->pNext;
	}
	else {
		USERDATA* preventContactBook;
		preventContactBook = pTmp;

		preventContactBook->pNext=UserData;
		pTmp = UserData;
		ContactBook->pNext = NULL;
	}


	FILE* pfile = NULL;
	pfile = fopen("Contactbook.txt", "a");
	fprintf(pfile, "\n");
	fprintf(pfile, "�̸�: %s, ��ȭ��ȣ: %s, ī�װ�: %d, ���� pNext������%p", ContactBook->szName, ContactBook->szPhone, ContactBook->category, UserData);
	fclose(pfile);
}