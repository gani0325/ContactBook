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
	char* cmpName = "name:";
	char* cmpPhone = "number:";
	char* cmpCategory = "category:";
	if (pFile == NULL) {
		pFile = fopen("Contactbook.txt", "a");
		fclose(pFile);
	}
	pFile = fopen("Contactbook.txt", "r");

	// ���� ������ �б�
	while (feof(pFile) == 0) {
		NewNode = Create_Pointer();
		//���پ� �б�
		pszToken = "";
		if (fgets(Name, 100, pFile) != NULL) {
			// " "���� ��ūȭ
			pszToken = strtok(Name, pszSep);
			// ��ū�� NULL�� ������!
			while (pszToken != NULL) {
				if (strcmp(Name, "\n") == 0) {
					pszToken = strtok(NULL, pszSep);
					continue;
				}
				//�̸�:�� ������ ���� ��ū�� �̸��� �����Ѵ�.
				else if (strcmp(pszToken, cmpName) == 0) {
					pszToken = strtok(NULL, pszSep);
					strcpy(NewNode->szName, pszToken);

					continue;
				}
				//��ȭ��ȣ:�� ������ ���� ��ū�� ��ȭ��ȣ�� �����Ѵ�.
				else if (strcmp(pszToken, cmpPhone) == 0) {
					pszToken = strtok(NULL, pszSep);
					strcpy(NewNode->szPhone, pszToken);
					continue;
				}
				//ī�װ���:�� ������ ���� ��ū�� ī�װ����� �����Ѵ�.
				else if (strcmp(pszToken, cmpCategory) == 0) {
					pszToken = strtok(NULL, pszSep);
					NewNode->category = atoi(pszToken);

					continue;
				}
				//\n���� ��ū�� ����.
				pszToken = strtok(NULL, pszSep);
			}
		}
		if (NewNode->category != 0) {
			if ((*Head) == NULL)
			{
				*Head = NewNode;
			}
			else
			{
				//  ������ ã�� NewNode�� �����Ѵ�. 
				USERDATA* Tail = (*Head);
				while (Tail->pNext != NULL)
				{
					Tail = Tail->pNext;
				}
				// ���� �ּ�
				Temp = Tail;
				// ���� �ּ�
				Tail->pNext = NewNode;
			}
		}
	}
	fclose(pFile);
}