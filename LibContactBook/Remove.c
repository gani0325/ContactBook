#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>
#include <locale.h>

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];
	int category;
	struct USERDATA* pNext;
} USERDATA;

void Remove(char szName[]) {
	//printf("\n");
	//printf("--------------------------------����[R]--------------------------------\n");

	//FILE* pFile = NULL;
	//char mystring[100];
	//char name_tmp[100];
	//char name_ans[15];

	//printf("�����ϰ� ���� �̸��� �Է��ϼ��� : ");
	////gets(name_ans);
	//scanf("%s", name_ans);
	//puts(name_ans);

	//USERDATA* RemoveContact;
	//printf("%s", RemoveContact);

	//pFile = fopen("ContactBook.txt", "r");
	//if (pFile == NULL) perror("Error opening file");

	//// feof : �־��� ��Ʈ������ EOF(End Of File. ������ ��)�� ����
	//while (feof(pFile) == 0) {
	//	// fgets : fgets(����,���� ����,����);
	//	if (fgets(mystring, 100, pFile) != EOF) {
	//		// ������ �ѱ���� ���ڵ� �ؾ��� ��
	//		printf("%s\n", mystring);
	//	}
	//}
	//fclose(pFile);
}