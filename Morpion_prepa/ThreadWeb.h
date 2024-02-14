#pragma once
#include <vector>

#include "Thread.h"
#include "WebDisplay.h"

class ThreadWeb : public Thread {
private:
    std::vector<char> grid;

public:
    ThreadWeb(std::vector<char> grid) : grid(grid) {}
    virtual void OnThread() {
        WebDisplay webDisplay;
        webDisplay.init();
        webDisplay.start(grid);
    }
};