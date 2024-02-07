#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define WIDTH 720
#define HEIGHT 720

class Draw
{
private:
	static void crossDraw(sf::RenderWindow* window, sf::Vector2f pos);
	static void circleDraw(sf::RenderWindow* window, sf::Vector2f pos);
public:
	static void draw(sf::RenderWindow* window, std::vector <sf::RectangleShape*> grid, std::vector<char> playGrid);
};

