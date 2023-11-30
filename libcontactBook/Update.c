#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void Update(USERDATA* Head) {
    //UpdateUI();

    USERDATA* Current = Head;

    char UpdateName[32];
    char UpdateNameTemp[32];
    char UpdatePhone[32];
    int UpdateCategory = 0;
    scanf("%s", UpdateName);

    while (Current->pNext != NULL)
    {
        //구조체 이름과 수정할 이름이 같으면 출력한다.
        strcpy(UpdateNameTemp, Current->szName);
        if (*UpdateName == *UpdateNameTemp) {
            printf("update contactbook number : ");
            scanf("%s", UpdatePhone);
            strcpy(Current->szPhone, UpdatePhone);
            printf("update category friend[0], family[1], company[2], other[3] : ");
            scanf("%d", &UpdateCategory);
            getchar();
            Current->category = UpdateCategory;
            break;
        }
        Current = Current->pNext;
    }
}