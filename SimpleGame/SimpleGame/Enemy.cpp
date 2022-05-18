#include "Enemy.h"
#include "Item.h"
#include "Inventory.h"

Enemy::Enemy(int health, int money, const std::string& name)
	: Character(health, money)
	, m_Name(name)
{
}

void Enemy::TakeItems(std::vector<std::unique_ptr<Item>>* itemList)
{
	if (!itemList)
		return;

	for (int i = 0; i < itemList->size(); ++i)
	{
		m_Inventory->AddNewItem((*itemList)[i]);
		SelectItemToUse(i);
	}
}

const std::string& Enemy::GetName() const
{
	return m_Name;
}
