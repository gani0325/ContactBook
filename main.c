#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdio.h>
#include <malloc.h>


void main() {
	char* menu = malloc(sizeof(char)); // size 4 동적할당입니다!
	memset(menu, 0, sizeof(char));
	char temp = "";

	USERDATA* Head = malloc(sizeof(USERDATA)+1);
	Head = NULL;

	USERDATA* NewNode = NULL;

	while (temp != 'X') {
		MainMenu(menu);
		temp = *menu;

		if (temp == 'A') {
			// 노드 생성
			NewNode = Create(&Head);
			// 노드 추가
			Add(&Head, NewNode);
		}
		else if (temp == 'L') {
			Reallocation(Head);
		}
		else if (temp == 'P') {
			PrintAll(Head);
		}
		else if (temp == 'S') {
			Search(Head);
		}
		else if (temp == 'C') {
			Category(Head);
		}
		else if (temp == 'R') {
			NewNode = SLL_GetNodeAt(Head);
			Remove(&Head, NewNode);
		}
		else if (temp == 'U') {
			Update(Head);
		}
		else if (temp == 'E') {
			Exit(Head);
		}
		else {
			temp = "";
			continue;
		}
	}
}