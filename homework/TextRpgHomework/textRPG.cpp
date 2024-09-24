// TextRpg000.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>

const int LINECOUNT = 50;

const int NAMELEN = 10;

// �������� 
// ��� �������� ������ ��ǻ�� ����� ���� ���´�.
// ���¿� 

char UIName[NAMELEN] = "NONE";

int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

// ���� �߿���
void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    // C��Ÿ�� ���� ���� �����ִ� �Լ�
    int Size = strlen(_Name);
    _Arr[0] = _Name[0];
    // strcpy_s()
    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }
}

// �Լ��� �׳� �ڱⰡ ����� ������ ����� ���̴�.
// �� ���� ������� �����մϴ�.

// �ൿ
void CreatePlayer(const char* const _Ptr, const char* const _uiPtr, int _Att, int _Hp)
{
    // char[100] = 300����
    StrCopy(PlayerName, NAMELEN, _Ptr);
    StrCopy(UIName, NAMELEN, _uiPtr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
}

// ��� ������ �ڵ带 ��ġ�� ���ؼ� �����ؿԽ��ϴ�.
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
    printf_s("���ݷ� : %d\n", _Att);
    printf_s("ü�� : %d\n", _HP);
    

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

int main()
{
    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/;

    CreatePlayer("Player","status", 10, 100);
    CreateMonster("Orc","status", 10, 50);

    PlayerStatusRender();
    MonsterStatusRender();

    // printf_s("�ο��");
    // ���� �̰� �÷��̾��� ������ �̴ϴ�.


}
