#pragma once
#include <string>

enum class EItemType
{
	weapon,
	armor
};

class Item
{
public:
	Item(int buyCost, int sellCost, int weight, const std::string& name);

	int GetBuyCost() const;
	int GetSellCost() const;
	int GetWeight() const;
	const std::string& GetName() const;
	virtual EItemType GetType() const = 0;
	virtual std::string GetInfoAboutItem() const = 0;

protected:
	int m_BuyCost = 0;
	int m_SellCost = 0;
	int m_Weight = 0;
	std::string m_Name;
};
