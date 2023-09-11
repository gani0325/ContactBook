#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];
	int category;
	struct USERDATA* pNext;
} USERDATA;

void Add(char* UserData) {
	USERDATA* ContactBook;
	// �����Ҵ� ���� �ּҸ� ����ü ������ �Ҵ��ϱ�
	ContactBook = UserData;

	// ���ο� ���� �ּҸ� �ӽ� ����
	static USERDATA* pTmp;

	printf("�߰��� �̸��� �Է��ϼ���:");
	scanf("%s", ContactBook->szName);
	printf("�̸��� �´� ��ȭ��ȣ�� �Է��ϼ���(010-0000-0000):");
	scanf("%s", ContactBook->szPhone);
	printf("ī�װ��� �´� ���ڸ� �Է��ϼ���. ģ��[0], ����[1], ����[2], ��Ÿ[3]:");
	scanf("%d", &ContactBook->category);
	getchar();


	// ���� ó����!
	if (pTmp == NULL) {
		// ���� ����ü�� NULL , ���� �ּҿ� �ѱ� �ּҸ� pTmp �� ����
		pTmp = UserData;
		ContactBook->pNext = NULL;
	}
	else {
		// ���� ����ü �ּҿ� ���� �ּ� �ֱ�
		USERDATA* prevContactBook;
		prevContactBook = pTmp;
		prevContactBook->pNext = UserData;

		// ���� ����ü�� NULL , ���� �ּҿ� �ѱ� �ּҸ� pTmp �� ����
		pTmp = UserData;
		ContactBook->pNext = NULL;
	}

	 
	FILE* pfile = NULL;
	pfile = fopen("Contactbook.txt", "a");
	fprintf(pfile, "\n");
	fprintf(pfile, "�̸�: %s, ��ȭ��ȣ: %s, ī�װ�: %d", ContactBook->szName, ContactBook->szPhone, ContactBook->category);
	fclose(pfile);
}