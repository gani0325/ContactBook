#pragma once

// 구조체 (이름, 전화번호, 카테고리, 연결리스트 주소)
typedef struct USERDATA
{
	char szName[32];
	char szPhone[32];
	int category;
	struct USERDATA* pNext;
} USERDATA;

// 큰 메뉴 UI
void MainMenu(char* menu);

// 세부 메뉴 UI
void PrintAllUI();
void MainMenuUI();
void RemoveUI();
void CategoryUI();
void CreateUI();
void SearchUI();

// 1) 전화번호부 추가
// - 중복 이름 유효성 검사
char* Find(USERDATA* Head, char* name);
// - 새로운 전화번호부 구조체 생성
USERDATA* Create(USERDATA** Head);
// - 연결리스트에 추가
USERDATA* Add(USERDATA** Head, USERDATA* NewNode);

// 2) 전화번호부 검색
void Search(USERDATA* Head);

// 3) 전화번호부 전체 출력
USERDATA* PrintAll(USERDATA* Head);

// 4) 전화번호부 삭제
// - 삭제할 이름의 주소 확인
USERDATA* SLL_GetNodeAt(USERDATA* Head);
// - 연결 리스트로 해당 주소 삭제
void Remove(USERDATA** Head, USERDATA* Remove);
// - 삭제한 노드 메모리 소멸
void SLL_DestroyNode(USERDATA* Remove);

// 5) 전화번호부 수정
void Update(USERDATA* Head);

// 6) 전화번호부 카테고리별 출력
void Category(USERDATA* Head);

// 7) 전화번호부 처음 시작시 주소 재할당
USERDATA* Reallocation();

// 8) 전화번호부 종료시 동적할당 해지
void Exit(USERDATA* Head);