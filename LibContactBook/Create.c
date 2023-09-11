﻿#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

//  노드 생성 
USERDATA* Create() {
	USERDATA* ContactBook = (USERDATA*)malloc(sizeof(USERDATA));

	char name[32];
	char phone[32];
	int num = 0;

	printf("추가할 이름을 입력하세요:");
	scanf("%s", name);
	printf("이름에 맞는 전화번호를 입력하세요(010-0000-0000):");
	scanf("%s", phone);
	printf("카테고리에 맞는 숫자를 입력하세요. 친구[0], 가족[1], 직장[2], 기타[3]:");
	scanf("%d", &num);
	getchar();

	strcpy(ContactBook->szName, name);
	strcpy(ContactBook->szPhone, phone);
	ContactBook->category = num;  //  데이터를 저장한다. 
	ContactBook->pNext = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화 한다. 

	printf("%s_%s_%d\n", ContactBook->szName, ContactBook->szPhone, ContactBook->category);

	return ContactBook;
}