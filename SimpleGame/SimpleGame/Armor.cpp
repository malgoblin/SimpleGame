#include "Armor.h"


Armor::Armor(int buyCost, int sellCost, int weight, int armor, const std::string& name)
	: Item(buyCost, sellCost, weight, name)
	, m_Armor(armor)
{
	m_InfoAboutItem = m_Name + " - weight:" + std::to_string(m_Weight) + " cost:" + std::to_string(m_BuyCost) + " armor:" + std::to_string(m_Armor);
}

int Armor::GetArmor() const
{
	return m_Armor;
}

EItemType Armor::GetType() const
{
	return EItemType::armor;
}

std::string Armor::GetInfoAboutItem() const
{
	return m_InfoAboutItem;
}