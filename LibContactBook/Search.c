#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Search_test(USERDATA* Head)
{
	USERDATA* Current = Head;
	char compareName[32];
	printf("�˻��ϰ� ���� �̸��� �Է��ϼ��� : ");
	scanf("%s", compareName);
	//Current->pNext�� �� �����Ͱ� �ְ� ����ü�̸��� �˻��� �̸��� ���� ������, Current�ּҴ� ���� ����ü�� �Ѿ��
	
	while (strcmp(Current->szName, compareName) != 0 && Current->pNext != NULL)
	{
		Current = Current->pNext;
	}
	//����ü �̸��� �˻��� �̸��� ������ ����Ѵ�.
	if (strcmp(Current->szName, compareName) == 0) {
		printf("%s\n", Current->szName);
		printf("%s\n", Current->szPhone);
		printf("%d\n", Current->category);
	}
}


void Search(char* source) {
	SearchUI();

	FILE* pFile = NULL;

	char name_tmp[100];
	char name_ans[15];

	//gets(name_ans);
	scanf("%s", name_ans);
	puts(name_ans);

	pFile = fopen("ContactBook.txt", "r");
	if (pFile == NULL) perror("Error opening file");

	// feof : �־��� ��Ʈ������ EOF(End Of File. ������ ��)�� ����
	while (feof(pFile)) {
		fgets(name_tmp, 100, pFile);

		// fgets : fgets(����,���� ����,����);
		if (strstr(name_tmp, name_ans) != NULL) {
			// ������ �ѱ���� ���ڵ� �ؾ��� ��
			printf("���� ã�� : %s\n", name_tmp);
		}
	}
	fclose(pFile);
}