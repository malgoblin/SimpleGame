#pragma once
#include <vector>
#include <memory>

class Item;
class Inventory;

class Character
{
public:
	int GetHealth() const;
	int GetMoney() const;
	int GetDamage() const;
	int GetArmor() const;

	bool IsAlive() const;

	void AddNewItem(std::unique_ptr<Item>& item);
	void SelectItemToUse(int number);
	const std::vector<std::unique_ptr<Item>>* GetItemList() const;
	int GetInventoryWeight() const;
	void DicreaseHealth(int lostHealth);
	virtual ~Character();

protected:
	Character(int health, int money);

protected:
	int m_Health = 0;
	int m_Money = 0;
	int m_Damage = 0;
	int m_Armor = 0;
	std::unique_ptr<Inventory> m_Inventory;
};
