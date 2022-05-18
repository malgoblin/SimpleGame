#pragma once

#include <string>
#include <vector>

class Interface
{
	using TActionList = std::vector<std::string>;

public:
	unsigned int GetAction(const std::string& info, const TActionList& list) const;
	void WriteMessage(const std::string& info) const;

private:	
	void WriteList(const TActionList& list) const;
};
