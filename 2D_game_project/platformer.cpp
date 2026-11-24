#include "platformer.h"
void runPlatformer(sf::RenderWindow& window, GameData& data)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		data.currentMenu = MENU;
	}
	window.clear(sf::Color(28, 32, 42));
	window.display();
}