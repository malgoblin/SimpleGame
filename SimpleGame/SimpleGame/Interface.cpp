#include "Interface.h"
#include <iostream>


unsigned int Interface::GetAction(const std::string& info, const TActionList& list) const
{
	unsigned int action = 0;
	while (true)
	{
		std::cout << info << std::endl;
		WriteList(list);
		std::cin >> action;
		if ((action > 0) && (action <= list.size()))
		{
			break;
		}
	}
	return (action - 1);
}

void Interface::WriteList(const TActionList& list) const
{
	for (unsigned int i = 0; i < list.size(); ++i)
	{
		std::cout << i + 1 << " - " << list[i] << std::endl;
	}
}

void Interface::WriteMessage(const std::string& info) const
{
	std::cout << info << std::endl;
}
