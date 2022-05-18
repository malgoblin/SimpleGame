#include "Inventory.h"
#include "Item.h"

void Inventory::AddNewItem(std::unique_ptr<Item>& item)
{
	if (item)
	{
		m_InventoryWeight += item->GetWeight();
		m_ItemList.push_back(std::move(item));
	}
}

const std::unique_ptr<Item>& Inventory::GetSelectItemToUse(int index) const
{
	if ((index >= 0) && (index < m_ItemList.size()))
		return m_ItemList[index];
	return m_ItemList[0];
}

const std::vector<std::unique_ptr<Item>>* Inventory::GetItemList() const
{
	return &m_ItemList;
}

bool Inventory::HasItems() const
{
	return !m_ItemList.empty();
}

int Inventory::GetInventoryWeight() const
{
	return m_InventoryWeight;
}

Inventory::~Inventory()
{
}
