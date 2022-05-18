#pragma once
#include <memory>

class Enemy;

enum class ERoomType
{
	Shop,
	BattleRoom,
};

class Room
{
public:
	Room(std::unique_ptr<Enemy>& enemy);
	Room();
	ERoomType GetRoomType() const;
	const std::unique_ptr<Enemy>& GetEnemy() const;

private:
	ERoomType m_RoomType;
	std::unique_ptr<Enemy> m_Enemy;
};
