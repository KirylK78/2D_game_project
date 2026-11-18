#include "saveprogress.h"
#include <fstream> //Библиотека для работы с файлами

void SaveProgress(const GameData& data) { //Берет константу из gamedata
	std::ofstream file("playerdata.txt");
	if (file.is_open()) { //Проверка открыт ли файл и если открыт записывает значения через пробел
		file << data.Diamonds << " " << data.PlayerSkin;
		file.close();
	}
}
void LoadProgress(GameData& data) { //Достает значение из gamedata
	std::ifstream file("playerdata.txt");
	if (file.is_open()) { //Проверка открыт ли файл и если открыт забирает из него значения
		file >> data.Diamonds >> data.PlayerSkin;
		file.close();
	}
}