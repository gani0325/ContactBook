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
        //구조체 이름과 검색할 이름이 같으면 출력한다.
        if (Current->category == CategoryNum) {
            printf("이름: %s ", Current->szName);
            printf("전화번호: %s ", Current->szPhone);
            printf("카테고리: %d ", Current->category);
            printf("\n");
        }
        if (Current->pNext == NULL) {
            break;
        }
        Current = Current->pNext;
    }
}