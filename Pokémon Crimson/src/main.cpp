#include "Game.h"
#include<iostream>

int main()
{
	try
	{
		Game game;
		game.launch();
	}
	catch (std::exception& e)
	{
		std::cerr << "\nEXCEPTION: " << e.what() << std::endl;
	}
}