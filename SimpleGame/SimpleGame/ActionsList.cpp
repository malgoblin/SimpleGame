#include "ActionsList.h"

ActionsList::ActionsList()
{
	m_ActionListForShop =
		{ EActions::Move
		, EActions::Buy
		, EActions::Open_Inventory
		, EActions::Exit
	};

	m_ActionListForBattleRoom =
		{ EActions::Move
		, EActions::Open_Inventory
		, EActions::Exit
	};

	m_ActionListForStart =
		{ EActions::Start
		, EActions::Exit
	};
}

const std::vector<EActions>& ActionsList::GetActionListForShop() const
{
	return m_ActionListForShop;
}

const std::vector<EActions>& ActionsList::GetActionListForBattleRoom() const
{
	return m_ActionListForBattleRoom;
}

const std::vector<EActions>& ActionsList::GetStartActionList() const
{
	return m_ActionListForStart;
}
