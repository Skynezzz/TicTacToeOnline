#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Victory
{
private:
	bool state = false;

	int Line(std::vector<char> playGrid);
	int Column(std::vector<char> playGrid);
	int Diagonal(std::vector<char> playGrid);
	int Loose(std::vector<char> playGrid);

public:
	void VictoryCheck(std::vector<char> playGrid);
	inline bool getState() { return state; };
};

