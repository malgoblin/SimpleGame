#include "Game.h"
#include "ActionsList.h"
#include "Hero.h"
#include "Enemy.h"
#include "Shop.h"
#include "Interface.h"
#include "ItemManager.h"
#include "Item.h"
#include "Map.h"
#include "Room.h"
#include "EnemyManager.h"
#include "DefaultConsts.h"
#include <string_view>

std::string Game::TakeActionsName(const EActions& action) const
{
	switch (action)
	{
	case EActions::Move: return "Move to next room";
	case EActions::Buy: return "Buy Items";
	case EActions::Open_Inventory: return "Open Inventory";
	case EActions::Exit: return "Exit";
	case EActions::Start: return "Start Game";
	default: return "Exit";
	}
}

Game::Game(int health, int money, int maxWeight)
	: m_ActionsList(std::unique_ptr<ActionsList>(new ActionsList()))
	, m_ItemManager(std::unique_ptr<ItemManager>(new ItemManager()))
	, m_EnemyManager(std::unique_ptr<EnemyManager>(new EnemyManager()))
	, m_Menu(std::unique_ptr<Interface>(new Interface()))
	, m_Hero(std::unique_ptr<Hero>(new Hero(health, money, maxWeight)))
	, m_Map(std::unique_ptr<Map>(new Map()))
	, m_Actions(m_ActionsList ? m_ActionsList->GetStartActionList() : std::vector<EActions>())
{
} 

void Game::PrepareStart()
{
	if (m_Map)
		m_Map->CreateShopRoom();
}

void Game::PrepareRoom()
{
	if (!m_Map || !m_ActionsList || !m_Map->GetCurrentRoom())
		return;

	if (m_Map->GetCurrentRoom()->GetRoomType() == ERoomType::Shop)
	{
		if (!m_ItemManager)
			return;

		m_Shop = std::unique_ptr<Shop>(new Shop(m_ItemManager->CreateItemList(DefaultConsts::ShopItemCount)));
		m_Actions = m_ActionsList->GetActionListForShop();
	}
	else
	{
		StartBattle();
		if (!DoesHeroWinBattle())
		{
			if (m_Menu)
				m_Menu->WriteMessage("YOU ARE DEAD");

			m_GameOver = true;
		}
		else
		{
			if (m_Menu)
				m_Menu->WriteMessage("CONGRATULATION, You've killed " + m_Map->GetCurrentRoom()->GetEnemy()->GetName());

			m_Actions = m_ActionsList->GetActionListForBattleRoom();
		}
	}

}

std::string Game::GetInfoAboutHero() const
{
	if (!m_Hero)
		return "";

	return "You have Money:" + std::to_string(m_Hero->GetMoney()) + ", Available Weight:" + std::to_string(m_Hero->GetMaxWeight() - m_Hero->GetInventoryWeight());
}

std::string Game::GetInfoAboutHeroStatus() const
{
	if (!m_Hero)
		return "";

	return "Your status - health: " + std::to_string(m_Hero->GetHealth()) + " damage: " + std::to_string(m_Hero->GetDamage()) + " armor: " + std::to_string(m_Hero->GetArmor());
}

std::string Game::GetInfoAboutHeroDamageArmor() const
{
	if (!m_Hero)
		return "";

	return "\nKnow you have - damage: " + std::to_string(m_Hero->GetDamage()) + "; armor: " + std::to_string(m_Hero->GetArmor());
}

void Game::CreateItemListToWrite(const std::vector<std::unique_ptr<Item>>* itemList)
{
	ClearItemListToWrite();
	if (itemList)
	{
		m_ItemListToWrite.reserve(itemList->size());
		for (const auto& item : *itemList)
		{
			if (item)
			{
				m_ItemListToWrite.push_back(item->GetInfoAboutItem());
			}
		}
	}

	m_ItemListToWrite.push_back("Exit");
}

void Game::ClearItemListToWrite()
{
	m_ItemListToWrite.clear();
}

void Game::BuyItems()
{
	if (!m_Shop || !m_Menu || !m_Hero)
		return;

	constexpr std::string_view infoShop = "Enter number for buy items or Exit. ";
	constexpr std::string_view errorWeight = "Can't buy. Too heavy. ";
	constexpr std::string_view errorMoney = "Can't buy. Too expensive. ";

	std::string info = std::string(infoShop) + GetInfoAboutHero();

	bool closeShop = false;

	while (!closeShop)
	{
		CreateItemListToWrite(m_Shop->GetItemList());
		unsigned int nextAction = m_Menu->GetAction(info, m_ItemListToWrite);
		size_t itemCount = m_ItemListToWrite.size();
		if (itemCount == 0 || nextAction == itemCount - 1)
		{
			closeShop = true;
			ClearItemListToWrite();
			break;
		}

		if (m_Hero->GetMoney() >= m_Shop->GetItem(nextAction)->GetBuyCost())
		{
			if (m_Hero->HasEnoughSpaceFor(m_Shop->GetItem(nextAction)->GetWeight()))
			{
				m_Hero->DicreaseMoney(m_Shop->GetItem(nextAction)->GetBuyCost());
				m_Hero->AddNewItem(m_Shop->GetItem(nextAction));
				info = infoShop;
			}
			else
			{
				info = errorWeight;
			}
		}
		else
		{
			info = errorMoney;
		}

		info += GetInfoAboutHero();
	}
}

void Game::OpenInventory()
{
	if (!m_Menu || !m_Hero)
		return;

	constexpr std::string_view infoInventory = "Enter number's item what you want selected to use or Exit. You can use one weapon and one armor";

	CreateItemListToWrite(m_Hero->GetItemList());

	bool closeInventory = false;

	while (!closeInventory)
	{
		std::string info = std::string(infoInventory) + GetInfoAboutHeroDamageArmor();

		unsigned int nextAction = m_Menu->GetAction(info, m_ItemListToWrite);

		if (nextAction + 1 >= m_ItemListToWrite.size())
		{
			closeInventory = true;
			ClearItemListToWrite();
			break;
		}

		m_Hero->SelectItemToUse(nextAction);
	}
}

void Game::MoveToNextRoom()
{
	m_Map->CreateBattleRoom(m_EnemyManager->CreateNewEnemy(m_ItemManager->CreateItemList(DefaultConsts::EnemyItemCount)));
}

EActions Game::NextAction()
{
	constexpr std::string_view info = "Available Actions (enter number). ";

	std::string defaultInfo = std::string(info) + GetInfoAboutHeroStatus();

	std::vector<std::string> actionListToWrite;
	size_t actionsSize = m_Actions.size();

	actionListToWrite.reserve(actionsSize);

	for (int i = 0; i < actionsSize; ++i)
	{
		actionListToWrite.push_back(TakeActionsName(m_Actions[i]));
	}
	return m_Actions[m_Menu->GetAction(defaultInfo, actionListToWrite)];

}

bool Game::DoesHeroWinBattle()
{
	return (m_Hero->GetHealth() > 0);
}

void Game::StartBattle()
{
	if (!m_Hero || !m_Map)
		return;

	const auto& room = m_Map->GetCurrentRoom();
	if (!room)
		return;

	const auto& enemy = room->GetEnemy();
	if (!room)
		return;

	bool battleEnd = false;	
	int heroDamage = m_Hero->GetDamage();
	int heroArmor = m_Hero->GetArmor();
	int enemyDamage = enemy->GetDamage();
	int enemyArmor = enemy->GetArmor();

	int enemyDamageAfterArmor = enemyDamage < heroArmor ? 0 : enemyDamage - heroArmor;
	if (enemyDamageAfterArmor <= 0)
	{
		// if no damage from enemy - autowin
		enemy->DicreaseHealth(enemy->GetHealth());
		return;
	}

	int heroDamageAfterArmor = heroDamage < enemyArmor ? 0 : heroDamage - enemyArmor;

	int i = 0;
	while (!battleEnd)
	{
		enemy->DicreaseHealth(heroDamageAfterArmor);
		m_Hero->DicreaseHealth(enemyDamageAfterArmor);

		if (!m_Hero->IsAlive() || !enemy->IsAlive())
		{
			battleEnd = true;
			break;
		}

		if (++i == DefaultConsts::BattleRoundMaxCount)
		{
			battleEnd = true;
			m_Hero->DicreaseHealth(m_Hero->GetHealth());
			break;
		}	
	}
}

Game::~Game()
{
}

void Game::StartGame()
{
	PrepareStart();
	while (!m_GameOver)
	{
		EActions currentAction = NextAction();

		switch (currentAction)
		{
		case EActions::Move:
			MoveToNextRoom();
			PrepareRoom();
			break;
		case EActions::Open_Inventory:
			OpenInventory();
			break;
		case EActions::Buy:
			BuyItems();
			break;
		case EActions::Start:
			PrepareRoom();
			break;
		case EActions::Exit:
			m_GameOver = true;
			break;
		}
	}
}
