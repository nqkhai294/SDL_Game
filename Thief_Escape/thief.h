

#pragma once

#include "lib.h"
#include "pile.h"

using namespace std;

class thief:LTexture
{
public:
    bool init();

    void render();

    void Free();

    void resetTime()
    {
        time = 0;
    }

    void fall();

    void update(int pileWidth, int pileHeight);
private:
    int angle, time, y0;
    int ahead = 0;
    string saved_path = "";
    position posThief;
};
