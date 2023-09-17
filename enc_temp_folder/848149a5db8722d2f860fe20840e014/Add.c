#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

USERDATA* Add(USERDATA** Head, USERDATA* NewNode) {
    //  헤드 노드가 NULL이라면 새로운 노드가 Head 
    USERDATA* Temp = NULL;

    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        //  테일을 찾아 NewNode를 연결한다. 
        USERDATA* Tail = (*Head);
        while (Tail->pNext != NULL)
        {
            Tail = Tail->pNext;

        }
        // 이전 주소
        Temp = Tail;
        // 현재 주소
        Tail->pNext = NewNode;
    }

    //printf("%p\n", Temp);   // 이전 주소
    //printf("%p", NewNode);  // 현재 주소

    FILE* pfile = NULL;
    pfile = fopen("Contactbook.txt", "a");
    fprintf(pfile, "\n");
    //fprintf(pfile, "이름: %s, 전화번호: %s, 카테고리: %d:, 이전 구조체 포인터: %p, 현재 구조체 주소: %p, 현재 구조체 포인터(null 이어야함..): %p, ", ContactBook->szName, ContactBook->szPhone, ContactBook->category,  prevContactBook->pNext, ContactBook, ContactBook->pNext);

    fprintf(pfile, "[%p] ", NewNode);
    fprintf(pfile, "이름: %s ", NewNode->szName);
    fprintf(pfile, "전화번호: %s ", NewNode->szPhone);
    fprintf(pfile, "카테고리: %d ", NewNode->category);
    fprintf(pfile, "이전 구조체 포인터 : %p\n", Temp);
    fprintf(pfile, "갖고있어야할 이전 구조체 포인터 : %p\n", NewNode->pNext);
    //fprintf(pfile, "현재 구조체 포인터(null 이어야함..) : %p", ContactBook->pNext);
    fclose(pfile);

}