#include "saveprogress.h"
#include <fstream>

void SaveProgress(const GameData& data) {
	std::ofstream file("playerdata.txt");
	if (file.is_open()) {
		file << data.Diamonds << " " << data.PlayerSkin;
		file.close();
	}
}
void LoadProgress(GameData& data) {
	std::ifstream file("playerdata.txt");
	if (file.is_open()) {
		file >> data.Diamonds >> data.PlayerSkin;
		file.close();
	}
}