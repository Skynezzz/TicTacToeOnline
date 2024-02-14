#include "GameManager.h"


GameManager::GameManager() {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Online TicTacToe");

    CreateDisplayGrid();
}

GameManager::~GameManager() {

}

void GameManager::CreatePlayGrid() {
    playGrid = { 'n', 'n', 'n',
                 'n', 'n', 'n',
                 'n', 'n', 'n' };
}

void GameManager::CreateDisplayGrid() {

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
}

void GameManager::GameLoop() {
    Victory victory;
    int flag = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (!victory.getState())
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
                    victory.VictoryCheck(playGrid);
                }
            }
        }

        Draw::draw(&window, grid, playGrid);
    }
}

int GameManager::GameLaunch()
{
    CreatePlayGrid();

    ThreadWeb webThread(&playGrid);
    webThread.Init();
    // Attend que le thread se termine
    // WaitForSingleObject(webThread.GetHandle(), INFINITE);

    Sleep(1000);

    GameLoop();

    return 0;
}