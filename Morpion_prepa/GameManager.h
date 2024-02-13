#pragma once
#include "Draw.h"
#include "Victory.h"
#include "WebDisplay.h"
#include <vector>

class GameManager
{
private:
	sf::RenderWindow window;
	std::vector <sf::RectangleShape*> grid;
	std::vector<char> playGrid;
	WebDisplay web;

	void CreatePlayGrid();
	void CreateDisplayGrid();
	void GameLoop();
public:
	GameManager();
	~GameManager();
	int GameLaunch();
};