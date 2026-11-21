#include "maze.h"
void runMaze(sf::RenderWindow& window, GameData& data) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		data.currentMenu = MENU;
		return;
	}

	window.clear(sf::Color(220, 20, 50));

	window.display();
}