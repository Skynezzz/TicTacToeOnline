#include "Draw.h"

void Draw::crossDraw(sf::RenderWindow* window, sf::Vector2f pos) {
    sf::RectangleShape leftLine({ 200,10 });
    sf::RectangleShape rightLine({ 200,10 });
    leftLine.setFillColor(sf::Color::Red);
    rightLine.setFillColor(sf::Color::Red);
    leftLine.setOrigin(100, 5);
    rightLine.setOrigin(100, 5);
    leftLine.setRotation(45);
    rightLine.setRotation(-45);
    leftLine.setPosition(pos);
    rightLine.setPosition(pos);
    window->draw(leftLine);
    window->draw(rightLine);
}


void Draw::circleDraw(sf::RenderWindow* window, sf::Vector2f pos)
{
    sf::CircleShape shape(80);
    shape.setFillColor(sf::Color::White);
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOrigin(80, 80);
    shape.setPosition(pos);
    window->draw(shape);
}

void Draw::draw(sf::RenderWindow* window, std::vector <sf::RectangleShape*> grid, std::vector<char> playGrid) {
    window->clear(sf::Color::White);

    for (float i = 0; i < playGrid.size(); i++)
    {
        sf::Vector2f cellDisplay = { WIDTH / 6 + ((float)((int)i % 3) * WIDTH / 3), HEIGHT / 6 + ((float)((int)i / 3) * HEIGHT / 3) };

        if (playGrid[i] == 'x') {
            crossDraw(window, cellDisplay);
        }
        if (playGrid[i] == 'o') {
            circleDraw(window, cellDisplay);
        }
    }
    for (int i = 0; i < grid.size(); i++)
    {
        window->draw(*grid[i]);
    }
    window->display();
}