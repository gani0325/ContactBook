# ☎️ ContactBook ☎️
- 전화번호부 프로그램의 개요를 만들고 화면과 메뉴의 구성하며 기능의 확장해보자!!!

### 🛎️ 2조의 규칙
**1️⃣ commit message** 

```c
➕[Feat] : 기능 추가
🚀[Chore] : 실행 파일 및 수정 시 
🚧[Refactor] : 코드 수정 (리팩토링)
📃[Memo] : 주석 수정
🚨[Alert] : 기능 오류 시
```

**2️⃣ 깃허브 push 시 🚨 알리기 (충돌 발생!! Pull 하고 수정하세요!!)**

**3️⃣ 1일 1 issue 작성**

**4️⃣ dev branch 에 1차 Merge, main branch 에 최종 Merge**

# ☎️ 프로젝트 ☎️
### 👨‍💻 1. 프로젝트 간트 차트
- ContactBook 개요짜기 (September 7, 2023)
- ContactBook 개요 구체화하기 (September 8, 2023)
- 프로그래밍 시작하기 + 회의록 작성하면서 진행 (September 9, 2023 ~ September 17, 2023)
- ContactBook 발표 하기 (September 18, 2023)

### 👨‍💻 2. 작업순서
- function 만들기
```
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
```

- 회의록
- Tasks Board 칸반보드

### 👨‍💻 3. 다이어그램
```jsx
                           main()
                              |
                              |
                          MainMenu()
          ____________________|___________________________________________________________________________
					|          |          |             |               |         |               |          |     |
		   Find()    Search()   PrintAll()   SLL_GetNodeAt()   Update()   Category()  Reallocation()  UI() Exit() 
       Add()                                Remove()                        
      Create()                          SLL_DestroyNode()                 
```
![image](https://github.com/gani0325/ContactBook/assets/76983526/db8c36dd-1e15-4fc6-9022-f8629ee4e9e4)

### 👨‍💻 4. 소스코드 분석
- **☎️ 전화번호부 추가**
    - **중복 이름 유효성 검사**
        - char* Find(USERDATA* Head, char* name);
        - 처음 추가할 때는 바로 이름을 리턴한다
        - 이름이 중복되었으면 재귀함수를 통해 다시 이름 받는다
        - while(1) 을 통해 null 까지 검사하고, 없으면 기존 이름을 리턴한다
        
        ```jsx
        if ((Head) == NULL)
        	{
        		printf("추가할 이름을 입력하세요:");
        		scanf("%s", &NameTemp);
        		strcpy(name, NameTemp);
        
        		return name;
        	}
        	else {
        		printf("추가할 이름을 입력하세요:");
        		scanf("%s", &NameTemp);
        		strcpy(FindTemp, Current->szName);
        
        		while (1)
        		{
        			if (*FindTemp == *NameTemp) {
        				printf("중복된 이름입니다. 다시 입력해주세요!\n");
        				Find(Current, name);
        			}
        			if (Current->pNext != NULL) {
        				break;
        			}
        			Current = Current->pNext;
        		}
        
        		strcpy(name, NameTemp);
        		return name;
        	}
        ```
        
    
    - **새로운 전화번호부 구조체 생성**
        - USERDATA* Create(USERDATA** Head);
        - ContactBook 이라는 구조체에 이름, 전화번호, 카테고리, 그다음 노드의 포인터는 null 로 받는다
        
        ```jsx
        USERDATA* ContactBook = (USERDATA*)malloc(sizeof(USERDATA));
        
        	char* name = (char*)malloc(sizeof(char));
        	char phone[32];
        	int num = 0;
        
        	printf("%p\n", name);
        	Find(*Head, name);
        	printf("%p", name);
        
        	printf("이름에 맞는 전화번호를 입력하세요(010-0000-0000):");
        	scanf("%s", phone);
        	printf("카테고리에 맞는 숫자를 입력하세요. 친구[0], 가족[1], 직장[2], 기타[3]:");
        	scanf("%d", &num);
        	getchar();
        
        	strcpy(ContactBook->szName, name);
        	strcpy(ContactBook->szPhone, phone);
        	ContactBook->category = num;  //  데이터를 저장한다. 
        	ContactBook->pNext = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화 한다.
        ```
        
    
    - **연결리스트에 추가**
        - USERDATA* Add(USERDATA** Head, USERDATA* NewNode);
        - 처음 주소면 바로 head 에 붙인다
        - tail 주소가 null 일 때까지 tail을 이어서 새로운 노드를 붙인다
        
        ```jsx
        if ((*Head) == NULL)
            {
                *Head = NewNode;
            }
            else
            {
                //  테일을 찾아 NewNode를 연결한다. 
                USERDATA* Tail = (*Head);
                while (Tail->pNext != NULL)
                {
                    Tail = Tail->pNext;
        
                }
                // 이전 주소
                Temp = Tail;
                // 현재 주소
                Tail->pNext = NewNode;
            }
        ```
        
- **☎️ 전화번호부 검색**
    - void Search(USERDATA* Head);
    - 구조체이름과 검색할 이름이 같지 않으면, Current주소는 다음 구조체로 넘어간다
    - 구조체 이름과 검색할 이름이 같으면 출력한다.
    
    ```jsx
    USERDATA* Current = Head;
    	char compareName[32];
    	scanf("%s", compareName);
    	//Current->pNext가 볼 포인터가 있고 구조체이름과 검색할 이름이 같지 않으면, Current주소는 다음 구조체로 넘어간다
    	
    	while (strcmp(Current->szName, compareName) != 0 && Current->pNext != NULL)
    	{
    		Current = Current->pNext;
    	}
    	//구조체 이름과 검색할 이름이 같으면 출력한다.
    	if (strcmp(Current->szName, compareName) == 0) {
    		printf("%s\n", Current->szName);
    		printf("%s\n", Current->szPhone);
    		printf("%d\n", Current->category);
    	}
    ```
    
- **☎️ 전화번호부 전체 출력**
    - USERDATA* PrintAll(USERDATA* Head);
    - 현재 포인터 pNext 주소가 null 일 때까지 출력한다
    
    ```jsx
    USERDATA* Current = Head;
    
    	while (Current != NULL)
    	{
    		printf("[%p] ", Current);
    		printf("이름: %s ", Current->szName);
    		printf("전화번호: %s ", Current->szPhone);
    		printf("카테고리: %d ", Current->category);
    		printf("이전 구조체 포인터 : %p\n", Current->pNext);
    
    		Current = Current->pNext;
    	}
    
    	return Current;
    ```
    
- **☎️ 전화번호부 삭제**
    - **삭제할 이름의 주소 확인**
        - USERDATA* SLL_GetNodeAt(USERDATA* Head);
        - 삭제하고 싶은 이름이랑 같을 때까지 연결 리스트로 이어간 후, 찾은 현재 주소를 리턴한다
        
        ```c
        char removeName[15];	
        	char removeTemp[15];
        	scanf("%s", removeName);
        	getchar();
        
        	USERDATA* Current = Head;
        
        	while (Current != NULL)
        	{	
        		strcpy(removeTemp, Current->szName);
        		if (*removeName == *removeTemp) {
        			break;
        		}
        		Current = Current->pNext;
        	}
        
        	return Current;
        ```
        
    
    - **연결 리스트로 해당 주소 삭제**
        - void Remove(USERDATA** Head, USERDATA* Remove);
        - 삭제할 주소를 만나면 삭제할 pNext와 현재 pNext를 연결시킨다
        
        ```c
        if (*Head == Remove)
        	{
        		*Head = Remove->pNext;
        	}
        	else
        	{
        		USERDATA* Current = *Head;
        		while (Current != NULL)
        		{
        			if (Current->pNext == Remove) {
        				break;
        			}
        			Current = Current->pNext;
        		}
        
        		if (Current != NULL)
        			Current->pNext = Remove->pNext;
        	}
        ```
        
    - **삭제한 노드 메모리 소멸**
        - void SLL_DestroyNode(USERDATA* Remove);
        
        ```c
        free(Remove);
        ```
        
- **☎️ 전화번호부 수정**
    - void Update(USERDATA* Head);
    - 수정하고 싶은 이름을 찾고, 전화번호, 카테고리를 입력한다
    
    ```c
    char UpdateName[32];
        char UpdateNameTemp[32];
        char UpdatePhone[32];
        int UpdateCategory = 0;
        scanf("%s", UpdateName);
    
        while (Current->pNext != NULL)
        {
            //구조체 이름과 수정할 이름이 같으면 출력한다.
            strcpy(UpdateNameTemp, Current->szName);
            if (*UpdateName == *UpdateNameTemp) {
                printf("수정하고 싶은 전화번호를 입력하세요 : ");
                scanf("%s", &UpdatePhone);
                strcpy(Current->szPhone, UpdatePhone);
                printf("수정하고 싶은 카테고리를 입력하세요 친구[0], 가족[1], 직장[2], 기타[3] : ");
                scanf("%d", &UpdateCategory);
                getchar();
                Current->category = UpdateCategory;
                break;
            }
            Current = Current->pNext;
        }
    ```
    
- **☎️ 전화번호부 카테고리별 출력**
    - void Category(USERDATA* Head);
    - 삭제하고자 하는 카테고리의 번호를 받아서 모두 출력한다
    
    ```c
    int CategoryNum = 0;
        scanf("%d", &CategoryNum);
        
        while (1)
        {
            //구조체 이름과 검색할 이름이 같으면 출력한다.
            if (Current->category == CategoryNum) {
                printf("이름: %s ", Current->szName);
                printf("전화번호: %s ", Current->szPhone);
                printf("카테고리: %d ", Current->category);
                printf("\n");
            }
            if (Current->pNext == NULL) {
                break;
            }
            Current = Current->pNext;
        }
    ```
    
- **☎️ 전화번호부 처음 실행 시 주소 재할당**
- **☎️ 전화번호부 UI**
    - 함수별로 출력할 UI 를 모았다
    
    ```c
    void PrintAllUI() {
    	printf("\n");
    	printf("--------------------------------전체 출력[P]--------------------------------\n");
    }
    
    void MainMenuUI() {
    	printf("\n");
    	printf("--------------------------------전화번호부 인터페이스--------------------------------\n");
    	printf("추가[A]  검색[S]  전체 출력[P]  삭제[R]  수정[U]  카테고리 출력[C]  프로그램 종료[X]\n");
    	printf("원하시는 명령어를 입력하세요 : ");
    }
    
    void RemoveUI() {
    	printf("\n");
    	printf("--------------------------------삭제[R]--------------------------------\n");
    	printf("삭제하고 싶은 이름을 입력하세요 : ");
    }
    
    void CategoryUI() {
    	printf("\n");
    	printf("--------------------------------카테고리 출력[C]--------------------------------\n");
    	printf("보고 싶은 카테고리에 맞는 숫자를 입력하세요. 친구[0], 가족[1], 직장[2], 기타[3]: ");
    }
    
    void CreateUI() {
    	printf("\n");
    	printf("--------------------------------추가[A]--------------------------------\n");
    }
    
    void SearchUI() {
    	printf("\n");
    	printf("--------------------------------검색[S]--------------------------------\n");
    	printf("검색하고 싶은 이름을 입력하세요 : ");
    }
    
    void UpdateUI() {
    	printf("\n");
    	printf("--------------------------------수정[U]--------------------------------\n");
    	printf("수정하고 싶은 이름을 입력하세요 : ");
    }
    ```
    
- **☎️ 전화번호부 끝**
    - void Exit(USERDATA* Head);
    - 전화번호부 종료시 동적할당 소멸시키기
    
    ```c
    while (Current->pNext != NULL) {
            free(Current);
        }
    ```


### 👨‍💻 5. 프로젝트 성과 결과
- **☎️ 전화번호부 추가**
    ![image](https://github.com/gani0325/ContactBook/assets/76983526/5327f433-b8d5-459a-8dbc-7314d37b457a)
- **☎️ 전화번호부 검색**
   ![image](https://github.com/gani0325/ContactBook/assets/76983526/0defe830-b48a-4cd6-927b-3cbc335595b6)
- **☎️ 전화번호부 전체 출력**
   ![image](https://github.com/gani0325/ContactBook/assets/76983526/35b182d3-788e-45df-b5c3-feed25be4067)
- **☎️ 전화번호부 삭제**
   ![image](https://github.com/gani0325/ContactBook/assets/76983526/31ba01e4-bab5-4f78-961b-46ccb660bc80)
- **☎️ 전화번호부 수정**
  ![image](https://github.com/gani0325/ContactBook/assets/76983526/ee852e2c-5708-4774-bc12-911b336506e0)
- **☎️ 전화번호부 카테고리별 출력**
  ![image](https://github.com/gani0325/ContactBook/assets/76983526/56abf788-636a-4092-8a0a-fd89e1e5c0b6)    
- **☎️ 전화번호부 처음 실행 시 주소 재할당**
- **☎️ 전화번호부 UI**
    ![image](https://github.com/gani0325/ContactBook/assets/76983526/ef09d0c4-0945-49d4-8bbc-ba938413b7b8)
- **☎️ 전화번호부 끝**
    ![image](https://github.com/gani0325/ContactBook/assets/76983526/4e20efa9-a4ed-4953-8df7-46b2d65f6231)
