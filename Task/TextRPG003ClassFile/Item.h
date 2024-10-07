#pragma once
class Item
{
private:
	int Att=0;
public:
	void SetAtt(int _value) {
		Att = _value;
	};
	int GetAtt() {
		return Att;
	}
};

