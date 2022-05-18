#include "EnemyManager.h"
#include "Enemy.h"
#include "Item.h"
#include "DefaultConsts.h"

EnemyManager::EnemyManager()
{
	m_EnemyList = {"Goblin", "Ork"};
}

std::unique_ptr<Enemy>& EnemyManager::CreateNewEnemy(std::vector<std::unique_ptr<Item>>* itemList)
{
	const int enemyHealth = std::rand() % DefaultConsts::MaxEnemyHealth + 1;
	const int enemyMoney = std::rand() % DefaultConsts::MaxEnemyMoney;
	const std::string enemyName = m_EnemyList[std::rand() % m_EnemyList.size()];
	m_NewEnemy.reset(new Enemy(enemyHealth, enemyMoney, enemyName));
	if (m_NewEnemy)
		m_NewEnemy->TakeItems(itemList);

	return m_NewEnemy;
}

EnemyManager::~EnemyManager()
{
}
