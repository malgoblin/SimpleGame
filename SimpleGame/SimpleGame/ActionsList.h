#pragma once
#include "Actions.h"
#include <vector>

class ActionsList
{
public:
	ActionsList();
	const std::vector<EActions>& GetActionListForShop() const;
	const std::vector<EActions>& GetActionListForBattleRoom() const;
	const std::vector<EActions>& GetStartActionList() const;

private:
	std::vector<EActions> m_ActionListForShop;
	std::vector<EActions> m_ActionListForBattleRoom;
	std::vector<EActions> m_ActionListForStart;
};
