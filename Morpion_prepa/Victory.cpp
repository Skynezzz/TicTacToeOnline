#include "Victory.h"

int Victory::Line(std::vector<char> playGrid) {

    for (int i = 0; i < 3; i++) {
        if (playGrid[i * 3] != 'n') {
            //std::cout << "ok" << std::endl;
            if (playGrid[i * 3] == playGrid[i * 3 + 1] && playGrid[i * 3] == playGrid[i * 3 + 2]) {
                std::cout << "Victory Line " << i << " by " << playGrid[i * 3] << std::endl;
                return 1;
            }
        }
    }
    return 0;
}
int Victory::Column(std::vector<char> playGrid) {

    for (int i = 0; i < 3; i++) {
        if (playGrid[i] != 'n') {
            //std::cout << "ok" << std::endl;
            if (playGrid[i] == playGrid[i + 3] && playGrid[i] == playGrid[i + 6]) {
                std::cout << "Victory Column " << i << " by " << playGrid[i] << std::endl;
                return 1;
            }
        }
    }
    return 0;
}
int Victory::Diagonal(std::vector<char> playGrid) {

    for (int i = 0; i < 3; i++) {
        if (i < 2 && playGrid[i * 2] != 'n') {
            //std::cout << "ok" << std::endl;
            if (!i && playGrid[i * 2] == playGrid[i * 2 + 4] && playGrid[i * 2] == playGrid[i * 2 + 8]) {
                std::cout << "Victory Diagonal " << i << " by " << playGrid[i] << std::endl;
                return 1;
            }
            if (i && playGrid[i * 2] == playGrid[i * 2 + 2] && playGrid[i * 2] == playGrid[i * 2 + 4]) {
                std::cout << "Victory Diagonal " << i << " by " << playGrid[i*2] << std::endl;
                return 1;
            }
        }
    }
    return 0;
}
int Victory::Loose(std::vector<char> playGrid) {
    for (int i = 0; i < 9; i++) {
        if (playGrid[i] == 'n')
            return 0;
    }
    std::cout << "Equality" << std::endl;
    return 1;
}

void Victory::VictoryCheck(std::vector<char> playGrid) {
    state = Column(playGrid) || Line(playGrid) || Diagonal(playGrid) || Loose(playGrid);
}