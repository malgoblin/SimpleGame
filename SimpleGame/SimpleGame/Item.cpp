#include "Item.h"

Item::Item(int buyCost, int sellCost, int weight, const std::string& name)
	: m_BuyCost(buyCost)
	, m_SellCost(sellCost)
	, m_Weight(weight)
	, m_Name(name)
{
}

int Item::GetBuyCost() const
{
	return m_BuyCost;
}

int Item::GetSellCost() const
{
	return m_SellCost;
}

int Item::GetWeight() const
{
	return m_Weight;
}

const std::string& Item::GetName() const
{
	return m_Name;
}
