#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	while (feof(pFile) == 0) {
		fgets(name_tmp, 100, pFile);

		// fgets : fgets(����,���� ����,����);
		if (strstr(name_tmp, name_ans) != NULL) {
			// ������ �ѱ���� ���ڵ� �ؾ��� ��
			printf("���� ã�� : %s\n", name_tmp);
		}
	}
	fclose(pFile);
}