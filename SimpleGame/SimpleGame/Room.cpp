#include "Room.h"
#include "Enemy.h"

Room::Room(std::unique_ptr<Enemy>& enemy)
{
	m_RoomType = ERoomType::BattleRoom;
	m_Enemy = std::move(enemy);
}

Room::Room()
{
	m_RoomType = ERoomType::Shop;
	m_Enemy = nullptr;
}

ERoomType Room::GetRoomType() const
{
	return m_RoomType;
}

const std::unique_ptr<Enemy>& Room::GetEnemy() const
{
	return m_Enemy;
}
