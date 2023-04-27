

#pragma once

#include "thief.h"
#include "pile.h"
#include "land.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class game:LTexture
{
public:
    struct input
    {
        enum type { QUIT, PLAY, NONE, PAUSE};
        type Type;
    };
    input playerInput;
    thief thief_;
    pile pile_;
    land land_;
public:
    game();

    ~game();

    bool initGraphic();

    bool isQuit()
    {
        return quit;
    }

    bool isDie()
    {
        return die;
    }

    int getPileWidth()
    {
        return pile_.width();
    }

    int getPileHeight()
    {
        return pile_.height();
    }

    void takeInput();

    void display();

    void freeGraphic();

    void renderScoreSmall();

    void renderScoreLarge();

    void renderBestScore();

    void renderReady();

    void renderBackground();

    void renderLand();

    void resume();

    void pause();

    void renderPauseTab();

    void renderGameOver();

    void replay();

    bool checkReplay();

    void Restart();

    void renderGuide();

private:
    const double scaleNumberS = 0.75;
    int bestScore;
};
