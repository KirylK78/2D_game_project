#include <SFMl/Graphics.hpp>
#include <iostream>
#include "gamedata.h"
#include "saveprogress.h"
int main() {

	sf::RenderWindow window(sf::VideoMode(800, 800), L"Меню игры");  //Инициализация основного окна
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
	diamondSP.setPosition(510.f, 10.f); //Местоположение
	diamondSP.setScale(
		70.f / diamondTextur.getSize().x, //Ширина
	    40.f / diamondTextur.getSize().y //Высота
		);

	sf::RectangleShape btnPlatformer(sf::Vector2f(300.f, 60.f)); //Инициализация кнопки ПРЫЖКИ и ее размер
	btnPlatformer.setPosition(40.f, 180.f); //Местоположение
	btnPlatformer.setFillColor(sf::Color(45, 115, 210)); //Цвет
	sf::Text txtPlatformer(L"2. Прыжки", font, 28); //Инициализация текста внутри кнопки ПРЫЖКИ
	txtPlatformer.setPosition(100.f, 192.f); //Местоположение
	txtPlatformer.setFillColor(sf::Color(245, 248, 255)); //Цвет 
	btnPlatformer.setOutlineThickness(4.f); //Добавление границы кнопки и ее размер
	btnPlatformer.setOutlineColor(sf::Color(110, 175, 255)); //Цвет 

	sf::RectangleShape btnMaze(sf::Vector2f(300.f, 60.f)); //Инициализация кнопки ЛАБИРИНТ и ее размер
	btnMaze.setPosition(40.f, 90.f); //Местоположение
	btnMaze.setFillColor(sf::Color(45, 115, 210)); //Цвет
	sf::Text txtMaze(L"1. Лабиринт", font, 28); //Инициализация текста внутри кнопки ЛАБИРИНТ
	txtMaze.setPosition(100.f, 102.f); //Местоположение
	txtMaze.setFillColor(sf::Color(245, 248, 255)); //Цвет 
	btnMaze.setOutlineThickness(4.f); //Добавление границы кнопки и ее размер
	btnMaze.setOutlineColor(sf::Color(110, 175, 255)); //Цвет 

	sf::RectangleShape btnDiamonds(sf::Vector2f(120.f, 40.f)); //Инициализация счетчика алмазов и его размер
	btnDiamonds.setPosition(500.f, 10.f); //Местоположение
	btnDiamonds.setFillColor(sf::Color(45, 115, 210)); //Цвет
	sf::Text txtDiamonds(std::to_wstring(data.Diamonds), font, 20); //Инициализация самого счетчика (из заголовка gamedata)
	txtDiamonds.setPosition(570.f, 20.f); //Местоположение
	txtDiamonds.setFillColor(sf::Color(245, 248, 255)); //Цвет
	btnDiamonds.setOutlineThickness(4.f); //Добавление границы кнопки и ее размер
	btnDiamonds.setOutlineColor(sf::Color(110, 175, 255)); //Цвет 

	while (window.isOpen()) //Основной цикл игры (работает до закрытия игры)
	{
		sf::Event event;
		while (window.pollEvent(event)) //Цикл обработки действий
		{
			if (event.type == sf::Event::Closed) window.close(); //Закрытие игры если пользовательнажал на крестик
		}
		if (data.currentMenu == MENU) //Цикл меню (когда пользовательв меню)
		{

			window.clear(sf::Color(28, 32, 42)); //Отрисовка фона
			window.draw(btnMaze); //Отрисовка остального контента 
			window.draw(txtMaze);
			window.draw(btnPlatformer);
			window.draw(txtPlatformer);
			window.draw(btnDiamonds);
			window.draw(txtDiamonds);
			window.draw(diamondSP);
			window.display(); //Показ финального кадра после отрисовки всего контента

		}
		else if (data.currentMenu == MAZE) {
			//Тут крч будет лабиринт
		}
		else if (data.currentMenu == PLATFORMER) {
			//А тут будет прыгалка
		}
	}

	return 0;
}