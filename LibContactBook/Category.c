#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>

void Category() {
	printf("\n");
	printf("--------------------------------ī�װ� ���[C]--------------------------------\n");

	FILE* pFile = NULL;
	char mystring[100];

	pFile = fopen("ContactBook.txt", "r");
	if (pFile == NULL) perror("Error opening file");

	// feof : �־��� ��Ʈ������ EOF(End Of File. ������ ��)�� ����
	while (feof(pFile) == 0) {
		// fgets : fgets(����,���� ����,����);
		if (fgets(mystring, 100, pFile) != EOF) {
			// ������ �ѱ���� ���ڵ� �ؾ��� ��
			printf("%s\n", mystring);
		}
	}
	fclose(pFile);
}