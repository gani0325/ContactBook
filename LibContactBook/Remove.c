#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <string.h>

USERDATA* SLL_GetNodeAt(USERDATA* Head)
{

	RemoveUI();
	
	char removeName[15];	
	char removeTemp[15];
	scanf("%s", removeName);
	getchar();

	USERDATA* Current = Head;

	while (Current != NULL)
	{	
		strcpy(removeTemp, Current->szName);
		if (*removeName == *removeTemp) {
			break;
		}
		Current = Current->pNext;
	}

	return Current;
}

void Remove(USERDATA** Head, USERDATA* Remove) {

	//  노드 제거 
	{
		if (*Head == Remove)
		{
			*Head = Remove->pNext;
		}
		else
		{
			USERDATA* Current = *Head;
			while (Current != NULL)
			{
				if (Current->pNext == Remove) {
					break;
				}
				Current = Current->pNext;
			}

			if (Current != NULL)
				Current->pNext = Remove->pNext;
		}
	}
}