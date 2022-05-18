#include "ItemManager.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

ItemManager::~ItemManager()
{
}

void ItemManager::ClearItemList()
{
	m_ItemList.clear();
}


std::vector<std::unique_ptr<Item>>* ItemManager::CreateItemList(int itemCount)
{
	ClearItemList();
	const std::vector<std::unique_ptr<Weapon>>* weaponList = m_DefaultWeaponList.GetWeaponList();
	const std::vector<std::unique_ptr<Armor>>* armorList = m_DefaultArmorsList.GetArmorList();
	
	size_t weaponSize = weaponList->size();
	size_t armorSize = armorList->size();

	int weaponCount = itemCount / 2;
	int armorCount = itemCount - weaponCount;

	m_ItemList.reserve(weaponCount + armorCount);

	for (int i = 0; i < weaponCount; ++i)
	{
		int index = std::rand() % weaponSize;
		m_ItemList.push_back(std::unique_ptr<Weapon>(new Weapon(*(weaponList->at(index)))));
	}

	for (int i = 0; i < armorCount; ++i)
	{
		int index = std::rand() % armorSize;
		m_ItemList.push_back(std::unique_ptr<Armor>(new Armor(*(armorList->at(index)))));
	}

	return &m_ItemList;
}


ItemManager::DefaultWeaponsList::DefaultWeaponsList()
{
	m_WeaponList.reserve(5);
	m_WeaponList.push_back(std::unique_ptr<Weapon>(new Weapon(7, 7, 7, 7, "Sword")));
	m_WeaponList.push_back(std::unique_ptr<Weapon>(new Weapon(6, 6, 6, 6, "Axe")));
}

const std::vector<std::unique_ptr<Weapon>>* ItemManager::DefaultWeaponsList::GetWeaponList() const
{
	return &m_WeaponList;
}


ItemManager::DefaultWeaponsList::~DefaultWeaponsList()
{
}

ItemManager::DefaultArmorsList::DefaultArmorsList()
{
	m_ArmorList.reserve(5);
	m_ArmorList.push_back(std::unique_ptr<Armor>(new Armor(5, 5, 5, 5, "Plate")));
	m_ArmorList.push_back(std::unique_ptr<Armor>(new Armor(4, 4, 4, 4, "Leather armor")));
}

const std::vector<std::unique_ptr<Armor>>* ItemManager::DefaultArmorsList::GetArmorList() const
{
	return &m_ArmorList;
}

ItemManager::DefaultArmorsList::~DefaultArmorsList()
{
}
