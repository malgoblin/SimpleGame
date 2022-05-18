#include "Map.h"
#include "Room.h"
#include "Enemy.h"

void Map::CreateBattleRoom(std::unique_ptr<Enemy>& enemy)
{
	m_CurrentRoom.reset(new Room(enemy));
}

void Map::CreateShopRoom()
{
	m_CurrentRoom.reset(new Room());
}

const std::unique_ptr<Room>& Map::GetCurrentRoom() const
{
	return m_CurrentRoom;
}
