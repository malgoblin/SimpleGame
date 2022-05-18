#pragma once
#include "Item.h"
#include <string>

class Armor : public Item
{
public:
	Armor(int buyCost, int sellCost, int weight, int armor, const std::string& name);
	int GetArmor() const;
	virtual EItemType GetType() const override;
	virtual std::string GetInfoAboutItem() const override;

private:
	int m_Armor = 0;
	std::string m_InfoAboutItem;
};
