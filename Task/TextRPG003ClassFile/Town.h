#pragma once
#include "Zone.h"

class UTown : public UZone
{
	// �������̽� ����ȭ.
public:
	// ���������� �������� �̴ϴ�.
	// ���� ���� ���Ǵ� ���
	UZone* InPlayer(class UPlayer& _Player/*, int& Result*/);
};

