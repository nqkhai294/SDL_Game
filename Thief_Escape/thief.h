

#pragma once

#include "lib.h"
#include "pipe.h"

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

    void update(short int pipeWidth, short int pipeHeight);
private:
    short int angle, time, y0;
    short int ahead = 0;
    string saved_path = "";
    position posThief;
};
