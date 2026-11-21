#include "magaz.h"
void runMagaz(sf::RenderWindow& window, GameData& data)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		data.currentMenu = MENU;
	}
	window.clear(sf::Color(95, 100, 0));
	window.display();
}