#pragma once
#include "Item.h"
#include <string>


class Weapon : public Item
{
public:
	Weapon(int buyCost, int sellCost, int weight, int damage, const std::string& name);
	int GetDamage() const;
	virtual EItemType GetType() const override;
	virtual std::string GetInfoAboutItem() const override;

private:
	int m_Damage = 0;
	std::string m_InfoAboutItem;
};
