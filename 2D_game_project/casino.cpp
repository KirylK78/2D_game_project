#include "casino.h"
void runCasino(sf::RenderWindow& window, GameData& data)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		data.currentMenu = MENU;
		return;
	}

	window.clear(sf::Color(100, 70, 200));

	window.display();
}