#pragma once
#include <memory>

class Enemy;
class Room;

class Map
{
public:
	void CreateBattleRoom(std::unique_ptr<Enemy>& enemy);
	void CreateShopRoom();
	const std::unique_ptr<Room>& GetCurrentRoom() const;

private:
	std::unique_ptr<Room> m_CurrentRoom;
};
