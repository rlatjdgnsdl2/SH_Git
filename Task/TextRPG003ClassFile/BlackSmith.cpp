#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
		int Select = _getch();

		switch (Select)
		{
		case '1':
			Enhance(_Player);

			// Ȯ���� ���δ� 2���� 1
			// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
			// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
			// 1~5������ ���а� ����Ȯ���� ������.
			// �ٿ������ �ʴ´�.
			// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
			// 10~15�� 0���� �����ϸ� 0���� ��������.
			// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.
			return;
			break;
		case '2':
			return;
			break;
		default:
			break;
		}
	}
}

void BlackSmith::Enhance(class UPlayer& _Player)
{
	int EquitAtt = _Player.GetEquiAtt();
	int Gold = _Player.GetGold();
	int result = rand() % 2;
	if (result == 0) {
		if (EquitAtt < 15) {
			if (EquitAtt >= 10) {
				_Player.SetEquiAtt(0);
				printf_s("��ȭ�� �����߽��ϴ�. ���� ���ݷ��� %d�� �˴ϴ�.", _Player.GetEquiAtt());
				_getch();
			}
			else if (EquitAtt >= 6) {
				_Player.SetEquiAtt(EquitAtt - 1);
				printf_s("��ȭ�� �����߽��ϴ�. ���� ���ݷ��� %d�� �˴ϴ�.", _Player.GetEquiAtt());
				_getch();
			}
			else 
			{
				printf_s("��ȭ�� �����߽��ϴ�");
				_getch();
			}
		}
	}
	else if (result == 1) {
		_Player.SetEquiAtt(EquitAtt + 1);
		printf_s("��ȭ�� �����߽��ϴ�. ���� ���ݷ��� %d�� �˴ϴ�.", _Player.GetEquiAtt());
		_getch();
	}

	_Player.SetGold(Gold - (100 * EquitAtt));
}
