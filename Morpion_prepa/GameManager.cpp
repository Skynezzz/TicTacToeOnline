
#include "GameManager.h"


GameManager::GameManager() {

}

GameManager::~GameManager() {

}

std::vector<char> GameManager::CreatePlayGrid() {
    std::vector<char> playGrid = { 'n', 'n', 'n',
                                   'n', 'n', 'n',
                                   'n', 'n', 'n' };
    return playGrid;
}

std::vector <sf::RectangleShape*> GameManager::CreateDisplayGrid(std::vector <sf::RectangleShape*> grid) {

    std::vector<sf::Vector2f> gridLinePos = { {WIDTH / 3 - 5, 10}, {WIDTH / 3 * 2 - 5, 10}, {10,HEIGHT / 3 - 5}, {10,HEIGHT / 3 * 2 - 5}, };
    
    for (int i = 0; i < 2; i++)
    {
        grid.push_back(new sf::RectangleShape({ 10,WIDTH - 20 }));
    }
    for (int i = 0; i < 2; i++)
    {
        grid.push_back(new sf::RectangleShape({ HEIGHT - 20,10 }));
    }

    for (int i = 0; i < grid.size(); i++)
    {
        grid[i]->setFillColor(sf::Color::Black);
        grid[i]->setPosition(gridLinePos[i]);
    }
    return grid;
}

void GameManager::GameLoop(sf::RenderWindow* window, bool victory, int flag, std::vector<char> playGrid, Victory victoryCheck, Draw draw, std::vector <sf::RectangleShape*> grid) {
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                if (!victory)
                {
                    //std::cout << "isPlaying" << std::endl;
                    int clickedCell = (int)(mousePos.x / 240) + (int)(mousePos.y / 240) * 3;
                    if (playGrid[clickedCell] != 'o' && playGrid[clickedCell] != 'x') {
                        if (flag) {
                            flag = 0;
                            playGrid[clickedCell] = 'x';
                        }
                        else {
                            flag = 1;
                            playGrid[clickedCell] = 'o';
                        }
                    }
                    victory = victoryCheck.VictoryCheck(playGrid);
                }
                /*std::cout << (int)(mousePos.x / 240) << "; " << (int)(mousePos.y / 240) << "; " << (int)(mousePos.x / 240) + (int)(mousePos.y / 240) * 3<< std::endl;*/
            }
        }



        draw.draw(window, grid, playGrid);
    }
}

int GameManager::GameLaunch()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    int flag = 0;
    bool victory = false;

    Draw draw;
    Victory victoryCheck;

    std::vector<char> playGrid = CreatePlayGrid();

    std::vector <sf::RectangleShape*> grid;
    grid=CreateDisplayGrid(grid);

    GameLoop(&window,victory, flag, playGrid, victoryCheck, draw, grid);

    return 0;
}