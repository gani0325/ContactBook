#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reallocation(USERDATA** Head)
{
	*Head = NULL;
	USERDATA* NewNode = NULL;
	USERDATA* Temp = NULL;
	FILE* pFile = NULL;
	char Name[100];
	char* pszSep = " ";
	char* pszToken = NULL;
	char* cmpName = "이름:";
	char* cmpPhone = "전화번호:";
	char* cmpCategory = "카테고리:";
	if (pFile == NULL) {
		pFile = fopen("Contactbook.txt", "a");
		fclose(pFile);
	}
	pFile = fopen("Contactbook.txt", "r");

	// 파일 끝까지 읽기
	while (feof(pFile) == 0) {
		NewNode = Create_Pointer();
		//한줄씩 읽기
		pszToken = "";
		if (fgets(Name, 100, pFile) != EOF) {
			// " "으로 토큰화
			pszToken = strtok(Name, pszSep);
			// 토큰이 NULL이 없을때!
			while (pszToken != NULL) {
				if (strcmp(Name, "\n") == 0) {
					pszToken = strtok(NULL, pszSep);
					continue;
				}
				//이름:을 만나면 다음 토큰인 이름을 저장한다.
				else if (strcmp(pszToken, cmpName) == 0) {
					printf("%s : ", pszToken);
					pszToken = strtok(NULL, pszSep);
					printf("%s : n", pszToken);
					strcpy(NewNode->szName, pszToken);

					continue;
				}
				//전화번호:을 만나면 다음 토큰인 전화번호를 저장한다.
				else if (strcmp(pszToken, cmpPhone) == 0) {
					pszToken = strtok(NULL, pszSep);
					strcpy(NewNode->szPhone, pszToken);
					continue;
				}
				//카테고리:을 만나면 다음 토큰인 카테고리를 저장한다.
				else if (strcmp(pszToken, cmpCategory) == 0) {
					pszToken = strtok(NULL, pszSep);
					NewNode->category = atoi(pszToken);

					continue;
				}
				//\n등의 토큰을 뺀다.
				pszToken = strtok(NULL, pszSep);
				printf("%s\n", pszToken);
			}
		}
		if (NewNode->category != NULL) {
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
		}
	}
	fclose(pFile);
}