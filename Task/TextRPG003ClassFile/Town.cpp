#include "Town.h"
#include <conio.h>
#include "Player.h"

// �����ͳ� ���۷����� ������ 8����Ʈ �̱� ������
UZone* UTown::InPlayer(class UPlayer& _Player)
{
	InMsgPrint();

	while (true)
	{
		// �̸� ����� #include �ִ��� �̷�°� ����.
		_Player.StatusRender();

		std::cout << "0. ü��ȸ��\n";
		std::cout << "1. ��ȭ\n";
		std::cout << "2. �ٸ� �������� �̵�\n";

		int Select = _getch();

		switch (Select)
		{
		case '2':
		{
			UZone* NextZone = ConnectingProgress();
			return NextZone;
			break;
		}
		case '0':
		case '1':
		case '3':
			printf_s("���� �ϼ����� ���� ����Դϴ�.");
			_getch();
			return nullptr;
		default:
			break;
		}

	}
}
