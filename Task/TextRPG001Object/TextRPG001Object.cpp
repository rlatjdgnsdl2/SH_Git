
#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;

const int NAMELEN = 10;

// 절차지향 
// 어떠한 현실적인 개념을 컴퓨터 세계로 끌고 들어온다.
// 상태와 
class Player;
class Player;
class Player;
class Player
{
public:
    Player(const char* const _Ptr, int _Att, int _Hp, int _Speed)
        : PlayerAtt(_Att), PlayerHp(_Hp), PlayerSpeed(_Speed)
    {
        // 배열형은 대입이 안됩니다.
        strcpy_s(PlayerName, NAMELEN, _Ptr);
    }

    int GetAtt()
    {
        return PlayerAtt;
    }

    const char* const GetName()
    {
        return PlayerName;
    }

    int CalSpeed()
    {
        return rand() % PlayerSpeed;
    }

    void StatusRender()
    {
        printf_s("%s Status", PlayerName);
        int nameLineCount = LINECOUNT - strlen(PlayerName) - strlen(" Status");
        for (int i = 0; i < nameLineCount; i += 1)
        {
            printf_s("-");
        }
        printf_s("\n");
        printf_s("공격력 : %d\n", PlayerAtt);
        printf_s("체력 : %d\n", PlayerHp);

        for (int i = 0; i < LINECOUNT; i += 1)
        {
            printf_s("-");
        }
        printf_s("\n");

        // printf_s("---------------------------------------------------\n");
    }

    void DamageRender(const char* const _AttName, int _Att)
    {
        // 랜더링
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, PlayerName, _Att);
    }

    void DamageLogic(int _Att)
    {
        PlayerHp -= _Att;
    }


private:
    int PlayerAtt = 0;
    int PlayerHp = 0;
    int PlayerSpeed = 10;
    char PlayerName[NAMELEN] = "NONE";
};

class Monster
{
public:
    Monster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
        : MonsterAtt(_Att), MonsterHp(_Hp), MonsterSpeed(_Speed)
    {
        // 배열형은 대입이 안됩니다.
        strcpy_s(MonsterName, NAMELEN, _Ptr);
    }

    int GetAtt()
    {
        return MonsterAtt;
    }

    const char* const GetName()
    {
        return MonsterName;
    }

    int CalSpeed()
    {
        return rand() % MonsterSpeed;
    }

    void DamageLogic(int _Att)
    {
        MonsterHp -= _Att;
    }

    void DamageRender(const char* const _AttName, int _Att)
    {
        // 랜더링
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, MonsterName, _Att);
    }

    void StatusRender()
    {
        printf_s("%s Status", MonsterName);
        int nameLineCount = LINECOUNT - strlen(MonsterName) - strlen(" Status");
        for (int i = 0; i < nameLineCount; i += 1)
        {
            printf_s("-");
        }
        printf_s("\n");
        printf_s("공격력 : %d\n", MonsterAtt);
        printf_s("체력 : %d\n", MonsterHp);

        for (int i = 0; i < LINECOUNT; i += 1)
        {
            printf_s("-");
        }
        printf_s("\n");

        // printf_s("---------------------------------------------------\n");
    }

private:
    int MonsterAtt = 10;
    int MonsterHp = 100;
    int MonsterSpeed = 10;
    char MonsterName[NAMELEN] = "NONE";
};

class FightZone
{

};


// 클래스의 필요성
// 함수는 다양한 상황에서 쓸수있게 만들수록 좋다.
// 함수는 작은 기능을 많이 만들고 
// 함수는 한번에 1가지 일을 할수록 좋다.
// 로직과 랜더를 분리해야 한다.

int main()
{
    Player NewPlayer = Player("1", 10, 100, 5);
    Monster NewMonster = Monster("Orc", 10, 100, 10);
    // 플레이어를 만들었다.

    srand(time(0));
    while (true)
    {
        // 화면 전체를 지워라.
        // 콘솔창에 다른 프로그램를 실행해주는 프로그램
        system("cls");

        char Input = ' ';

        // 전역함수는 최대한 지양해야 한다.
        int CurPlayerSpeed = NewPlayer.CalSpeed();
        int CurMonsterSpeed = NewMonster.CalSpeed();


        NewPlayer.StatusRender();
        NewMonster.StatusRender();
        Input = _getch();

        system("cls");
        // 데미지 주고
        // 플레이어가 몬스터보다 빠르다면
        // 플레이어가 먼저 데미지를 준다.
        if (CurPlayerSpeed > CurMonsterSpeed)
        {
            NewMonster.DamageLogic(NewPlayer.GetAtt());
        }
        else
        {
            NewPlayer.DamageLogic(NewMonster.GetAtt());
        }
        // 다시 다 출력
        NewPlayer.StatusRender();
        NewMonster.StatusRender();
        if (CurPlayerSpeed > CurMonsterSpeed)
        {
            NewMonster.DamageRender(NewPlayer.GetName(), NewPlayer.GetAtt());
        }
        else
        {
            NewPlayer.DamageRender(NewMonster.GetName(), NewMonster.GetAtt());
        }
        Input = _getch();

        system("cls");
        if (CurPlayerSpeed > CurMonsterSpeed)
        {
            NewPlayer.DamageLogic(NewMonster.GetAtt());
        }
        else
        {
            NewMonster.DamageLogic(NewPlayer.GetAtt());
        }

        // 다시 다 출력
        NewPlayer.StatusRender();
        NewMonster.StatusRender();

        if (CurPlayerSpeed > CurMonsterSpeed)
        {
            NewMonster.DamageRender(NewPlayer.GetName(), NewPlayer.GetAtt());
            NewPlayer.DamageRender(NewMonster.GetName(), NewMonster.GetAtt());
        }
        else
        {
            NewPlayer.DamageRender(NewMonster.GetName(), NewMonster.GetAtt());
            NewMonster.DamageRender(NewPlayer.GetName(), NewPlayer.GetAtt());
        }


        Input = _getch();
    }

}
