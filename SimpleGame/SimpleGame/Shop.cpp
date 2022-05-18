#include "Shop.h"
#include "Item.h"

Shop::Shop(std::vector<std::unique_ptr<Item>>* itemList)
{ 
	if (!itemList || itemList->empty())
		return;

	m_ItemList.reserve(itemList->size());

	for (auto& item : *itemList)
	{
		m_ItemList.push_back(std::move(item));
	}
}

Shop::~Shop()
{
}

const std::vector<std::unique_ptr<Item>>* Shop::GetItemList() const
{
	if (m_ItemList.empty())
		return nullptr;

	auto it = std::remove_if(m_ItemList.begin(), m_ItemList.end(), [](auto& p) { return !p; });
	if (it != m_ItemList.end())
	{
		m_ItemList.erase(it);
	}

	return &m_ItemList;
}

std::unique_ptr<Item>& Shop::GetItem(int number)
{
	if (number >= 0 && number < m_ItemList.size())
		return m_ItemList[number];
	return m_ItemList[0];
}
