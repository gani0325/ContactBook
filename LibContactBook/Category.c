#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>

void Category(USERDATA* Head) {
	printf("\n");
	printf("--------------------------------ī�װ� ���[C]--------------------------------\n");
    int categ;

    printf("���� ���� ī�װ��� �´� ���ڸ� �Է��ϼ���. ģ��[0], ����[1], ����[2], ��Ÿ[3]: ");
    scanf("%d", categ);
    getchar();
    USERDATA* Current = Head;

    printf("ī�װ�: %d ", categ);

    while (Current != NULL)
    {
        if (Current->category == categ) {
            printf("[%p] ", Current);
            printf("�̸�: %s ", Current->szName);
            printf("��ȭ��ȣ: %s ", Current->szPhone);
            
            Current = Current->pNext;
        }
        else {
            Current = Current->pNext;
        }
        
            
    }

}