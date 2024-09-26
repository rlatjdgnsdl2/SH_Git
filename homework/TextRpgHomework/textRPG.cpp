// TextRpg000.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>  


const int LINECOUNT = 50;

const int NAMELEN = 10;

// �������� 
// ��� �������� ������ ��ǻ�� ����� ���� ���´�.
// ���¿� 
int PlayerAttMin = 0;
int PlayerAtt = 0;
int PlayerHp = 0;
int PlayerSpeed = 10;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
int MonsterSpeed = 10;
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
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    // char[100] = 300����
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
    PlayerSpeed = _Speed;
}

// ��� ������ �ڵ带 ��ġ�� ���ؼ� �����ؿԽ��ϴ�.
void CreateMonster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
    MonsterSpeed = _Speed;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    printf_s("%s Status", _Name);
    int nameLineCount = LINECOUNT - strlen(_Name) - strlen(" Status");
    for (int i = 0; i < nameLineCount; i += 1)
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
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

// ���Ǹ� ���ؼ� �����ߴٰ� �Ѵ�.
void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

// Ŭ������ �ʿ伺
// �Լ��� �پ��� ��Ȳ���� �����ְ� ������� ����.
// �Լ��� ���� ����� ���� ����� 
// �Լ��� �ѹ��� 1���� ���� �Ҽ��� ����.
// ������ ������ �и��ؾ� �Ѵ�.
void DamageRender(const char* const _AttName, const char* const _DefName, int _Att)
{
    // ������
    printf_s("%s �� %s�� �����ؼ� %d�� �������� �������ϴ�.\n", _AttName, _DefName, _Att);
}

void DamageLogic(int& _DefHp, int _Att)
{
    _DefHp -= _Att;
}

void SpeedCheckRender(const char* const _Name)
{
    printf_s("%s �� �����Դϴ�\n", _Name);
}

void SetRandomSpeed() 
{
    PlayerSpeed = (rand() % 20);
    MonsterSpeed = (rand() % 10);
}




int main()
{
    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/;

    // ������ �İ��� ���弼��.
    CreatePlayer("1", 10, 100, 20);
    CreateMonster("Orc", 10, 100, 10);

    // �÷��̾�� 0~19
    // ���ʹ� 0~9
    // �÷��̾�� ���ʹ� ���� ������ �ڽ��� ���� ���ǵ� �ɷ�
    // �����ϱ� ���� ���Ϳ� �÷��̾�� ���� ���� �ӷ��� �̾Ƴ���.
    // �� ���� ���� ���� �����Ѵ�.

    while (true)
    {
        // ȭ�� ��ü�� ������.
        // �ܼ�â�� �ٸ� ���α׷��� �������ִ� ���α׷�
        system("cls");

        char Input = ' ';


        PlayerStatusRender();
        MonsterStatusRender();
        Input = _getch();

        system("cls");

        SetRandomSpeed();
        if (PlayerSpeed >= MonsterSpeed) 
        {
            // ������ �ְ�
            DamageLogic(MonsterHp, PlayerAtt);
            // �ٽ� �� ���
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(PlayerName);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
            Input = _getch();

            system("cls");
            DamageLogic(PlayerHp, MonsterAtt);
            // �ٽ� �� ���
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(PlayerName);
            DamageRender(PlayerName, MonsterName, PlayerAtt);
            DamageRender(MonsterName, PlayerName, MonsterAtt);

            Input = _getch();
        }
        else if (PlayerSpeed < MonsterSpeed) {


            // ������ �ְ�
            DamageLogic(PlayerHp, MonsterAtt);
            // �ٽ� �� ���
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(MonsterName);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
            Input = _getch();

            system("cls");
            DamageLogic(MonsterHp, PlayerAtt);
            // �ٽ� �� ���
            PlayerStatusRender();
            MonsterStatusRender();
            SpeedCheckRender(MonsterName);
            DamageRender(MonsterName, PlayerName, MonsterAtt);
            DamageRender(PlayerName, MonsterName, PlayerAtt);

            Input = _getch();

        }





        
    }

}
