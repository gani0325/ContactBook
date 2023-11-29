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
        //����ü �̸��� ������ �̸��� ������ ����Ѵ�.
        strcpy(UpdateNameTemp, Current->szName);
        if (*UpdateName == *UpdateNameTemp) {
            printf("�����ϰ� ���� ��ȭ��ȣ�� �Է��ϼ��� : ");
            scanf("%s", UpdatePhone);
            strcpy(Current->szPhone, UpdatePhone);
            printf("�����ϰ� ���� ī�װ����� �Է��ϼ��� ģ��[0], ����[1], ����[2], ��Ÿ[3] : ");
            scanf("%d", &UpdateCategory);
            getchar();
            Current->category = UpdateCategory;
            break;
        }
        Current = Current->pNext;
    }
}