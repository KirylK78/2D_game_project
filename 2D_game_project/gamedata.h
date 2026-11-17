#pragma once

enum GameMenu{
	MENU = 0,
	MAZE = 1,
	PLATFORMER = 2,
};
struct GameData{ //Общие данные для всех модулей
	GameMenu currentMenu = MENU; //Текущее местонахождение в игре
	int Diamonds = 0; 
	int PlayerSkin = 0;
};