#pragma once
#include <vector>
#include <memory>

class Item;

class Shop
{
public:
	Shop(std::vector<std::unique_ptr<Item>>* itemList);
	const std::vector<std::unique_ptr<Item>>* GetItemList() const;
	std::unique_ptr<Item>& GetItem(int number);
	~Shop();
private:
	mutable std::vector<std::unique_ptr<Item>> m_ItemList;
};
