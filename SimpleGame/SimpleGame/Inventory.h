#pragma once
#include <vector>
#include <memory>

class Item;

class Inventory
{
public:
	void AddNewItem(std::unique_ptr<Item>& item);
	const std::unique_ptr<Item>& GetSelectItemToUse(int index) const;
	const std::vector<std::unique_ptr<Item>>* GetItemList() const;
	bool HasItems() const;

	int GetInventoryWeight() const;
	~Inventory();

private:
	std::vector<std::unique_ptr<Item>> m_ItemList;

	int m_InventoryWeight = 0;
};
