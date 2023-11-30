#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void Category(USERDATA* Head) {
    CategoryUI();

    USERDATA* Current = Head;

    int CategoryNum = 0;
    scanf("%d", &CategoryNum);
    
    while (1)
    {
        //����ü �̸��� �˻��� �̸��� ������ ����Ѵ�.
        if (Current->category == CategoryNum) {
            printf("name: %s ", Current->szName);
            printf("number: %s ", Current->szPhone);
            printf("category: %d ", Current->category);
            printf("\n");
        }
        if (Current->pNext == NULL) {
            break;
        }
        Current = Current->pNext;
    }
}