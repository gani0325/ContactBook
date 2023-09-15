#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void Update(USERDATA* Head) {
    UpdateUI();

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
            printf("수정하고 싶은 전화번호를 입력하세요 : ");
            scanf("%s", &UpdatePhone);
            strcpy(Current->szPhone, UpdatePhone);
            printf("수정하고 싶은 카테고리를 입력하세요 친구[0], 가족[1], 직장[2], 기타[3] : ");
            scanf("%d", &UpdateCategory);
            getchar();
            Current->category = UpdateCategory;
            break;
        }
        Current = Current->pNext;
    }
}