#include "Weapon.h"


Weapon::Weapon(int buyCost, int sellCost, int weight, int damage, const std::string& name)
	: Item(buyCost, sellCost, weight, name)
	, m_Damage(damage)
{
	m_InfoAboutItem = m_Name + " - weight:" + std::to_string(m_Weight) + " cost:" + std::to_string(m_BuyCost) + " damage:" + std::to_string(m_Damage);
}

int Weapon::GetDamage() const
{
	return m_Damage;
}

EItemType Weapon::GetType() const
{
	return EItemType::weapon;
}

std::string Weapon::GetInfoAboutItem() const
{
	return m_InfoAboutItem;
}
