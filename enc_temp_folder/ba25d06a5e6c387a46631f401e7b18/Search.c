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
	//Current->pNext�� �� �����Ͱ� �ְ� ����ü�̸��� �˻��� �̸��� ���� ������, Current�ּҴ� ���� ����ü�� �Ѿ��
	
	while (strcmp(Current->szName, compareName) != 0 && Current->pNext != NULL)
	{
		Current = Current->pNext;
	}
	//����ü �̸��� �˻��� �̸��� ������ ����Ѵ�.
	if (strcmp(Current->szName, compareName) == 0) {
		printf("�̸�: %s ", Current->szName);
		printf("��ȭ��ȣ: %s ", Current->szPhone);
		printf("ī�װ�: %d ", Current->category);
		printf("���� ����ü ������ : %p\n", Current->pNext);
	}
}