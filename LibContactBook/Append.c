#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>

Node* Append(Node** Head, Node* NewNode) {
	Node* Tail = NULL;
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	else {
		Tail = (*Head);
		printf("Tail 포인터 %p\n", Tail->pNext);
		while (Tail->pNext != NULL) {
			Tail = Tail->pNext;
			printf("Tail 포인터 %p\n", Tail->pNext);
		}
		Tail->pNext = NewNode;
		printf("Tail 포인터 %p\n", Tail->pNext);
	}
	return Tail;
}