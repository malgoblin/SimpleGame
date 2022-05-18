#pragma once
#include "Character.h"

class Hero : public Character
{
public:
	Hero(int health, int money, int maxWeight);
	void DicreaseMoney(int cost);
	bool HasEnoughSpaceFor(int itemWeight) const;
	int GetMaxWeight() const;

private:
	int m_MaxWeight = 0;
};
