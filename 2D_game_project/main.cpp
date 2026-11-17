#include <SFMl/Graphics.hpp>
#include <iostream>
#include "gamedata.h"
#include "saveprogress.h"
int main() {

	sf::RenderWindow window(sf::VideoMode(800, 800), L"Меню игры"); 
	window.setFramerateLimit(60); 

	GameData data;
	LoadProgress(data);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Ошибка";
	}

	sf::RectangleShape btnMaze(sf::Vector2f(300.f, 60.f));
	btnMaze.setPosition(250.f, 180.f);
	btnMaze.setFillColor(sf::Color::Blue);
	sf::Text txtMaze(L"1. Лабиринт", font, 28);
	txtMaze.setPosition(310.f, 192.f);
	txtMaze.setFillColor(sf::Color::White);

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		if (data.currentMenu == MENU) 
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) data.currentMenu = MAZE;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) data.currentMenu = PLATFORMER;

			window.clear(sf::Color::Green);

			window.draw(btnMaze);
			window.draw(txtMaze);
			window.display(); 
		}
		else if (data.currentMenu == MAZE) {
			//runmaze
		}
		else if (data.currentMenu == PLATFORMER) {
			//runplatformer
		}
	}

	return 0;
}