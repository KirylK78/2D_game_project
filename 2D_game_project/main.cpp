#include <SFMl/Graphics.hpp>
#include <iostream>
#include "gamedata.h"
#include "saveprogress.h"
#include "maze.h"
#include "platformer.h"
#include "casino.h"
#include "magaz.h"
int main() {

	sf::RenderWindow window(sf::VideoMode(1100, 700), L"Game");  
	window.setFramerateLimit(60); 

	GameData data; 
	LoadProgress(data); 

	sf::Font font; 
	font.loadFromFile("StiffStaff-Heavy.otf");
	  
	sf::Texture diamondTextur; 
	diamondTextur.loadFromFile("papik.png");
	sf::Sprite diamondSP(diamondTextur); 
	diamondSP.setPosition(710.f, 10.f); 
	diamondSP.setScale(
		90.f / diamondTextur.getSize().x, 
	    40.f / diamondTextur.getSize().y 
		);

	sf::Texture SKINDEFTEXTUR;
	SKINDEFTEXTUR.loadFromFile("skindef.jpg");
	sf::Sprite SKINDEFSP(SKINDEFTEXTUR);
	SKINDEFSP.setPosition(670.f, 400.f); 
	SKINDEFSP.setScale(
		200.f / SKINDEFTEXTUR.getSize().x, 
		200.f / SKINDEFTEXTUR.getSize().y 
	);

	sf::Texture SKIN1TEXTUR;
	SKIN1TEXTUR.loadFromFile("skin1.jpg");
	sf::Sprite SKIN1SP(SKIN1TEXTUR);
	SKIN1SP.setPosition(670.f, 400.f);
	SKIN1SP.setScale(
		200.f / SKIN1TEXTUR.getSize().x,
		200.f / SKIN1TEXTUR.getSize().y
	);

	sf::Texture SKIN2TEXTUR;
	SKIN2TEXTUR.loadFromFile("skin2.jpg");
	sf::Sprite SKIN2SP(SKIN2TEXTUR);
	SKIN2SP.setPosition(670.f, 400.f);
	SKIN2SP.setScale(
		200.f / SKIN2TEXTUR.getSize().x,
		200.f / SKIN2TEXTUR.getSize().y
	);

	sf::Texture SKIN3TEXTUR;
	SKIN3TEXTUR.loadFromFile("skin3.jpg");
	sf::Sprite SKIN3SP(SKIN3TEXTUR);
	SKIN3SP.setPosition(670.f, 400.f);
	SKIN3SP.setScale(
		200.f / SKIN3TEXTUR.getSize().x,
		200.f / SKIN3TEXTUR.getSize().y
	);

	sf::Texture SKIN4TEXTUR;
	SKIN4TEXTUR.loadFromFile("skin4.jpg");
	sf::Sprite SKIN4SP(SKIN4TEXTUR);
	SKIN4SP.setPosition(670.f, 400.f);
	SKIN4SP.setScale(
		200.f / SKIN4TEXTUR.getSize().x,
		200.f / SKIN4TEXTUR.getSize().y
	);

	sf::RectangleShape btnMaze(sf::Vector2f(300.f, 60.f)); 
	btnMaze.setPosition(40.f, 90.f); 
	btnMaze.setFillColor(sf::Color(45, 115, 210)); 
	sf::Text txtMaze(L"1. Лабиринт", font, 28); 
	txtMaze.setPosition(100.f, 102.f); 
	txtMaze.setFillColor(sf::Color(245, 248, 255)); 
	btnMaze.setOutlineThickness(4.f); 
	btnMaze.setOutlineColor(sf::Color(110, 175, 255)); 

	sf::RectangleShape btnPlatformer(sf::Vector2f(300.f, 60.f)); 
	btnPlatformer.setPosition(40.f, 180.f); 
	btnPlatformer.setFillColor(sf::Color(45, 115, 210)); 
	sf::Text txtPlatformer(L"2. Прыжки", font, 28); 
	txtPlatformer.setPosition(100.f, 192.f);
	txtPlatformer.setFillColor(sf::Color(245, 248, 255)); 
	btnPlatformer.setOutlineThickness(4.f); 
	btnPlatformer.setOutlineColor(sf::Color(110, 175, 255));

	sf::RectangleShape btnCasino(sf::Vector2f(300.f, 60.f)); 
	btnCasino.setPosition(40.f, 270.f); 
	btnCasino.setFillColor(sf::Color(45, 115, 210)); 
	sf::Text txtCasino(L"3. Рулетка", font, 28);
	txtCasino.setPosition(100.f, 282.f); 
	txtCasino.setFillColor(sf::Color(245, 248, 255)); 
	btnCasino.setOutlineThickness(4.f);
	btnCasino.setOutlineColor(sf::Color(110, 175, 255));  

	sf::RectangleShape btnMagaz(sf::Vector2f(120.f, 40.f)); 
	btnMagaz.setPosition(839.f, 10.f);
	btnMagaz.setFillColor(sf::Color(45, 115, 210)); 
	sf::Text txtMagaz(L"Магазин", font, 23); 
	txtMagaz.setPosition(845.f, 10.f); 
	txtMagaz.setFillColor(sf::Color(245, 248, 255));  
	btnMagaz.setOutlineThickness(4.f);
	btnMagaz.setOutlineColor(sf::Color(110, 175, 255));

	sf::RectangleShape btnDiamonds(sf::Vector2f(120.f, 40.f)); 
	btnDiamonds.setPosition(700.f, 10.f); 
	btnDiamonds.setFillColor(sf::Color(45, 115, 210)); 
	sf::Text txtDiamonds(std::to_wstring(data.Diamonds), font, 20);
	txtDiamonds.setPosition(770.f, 20.f);
	txtDiamonds.setFillColor(sf::Color(245, 248, 255)); 
	btnDiamonds.setOutlineThickness(4.f);
	btnDiamonds.setOutlineColor(sf::Color(110, 175, 255)); 

	while (window.isOpen()) 
	{
		sf::Vector2i CursorPosit = sf::Mouse::getPosition(window);
		sf::Vector2f MousePosit = window.mapPixelToCoords(CursorPosit); 

		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) window.close();
			if (data.currentMenu == MENU) {
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
						if ((data.PlayerSkin == SKINDEF) && (data.unlockSKIN[1] == 1)) {
							data.PlayerSkin = SKIN1;
						}
						else if ((data.PlayerSkin == SKIN1) && (data.unlockSKIN[2] == 1)) {
							data.PlayerSkin = SKIN2;
						}
						else if ((data.PlayerSkin == SKIN2) && (data.unlockSKIN[3] == 1)) {
							data.PlayerSkin = SKIN3;
						}
						else if ((data.PlayerSkin == SKIN3) && (data.unlockSKIN[4] == 1)) {
							data.PlayerSkin = SKIN4;
						}
						else if ((data.PlayerSkin == SKIN4) && (data.unlockSKIN[0] == 1)) {
							data.PlayerSkin = SKINDEF;
						}
				}
				else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
					if ((data.PlayerSkin == SKINDEF) && (data.unlockSKIN[4] == 1)) {
						data.PlayerSkin = SKIN4;
					}
					else if ((data.PlayerSkin == SKIN4) && (data.unlockSKIN[3] == 1)) {
						data.PlayerSkin = SKIN3;
					}
					else if ((data.PlayerSkin == SKIN3) && (data.unlockSKIN[2] == 1)) {
						data.PlayerSkin = SKIN2;
					}
					else if ((data.PlayerSkin == SKIN2) && (data.unlockSKIN[1] == 1)) {
						data.PlayerSkin = SKIN1;
					}
					else if ((data.PlayerSkin == SKIN1) && (data.unlockSKIN[0] == 1)) {
						data.PlayerSkin = SKINDEF;
					}
				}
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { 
				if (data.currentMenu == MENU) {
					if (btnMaze.getGlobalBounds().contains(MousePosit)){
						data.currentMenu = MAZE;
					}
					else if (btnPlatformer.getGlobalBounds().contains(MousePosit)){
						data.currentMenu = PLATFORMER;
					}
					else if (btnCasino.getGlobalBounds().contains(MousePosit)) {
						data.currentMenu = CASINO;
					}
					else if (btnMagaz.getGlobalBounds().contains(MousePosit)) {
						data.currentMenu = MAGAZ;
					}
				}
			}
		}
		if (data.currentMenu == MENU) 
		{
			if (btnMaze.getGlobalBounds().contains(MousePosit)) {  
				btnMaze.setOutlineColor(sf::Color(0, 0, 250));
			}
			else
			{
				btnMaze.setOutlineColor(sf::Color(110, 175, 255));
			}

			if (btnPlatformer.getGlobalBounds().contains(MousePosit)) {
				btnPlatformer.setOutlineColor(sf::Color(0, 0, 250)); 
			}
			else
			{
				btnPlatformer.setOutlineColor(sf::Color(110, 175, 255)); 
			}

			if (btnCasino.getGlobalBounds().contains(MousePosit)) {
				btnCasino.setOutlineColor(sf::Color(0, 0, 250)); 
			}
			else
			{
				btnCasino.setOutlineColor(sf::Color(110, 175, 255));
			}

			if (btnMagaz.getGlobalBounds().contains(MousePosit)) {
				btnMagaz.setOutlineColor(sf::Color(0, 0, 250));
			}
			else
			{
				btnMagaz.setOutlineColor(sf::Color(110, 175, 255));
			}

			txtDiamonds.setString(std::to_string(data.Diamonds));
			window.clear(sf::Color(28, 32, 42)); 
			window.draw(btnMaze); 
			window.draw(txtMaze);
			window.draw(btnPlatformer);
			window.draw(txtPlatformer);
			window.draw(btnDiamonds);
			window.draw(txtDiamonds);
			window.draw(diamondSP);
			window.draw(btnCasino);
			window.draw(txtCasino);
			window.draw(btnMagaz);
			window.draw(txtMagaz);
			if (data.PlayerSkin == SKINDEF) window.draw(SKINDEFSP);
			else if (data.PlayerSkin == SKIN1) window.draw(SKIN1SP);
			else if (data.PlayerSkin == SKIN2) window.draw(SKIN2SP);
			else if (data.PlayerSkin == SKIN3) window.draw(SKIN3SP);
			else if (data.PlayerSkin == SKIN4) window.draw(SKIN4SP);
			window.display(); 
		}
		else if (data.currentMenu == PLATFORMER) {
			runPlatformer(window, data);
		}
		else if (data.currentMenu == MAZE) {
			runMaze(window, data);
		}
		else if (data.currentMenu == CASINO) {
			runCasino(window, data);
		}
		else if (data.currentMenu == MAGAZ) {
			runMagaz(window, data);
		}
	}
	SaveProgress(data);
	return 0;
}