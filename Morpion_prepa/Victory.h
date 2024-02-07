#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Victory
{
private:
	int Line(std::vector<char> playGrid);
	int Column(std::vector<char> playGrid);
	int Diagonal(std::vector<char> playGrid);
	int Loose(std::vector<char> playGrid);

public:
	bool VictoryCheck(std::vector<char> playGrid);
};

