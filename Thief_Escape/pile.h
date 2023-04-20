#pragma once

#include "lib.h"
#include <iostream>
#include <vector>

using namespace std;

extern vector<position> posPile;

class pile:LTexture
{
private:
    const int randMin = -373 + 30; // 373 là kích thước ảnh pile
    const int randMax = SCREEN_HEIGHT - LAND_HEIGHT - 373 - PILE_DISTANCE - 30;
public:
    bool init();

    void Free();

    void render();

    void update();

    int width() {return getWidth();}

    int height() {return getHeight();}
};
