#pragma once
#include <memory>
#include <vector>
#include <string>

class Enemy;
class Item;

class EnemyManager
{
public:
	EnemyManager();
	std::unique_ptr<Enemy>& CreateNewEnemy(std::vector<std::unique_ptr<Item>>* itemList);
	~EnemyManager();

private:
	std::vector<std::string> m_EnemyList;
	std::unique_ptr<Enemy> m_NewEnemy;
};
