#pragma once
#include "Character.h"
#include <string>
#include <vector>
#include <memory>

class Item;

class Enemy : public Character
{
public:
	Enemy(int health, int money, const std::string& name);

	void TakeItems(std::vector<std::unique_ptr<Item>>* itemList);
	const std::string& GetName() const;

private:
	std::string m_Name;
};
