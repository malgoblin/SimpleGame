#include "Character.h"
#include "Item.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "DefaultConsts.h"

Character::Character(int health, int money)
	: m_Health(health)
	, m_Money(money)
	, m_Damage(DefaultConsts::CharacterDefaultDamage)
	, m_Armor(DefaultConsts::CharacterDefaultArmor)
	, m_Inventory(std::unique_ptr<Inventory>(new Inventory()))
{
}

Character::~Character()
{
}

int Character::GetHealth() const
{
	return m_Health;
}

int Character::GetMoney() const
{
	return m_Money;
}

int Character::GetDamage() const
{
	return m_Damage;
}

int Character::GetArmor() const
{
	return m_Armor;
}

bool Character::IsAlive() const
{
	return GetHealth() > 0;
}


void Character::AddNewItem(std::unique_ptr<Item>& item)
{
	if (m_Inventory)
	{
		m_Inventory->AddNewItem(item);
	}
}

void Character::SelectItemToUse(int number)
{
	if (!m_Inventory || !m_Inventory->HasItems())
		return;

	const auto& selectedItem = m_Inventory->GetSelectItemToUse(number);
	if (!selectedItem)
		return;

	switch (selectedItem->GetType())
	{
	case EItemType::weapon: m_Damage = dynamic_cast<Weapon*>(selectedItem.get())->GetDamage(); break;
	case EItemType::armor: m_Armor = dynamic_cast<Armor*>(selectedItem.get())->GetArmor(); break;
	}
}

const std::vector<std::unique_ptr<Item>>* Character::GetItemList() const
{
	return m_Inventory->GetItemList();
}

int Character::GetInventoryWeight() const
{
	return m_Inventory->GetInventoryWeight();
}

void Character::DicreaseHealth(int lostHealth)
{
	m_Health -= lostHealth;
}