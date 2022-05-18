#include "Hero.h"
#include "Character.h"

Hero::Hero(int health, int money, int maxWeight)
	: Character(health, money)
	, m_MaxWeight(maxWeight)
{
}

void Hero::DicreaseMoney(int cost)
{
	m_Money = m_Money > cost ? m_Money - cost : 0;
}

bool Hero::HasEnoughSpaceFor(int itemWeight) const
{
	return (GetInventoryWeight() <= m_MaxWeight - itemWeight);
}

int Hero::GetMaxWeight() const
{
	return m_MaxWeight;
}
