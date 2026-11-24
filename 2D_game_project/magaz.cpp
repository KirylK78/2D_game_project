#include "magaz.h"
#include "gamedata.h"
void runMagaz(sf::RenderWindow& window, GameData& data)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		data.currentMenu = MENU;
	}

	sf::Font font;

	font.loadFromFile("StiffStaff-Heavy.otf");

	sf::Texture skin1;
	sf::Texture skin2;
	sf::Texture skin3;
	sf::Texture skin4;

	skin1.loadFromFile("papik.png");
	skin2.loadFromFile("papik.png");
	skin3.loadFromFile("papik.png");
	skin4.loadFromFile("papik.png");

	sf::Sprite SKIN1(skin1);
	SKIN1.setPosition(10.f, 10.f);
	SKIN1.setScale(
	250.f / skin1.getSize().x,
	300.f / skin1.getSize().y
	);

	sf::Sprite SKIN2(skin2);
	SKIN2.setPosition(260.f, 10.f);
	SKIN2.setScale(
		250.f / skin2.getSize().x,
		300.f / skin2.getSize().y
	);

	sf::Sprite SKIN3(skin3);
	SKIN3.setPosition(510.f, 10.f);
	SKIN3.setScale(
		250.f / skin3.getSize().x,
		300.f / skin3.getSize().y
	);

	sf::Sprite SKIN4(skin4);
	SKIN4.setPosition(760.f, 10.f);
	SKIN4.setScale(
		250.f / skin4.getSize().x,
		300.f / skin4.getSize().y
	);

	sf::Text txtSKIN1("SKIN1", font, 20);
	txtSKIN1.setPosition(110.f, 280.f);
	txtSKIN1.setFillColor(sf::Color(45, 115, 210));

	sf::Text txtSKIN2("SKIN2", font, 20);
	txtSKIN2.setPosition(360.f, 280.f);
	txtSKIN2.setFillColor(sf::Color(45, 115, 210));

	sf::Text txtSKIN3("SKIN3", font, 20);
	txtSKIN3.setPosition(610.f, 280.f);
	txtSKIN3.setFillColor(sf::Color(45, 115, 210));

	sf::Text txtSKIN4("SKIN4", font, 20);
	txtSKIN4.setPosition(860.f, 280.f);
	txtSKIN4.setFillColor(sf::Color(45, 115, 210));

	sf::RectangleShape btnBuy1(sf::Vector2f(140.f, 30.f));
	btnBuy1.setPosition(65.f, 315.f);
	btnBuy1.setFillColor(sf::Color(45, 115, 210));
	btnBuy1.setOutlineThickness(3.f); 
	btnBuy1.setOutlineColor(sf::Color(110, 175, 255)); 

	sf::RectangleShape btnBuy2(sf::Vector2f(140.f, 30.f));
	btnBuy2.setPosition(315.f, 315.f);
	btnBuy2.setFillColor(sf::Color(45, 115, 210));
	btnBuy2.setOutlineThickness(3.f);
	btnBuy2.setOutlineColor(sf::Color(110, 175, 255));

	sf::RectangleShape btnBuy3(sf::Vector2f(140.f, 30.f));
	btnBuy3.setPosition(565.f, 315.f);
	btnBuy3.setFillColor(sf::Color(45, 115, 210));
	btnBuy3.setOutlineThickness(3.f);
	btnBuy3.setOutlineColor(sf::Color(110, 175, 255));

	sf::RectangleShape btnBuy4(sf::Vector2f(140.f, 30.f));
	btnBuy4.setPosition(815.f, 315.f);
	btnBuy4.setFillColor(sf::Color(45, 115, 210));
	btnBuy4.setOutlineThickness(3.f);
	btnBuy4.setOutlineColor(sf::Color(110, 175, 255));

	sf::Text txtBuy1(L"Купить", font, 28); 
	txtBuy1.setPosition(80.f, 310.f); 
	txtBuy1.setFillColor(sf::Color(245, 248, 255));

	sf::Text txtBuy2(L"Купить", font, 28);
	txtBuy2.setPosition(330.f, 310.f);
	txtBuy2.setFillColor(sf::Color(245, 248, 255));

	sf::Text txtBuy3(L"Купить", font, 28);
	txtBuy3.setPosition(580.f, 310.f);
	txtBuy3.setFillColor(sf::Color(245, 248, 255));

	sf::Text txtBuy4(L"Купить", font, 28);
	txtBuy4.setPosition(830.f, 310.f);
	txtBuy4.setFillColor(sf::Color(245, 248, 255));

	window.clear(sf::Color(28, 32, 42));

	sf::Vector2i CursorPosit = sf::Mouse::getPosition(window);
	sf::Vector2f MousePosit = window.mapPixelToCoords(CursorPosit);

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
	}
	if (btnBuy1.getGlobalBounds().contains(MousePosit)) {
		btnBuy1.setOutlineColor(sf::Color(0, 0, 250));
	}
	if (btnBuy2.getGlobalBounds().contains(MousePosit)) {
		btnBuy2.setOutlineColor(sf::Color(0, 0, 250));
	}
	if (btnBuy3.getGlobalBounds().contains(MousePosit)) {
		btnBuy3.setOutlineColor(sf::Color(0, 0, 250));
	}
	if (btnBuy4.getGlobalBounds().contains(MousePosit)) {
		btnBuy4.setOutlineColor(sf::Color(0, 0, 250));
	}
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (btnBuy1.getGlobalBounds().contains(MousePosit)) {
			if ((data.Diamonds >= 5) && (data.unlockSKIN[1] == false)){
				data.unlockSKIN[1] = true;
				data.Diamonds = data.Diamonds - 5;
			}
		}
		if (btnBuy2.getGlobalBounds().contains(MousePosit)) {
			if ((data.Diamonds >= 10) && (data.unlockSKIN[2] == false)) {
				data.unlockSKIN[2] = true;
				data.Diamonds = data.Diamonds - 10;
			}
		}
		if (btnBuy3.getGlobalBounds().contains(MousePosit)) {
			if ((data.Diamonds >= 15) && (data.unlockSKIN[3] == false)) {
				data.unlockSKIN[3] = true;
				data.Diamonds = data.Diamonds - 15;
			}
		}
		if (btnBuy4.getGlobalBounds().contains(MousePosit)) {
			if ((data.Diamonds >= 20) && (data.unlockSKIN[4] == false)) {
				data.unlockSKIN[4] = true;
				data.Diamonds = data.Diamonds - 20;
			}
		}
	}
	window.draw(SKIN1);
	window.draw(SKIN2);
	window.draw(SKIN3);
	window.draw(SKIN4);
	window.draw(txtSKIN1);
	window.draw(txtSKIN2);
	window.draw(txtSKIN3);
	window.draw(txtSKIN4);
	window.draw(btnBuy1);
	window.draw(btnBuy2);
	window.draw(btnBuy3);
	window.draw(btnBuy4);
	window.draw(txtBuy1);
	window.draw(txtBuy2);
	window.draw(txtBuy3);
	window.draw(txtBuy4);

	window.display();
	
}