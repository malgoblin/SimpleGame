#include "Game.h"
#include "DefaultConsts.h"
#include <ctime>
#include <iostream>


int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Game game(DefaultConsts::HeroHealth, DefaultConsts::HeroStartMoney, DefaultConsts::HeroWeight);
	game.StartGame();
}
