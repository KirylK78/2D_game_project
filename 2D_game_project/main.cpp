#include <SFMl/Graphics.hpp>
#include <iostream>
#include "gamedata.h"
#include "saveprogress.h"
#include "maze.h"
#include "platformer.h"
#include "casino.h"
#include "magaz.h"
int main() {

	sf::RenderWindow window(sf::VideoMode(1100, 700), L"Казик");  //Инициализация основного окна
	window.setFramerateLimit(60); //Ограничение фпс

	GameData data; 
	LoadProgress(data); //Загрузка сохранений (валюта,скины)

	sf::Font font; //Загрузка основного шрифта
	if (!font.loadFromFile("CormorantGaramond-VariableFont_wght.ttf")) {
		std::cout << "Ошибка загрузки шрифта";
	}
	  
	sf::Texture diamondTextur; //Загрузка изображения алмаза
	if (!diamondTextur.loadFromFile("papik.png")) {
		std::cout << "Ошибка загрузки изобр.";
	}

	sf::Sprite diamondSP(diamondTextur); //Создание самого изображения в меню
	diamondSP.setPosition(710.f, 10.f); //Местоположение
	diamondSP.setScale(
		90.f / diamondTextur.getSize().x, //Ширина
	    40.f / diamondTextur.getSize().y //Высота
		);

	sf::RectangleShape btnMaze(sf::Vector2f(300.f, 60.f)); //Инициализация кнопки ЛАБИРИНТ и ее размер
	btnMaze.setPosition(40.f, 90.f); //Местоположение
	btnMaze.setFillColor(sf::Color(45, 115, 210)); //Цвет
	sf::Text txtMaze(L"1. Лабиринт", font, 28); //Инициализация текста внутри кнопки ЛАБИРИНТ
	txtMaze.setPosition(100.f, 102.f); //Местоположение
	txtMaze.setFillColor(sf::Color(245, 248, 255)); //Цвет 
	btnMaze.setOutlineThickness(4.f); //Добавление границы кнопки и ее размер
	btnMaze.setOutlineColor(sf::Color(110, 175, 255)); //Цвет 

	sf::RectangleShape btnPlatformer(sf::Vector2f(300.f, 60.f)); //Инициализация кнопки ПРЫЖКИ и ее размер
	btnPlatformer.setPosition(40.f, 180.f); //Местоположение
	btnPlatformer.setFillColor(sf::Color(45, 115, 210)); //Цвет
	sf::Text txtPlatformer(L"2. Прыжки", font, 28); //Инициализация текста внутри кнопки ПРЫЖКИ
	txtPlatformer.setPosition(100.f, 192.f); //Местоположение
	txtPlatformer.setFillColor(sf::Color(245, 248, 255)); //Цвет 
	btnPlatformer.setOutlineThickness(4.f); //Добавление границы кнопки и ее размер
	btnPlatformer.setOutlineColor(sf::Color(110, 175, 255)); //Цвет 

	sf::RectangleShape btnCasino(sf::Vector2f(300.f, 60.f)); //Инициализация кнопки ПРЫЖКИ и ее размер
	btnCasino.setPosition(40.f, 270.f); //Местоположение
	btnCasino.setFillColor(sf::Color(45, 115, 210)); //Цвет
	sf::Text txtCasino(L"3. Рулетка", font, 28); //Инициализация текста внутри кнопки ПРЫЖКИ
	txtCasino.setPosition(100.f, 282.f); //Местоположение
	txtCasino.setFillColor(sf::Color(245, 248, 255)); //Цвет 
	btnCasino.setOutlineThickness(4.f); //Добавление границы кнопки и ее размер
	btnCasino.setOutlineColor(sf::Color(110, 175, 255)); //Цвет 

	sf::RectangleShape btnMagaz(sf::Vector2f(120.f, 40.f)); //Инициализация кнопки ПРЫЖКИ и ее размер
	btnMagaz.setPosition(835.f, 10.f); //Местоположение
	btnMagaz.setFillColor(sf::Color(45, 115, 210)); //Цвет
	sf::Text txtMagaz(L"Магазин", font, 28); //Инициализация текста внутри кнопки ПРЫЖКИ
	txtMagaz.setPosition(845.f, 10.f); //Местоположение
	txtMagaz.setFillColor(sf::Color(245, 248, 255)); //Цвет 
	btnMagaz.setOutlineThickness(4.f); //Добавление границы кнопки и ее размер
	btnMagaz.setOutlineColor(sf::Color(110, 175, 255)); //Цвет

	sf::RectangleShape btnDiamonds(sf::Vector2f(120.f, 40.f)); //Инициализация счетчика алмазов и его размер
	btnDiamonds.setPosition(700.f, 10.f); //Местоположение
	btnDiamonds.setFillColor(sf::Color(45, 115, 210)); //Цвет
	sf::Text txtDiamonds(std::to_wstring(data.Diamonds), font, 20); //Инициализация самого счетчика (из заголовка gamedata)
	txtDiamonds.setPosition(770.f, 20.f); //Местоположение
	txtDiamonds.setFillColor(sf::Color(245, 248, 255)); //Цвет
	btnDiamonds.setOutlineThickness(4.f); //Добавление границы кнопки и ее размер
	btnDiamonds.setOutlineColor(sf::Color(110, 175, 255)); //Цвет 

	while (window.isOpen()) //Основной цикл игры (работает до закрытия игры)
	{
		sf::Vector2i CursorPosit = sf::Mouse::getPosition(window);
		sf::Vector2f MousePosit = window.mapPixelToCoords(CursorPosit);

		sf::Event event;
		while (window.pollEvent(event)) //Цикл обработки действий
		{
			if (event.type == sf::Event::Closed) window.close(); //Закрытие игры если пользователь нажал на крестик
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

		if (data.currentMenu == MENU) //Цикл меню (когда пользователь в меню)
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

			window.clear(sf::Color(28, 32, 42)); //Отрисовка фона
			window.draw(btnMaze); //Отрисовка остального контента 
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
			window.display(); //Показ финального кадра после отрисовки всего контента

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

	return 0;
}