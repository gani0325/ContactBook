#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <malloc.h>

void MainMenu(char* menu) {
	MainMenuUI();

	char menu_tmp = "";	
	scanf("%c", &menu_tmp);
	getchar();
	*menu = menu_tmp;
}