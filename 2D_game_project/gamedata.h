#pragma once

enum GameMenu{
	MENU = 0,
	MAZE = 1,
	PLATFORMER = 2,
	CASINO = 3,
	MAGAZ = 4,
};
enum SkinID {
	SKINDEF = 0,
	SKIN1 = 1,
	SKIN2 = 2,
	SKIN3 = 3,
	SKIN4 = 4,
};
struct GameData{ //Общие данные для всех модулей
	GameMenu currentMenu = MENU; //Текущее местонахождение в игре
	int Diamonds = 0; //Текущее кол-во алмазов
	int PlayerSkin = SKINDEF; //Текущий скин игрока
};