#include <SFMl/Graphics.hpp>
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Game"); //Создание окна игры
	window.setFramerateLimit(60); //Ограничил количестов кадров в секунду
	while (window.isOpen()) //Цикл работает пока созданное окно открыто
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) window.close(); // Проверка не нажал ли пользователь на крестик
		}
		window.clear(sf::Color::Green); //Заливка фона
		window.display(); //Вывод кадра
	}
	return 0;
}