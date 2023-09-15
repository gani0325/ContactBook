#pragma once

typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];
	int category;
	struct USERDATA* pNext;
} USERDATA;

void MainMenu(char* menu);
char* Find(USERDATA* Head, char* name);
USERDATA* Create(USERDATA** Head);
USERDATA* Add(USERDATA** Head, USERDATA* NewNode);
void Search(USERDATA* Head);
USERDATA* PrintAll(USERDATA* Head);
USERDATA* SLL_GetNodeAt(USERDATA* Head);
void Remove(USERDATA** Head, USERDATA* Remove);
void Update(USERDATA* Head);
void Category(USERDATA* Head);

void PrintAllUI();
void MainMenuUI();
void RemoveUI();
void CategoryUI();
void CreateUI();
void SearchUI();

USERDATA* Reallocation();
void Exit();
void InputFile();
