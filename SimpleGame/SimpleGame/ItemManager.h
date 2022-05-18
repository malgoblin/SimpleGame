#pragma once
#include <vector>
#include <memory>

class Item;
class Weapon;
class Armor;

class ItemManager
{
public:
	std::vector<std::unique_ptr<Item>>* CreateItemList(int itemCount);
	~ItemManager();

private:
	void ClearItemList();

private:
	std::vector<std::unique_ptr<Item>> m_ItemList;

	class DefaultWeaponsList
	{
	public:
		DefaultWeaponsList();
		const std::vector<std::unique_ptr<Weapon>>* GetWeaponList() const;
		~DefaultWeaponsList();

	private:
		std::vector<std::unique_ptr<Weapon>> m_WeaponList;
	} m_DefaultWeaponList;

	class DefaultArmorsList
	{
	public:
		DefaultArmorsList();
		const std::vector<std::unique_ptr<Armor>>* GetArmorList() const;
		~DefaultArmorsList();

	private:
		std::vector<std::unique_ptr<Armor>> m_ArmorList;
	} m_DefaultArmorsList;
};