#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>

void Category(USERDATA* Head) {
    int categ;
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