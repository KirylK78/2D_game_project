#pragma once

enum GameMenu{
	MENU = 0,
	MAZE = 1,
	PLATFORMER = 2,
	CASINO = 3,
	MAGAZ = 4,
};
struct GameData{ //Общие данные для всех модулей
	GameMenu currentMenu = MENU; //Текущее местонахождение в игре
	int Diamonds = 0; //Текущее кол-во алмазов
	int PlayerSkin = 0; //Текущий скин игрока
};