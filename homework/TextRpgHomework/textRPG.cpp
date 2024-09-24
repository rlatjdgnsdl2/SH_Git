// TextRpg000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;

const int NAMELEN = 10;

// 절차지향 
// 어떠한 현실적인 개념을 컴퓨터 세계로 끌고 들어온다.
// 상태와 

char UIName[NAMELEN] = "NONE";

int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

int preAtt = 0;
int preDamage = 0;
char preAttr[NAMELEN] = "NONE";
char preDamaged[NAMELEN] = "NONE";




// 아주 중요한
void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    // C스타일 글자 개수 세어주는 함수
    int Size = strlen(_Name);
    _Arr[0] = _Name[0];
    // strcpy_s()
    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }
}

// 함수는 그냥 자기가 만들고 싶으면 만드는 것이다.
// 전 많이 만들수록 좋아합니다.

// 행동
void CreatePlayer(const char* const _Ptr, const char* const _uiPtr, int _Att, int _Hp)
{
    // char[100] = 300번지
    StrCopy(PlayerName, NAMELEN, _Ptr);
    StrCopy(UIName, NAMELEN, _uiPtr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
}

// 모든 문법은 코드를 덜치기 위해서 발전해왔습니다.
void CreateMonster(const char* const _Ptr, const char* const _uiPtr, int _Att, int _Hp)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    StrCopy(UIName, NAMELEN, _uiPtr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
}

void StatusRender(const char* _Name, const char* _UI, int _Att, int _HP)
{
    printf_s("%s %s", _Name ,_UI);

    int nameCount = strlen(_Name);
    int uiCount = strlen(_UI);
    for (int i = 0; i < LINECOUNT-nameCount-uiCount-1; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);
    

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

    // printf_s("---------------------------------------------------\n");
}

void PlayerStatusRender()
{
    StatusRender(PlayerName,UIName, PlayerAtt, PlayerHp);
}

void MonsterStatusRender()
{
    StatusRender(MonsterName,UIName, MonsterAtt, MonsterHp);
}

void Damage(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
    // 랜더링
    

    // 게임 로직
    _DefHp -= _Att;
}
void PrintDamage(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att) {
    if (_AttName == PlayerName) {
        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);
        preAtt = _Att;
        StrCopy(preAttr, NAMELEN, _AttName);
        StrCopy(preDamaged, NAMELEN, _DefName);
    }
    if (_AttName == MonsterName){

        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", preAttr, preDamaged, preAtt);
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);

    }
   

}



int main()
{
    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/;

    CreatePlayer("player","Status", 10, 100);
    CreateMonster("Orc","Status", 10, 50);

    while (true)
    {
        // 화면 전체를 지워라.
        // 콘솔창에 다른 프로그램를 실행해주는 프로그램
        system("cls");

        char Input = ' ';

        PlayerStatusRender();
        MonsterStatusRender();
        Input = _getch();

        Damage(PlayerName, MonsterName, MonsterHp, PlayerAtt);
        PrintDamage(PlayerName, MonsterName, MonsterHp, PlayerAtt);
        Input = _getch();

        Damage(MonsterName, PlayerName, PlayerHp, MonsterAtt);
        PrintDamage(MonsterName, PlayerName, PlayerHp, MonsterAtt);
        Input = _getch();
    }

}
