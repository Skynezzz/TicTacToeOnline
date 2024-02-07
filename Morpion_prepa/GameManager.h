#pragma once
#include "Draw.h"
#include "Victory.h"
#include <vector>

class GameManager
{
private:
	std::vector<char> CreatePlayGrid();
	std::vector <sf::RectangleShape*> CreateDisplayGrid(std::vector <sf::RectangleShape*> grid);
	void GameLoop(sf::RenderWindow* window, bool victory, int flag, std::vector<char> playGrid, Victory victoryCheck, Draw draw, std::vector <sf::RectangleShape*> grid);
public:
	GameManager();
	int GameLaunch();
	~GameManager();
};