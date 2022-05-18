#pragma once
#include "Actions.h"
#include <vector>
#include <string>
#include <memory>

enum class ERoomType;
class Interface;
class Shop;
class ItemManager;
class Hero;
class EnemyManager;
class ActionsList;
class Item;
class Map;

class Game
{
public:
	void StartGame();
	Game(int health, int money, int maxWeight);
	~Game();

private:
	void PrepareStart();
	void PrepareRoom();
	void BuyItems();
	void OpenInventory();
	void MoveToNextRoom();
	bool DoesHeroWinBattle();
	void StartBattle();
	std::string GetInfoAboutHero() const;
	std::string GetInfoAboutHeroStatus() const;
	std::string GetInfoAboutHeroDamageArmor() const;
	void CreateItemListToWrite(const std::vector<std::unique_ptr<Item>>* itemList);
	void ClearItemListToWrite();

	EActions NextAction();
	std::string TakeActionsName(const EActions& action) const;

private:
	std::unique_ptr<ActionsList> m_ActionsList;
	std::unique_ptr<ItemManager> m_ItemManager;
	std::unique_ptr<EnemyManager> m_EnemyManager;
	std::unique_ptr<Interface> m_Menu;
	std::unique_ptr<Shop> m_Shop;
	std::unique_ptr<Hero> m_Hero;
	std::unique_ptr<Map> m_Map;
	std::vector<std::string> m_ItemListToWrite;
	bool m_GameOver = false;
	std::vector<EActions> m_Actions;
};