#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PrintAllUI() {
	printf("\n");
	printf("--------------------------------print all[P]--------------------------------\n");
}

void MainMenuUI() {
	printf("\n");
	printf("--------------------------------contact book interface--------------------------------\n");
	printf("add[A]  search[S]  print all[P]  delete[R]  update[U]  category[C]  exit[X]\n");
	printf("insert command : ");
}

void RemoveUI() {
	printf("\n");
	printf("--------------------------------delete[R]--------------------------------\n");
	printf("delete name : ");
}

void CategoryUI() {
	printf("\n");
	printf("--------------------------------show category[C]--------------------------------\n");
	printf("show category number. friend[0], family[1], company[2], other[3]: ");
}

void CreateUI() {
	printf("\n");
	printf("--------------------------------add[A]--------------------------------\n");
}

void SearchUI() {
	printf("\n");
	printf("--------------------------------search[S]--------------------------------\n");
	printf("search name : ");
}

void UpdateUI() {
	printf("\n");
	printf("--------------------------------update[U]--------------------------------\n");
	printf("update name : ");
}
