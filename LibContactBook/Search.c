#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

USERDATA* Search_test(USERDATA* Head)
{
	USERDATA* Current = Head;
	char* compareName = "";
	printf("�˻��ϰ� ���� �̸��� �Է��ϼ��� : ");
	scanf("%s", &compareName);
	//Current->pNext�� �� �����Ͱ� �ְ� ����ü�̸��� �˻��� �̸��� ���� ������, Current�ּҴ� ���� ����ü�� �Ѿ��
	while (strcmp(Current->szName, compareName) != 0 && Current->pNext != NULL)
	{
		Current = Current->pNext;
	}
	//����ü �̸��� �˻��� �̸��� ������ ����Ѵ�.
	if (strcmp(Current->szName, compareName) == 0) {
		printf("%s\n", Current->szName);
		printf("%s\n", Current->szPhone);
		printf("%s\n", Current->category);
	}
	return Current;
}


void Search(char* source) {
	printf("\n");
	printf("--------------------------------�˻�[S]--------------------------------\n");

	FILE* pFile = NULL;

	char name_tmp[100];
	char name_ans[15];

	printf("�˻��ϰ� ���� �̸��� �Է��ϼ��� : ");
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