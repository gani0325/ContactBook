#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];
	int category;
	struct _USERDATA* pNext;
} USERDATA;
void Add() {
	
	
	USERDATA UserData = { 0,0,0 };
	static USERDATA* pTmp;
	USERDATA* ContactBook = &UserData;

	if (pTmp->szName == 0) {
		pTmp=NULL;
	}

	*ContactBook->szName = 0;
	if (*ContactBook->szName != 0) {
		ContactBook->pNext = pTmp->pNext;
	}

	printf("�߰��� �̸��� �Է��ϼ���:");
	scanf("%s", ContactBook->szName);
	printf("�̸��� �´� ��ȭ��ȣ�� �Է��ϼ���(010-0000-0000):");
	scanf("%s", ContactBook->szPhone);
	printf("ī�װ��� �´� ���ڸ� �Է��ϼ���. ģ��[0], ����[1], ����[2], ��Ÿ[3]:");
	scanf("%d", &ContactBook->category);
	
	FILE* pfile = NULL;
	pfile = fopen("Contactbook.txt", "a");
	fprintf(pfile, "���� ����ü�� �ٶ󺸴� ������%p\n", &pTmp);
	if (*ContactBook->szName != 0) {
		pTmp->pNext = &UserData;
	}
	
	fprintf(pfile,"\n");
	fprintf(pfile, "�̸�: %s, ��ȭ��ȣ: %s, ī�װ�: %d, ����tmp ������%p, ���� pNext������%p", ContactBook->szName, ContactBook->szPhone, ContactBook->category, &pTmp, ContactBook->pNext);
	fclose(pfile);
}